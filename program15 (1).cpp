
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5
#define DATAFILE "itc"

typedef struct {
    char sname[12];
    double grade;
    int units;
    char letter[3];
    double QPE;
} subject;

void Bubble(subject a[], int l, int r)
{
    int i, j, compare;
    subject temp;
    for (i = l; i < r; i++)
        for (j = r; j > i; j--) {
            compare = (strcmp(a[j].sname, a[j - 1].sname));
            if (compare < 0) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
}

double QPI(subject a[], int n) {
    double totalQPE = 0.0;
    int totalUnits = 0; 
    int i = 1;
    while ( i <= n)  {
        totalQPE += a[i].QPE * a[i].units;
        totalUnits += a[i].units;
        i++;
    }
    return totalQPE / totalUnits;
}

void Letter(subject a[], int n) {
    int i = 0;
    while (i++ < n) {
        if (a[i].grade >=92.0 && a[i].grade <= 100) {
      
        
            strcpy(a[i].letter, "A");
        a[i]. QPE = 4.0;}

        else if (a[i].grade >= 88.0 && a[i].grade <= 91.0){
        
            strcpy(a[i].letter, "B+");
        a[i].QPE = 3.5; }

        else if (a[i].grade >= 84.0 && a[i].grade <= 87.0){
        
            strcpy(a[i].letter, "B");
        a[i].QPE = 3.0;}

        else if (a[i].grade >= 80.0 && a[i].grade <= 83.0){
        
            strcpy(a[i].letter, "C+");
        a[i].QPE = 2.5;}

        else if (a[i].grade >= 76.0 && a[i].grade <= 79.0){
        
            strcpy(a[i].letter, "C");
        a[i].QPE = 2.0; }

        else if (a[i].grade >= 72.0 && a[i].grade <= 75.0) {
        
            strcpy(a[i].letter, "D");
        a[i].QPE = 1.0; }

        else if (a[i].grade < 72.0){
        
            strcpy(a[i].letter, "F");
        a[i].QPE = 0; }
 }
}
/*--------------------------------------------*/
char Menu(char choice) {
    do {
        getchar();
        printf("\n<< CS 1131 Example >>\n\n");
        printf("[A] Add Subject\n");
        printf("[V] View Subjects\n");
        printf("[Q] Quit Program\n\n");
        printf("enter letter of choice : ");
        choice = toupper(getchar());
    } while (choice != 'A' && choice != 'V' &&
        choice != 'Q');
    return choice;
}
/*----------------------------------------------*/
int ReadFile(subject a[], int b) {
    int counter = 0;
    FILE* sfile;
    if ((sfile = fopen(DATAFILE, "rb")) == NULL) {
        printf("Creating new file...");
        getchar(); // hold screen until key pressed
    }
    else {
        fread(a, b, 1, sfile);
        counter = a[0].units;
    }
    fclose(sfile);
    return(counter);
} // ReadFile
/*------------------------------------------------------*/
void WriteFile(subject a[], int n, int b) {
    FILE* sfile;
    a[0].units = n;
    sfile = fopen(DATAFILE, "wb");
    fwrite(a, b, 1, sfile);
    fclose(sfile);
} //WriteFile
/*----------------------------------------------------*/
void Add(subject a[], int n) {
    char c;
    float f;
    printf("\nsubject : ");
    scanf("%s", a[n].sname);
    printf("\ngrade : ");
    scanf("%lf", &a[n].grade);
    printf("\nunits : ");
    scanf("%d", &a[n].units);

} // Add

/*---------------------------------------------------*/
void View(subject a[], int n) {
    char c;
    float k;
    int i;
    Letter(a, n);

    printf("\nthere are %d record(s)\n\n", n);
    printf("\n\tsubject\t");
    printf("\t  grade\t");
    printf("  units\t");
    printf("  letter grade\n");
    if (n != 0) {
        for (i = 1; i < n + 1; i++) {
            printf("[%d]\t%-13s", i, a[i].sname);
            printf("\t%7.2lf", a[i].grade);
            printf("\t%5d   ", a[i].units);
            printf("\t%-5s\n", a[i].letter);

        } 
    } 
    else {
        printf("array is empty\n");
    } 

}



int main(void) {
    int count = 0, quit = 0; char choice = '\0';
    subject mysubjects[MAX + 1];
    int buffersize = sizeof mysubjects;
    count = ReadFile(mysubjects, buffersize);
    while (!quit) {
        choice = Menu(choice);
        switch (choice) {
        case 'A':
            if (count < MAX) {
                Add(mysubjects, count + 1);
                count++;
            }
            else printf("\narray is full");
            break;
            
        case 'V':
   			 View(mysubjects, count);
    		double studentQPI = QPI(mysubjects, count);
    		printf("\nStudent QPI: %.2lf\n", studentQPI);
    		break;
    
        case 'Q': quit = 1;
        } 
    } 
    WriteFile(mysubjects, count, buffersize);
} 

