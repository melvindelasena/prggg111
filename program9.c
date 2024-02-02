#include <stdio.h>

int main(void) {
    int total = 0;
    int counter = 0;
    int highest = 0; // Initialize highest to a low value
    int lowest = 100; // Initialize lowest to a high value
    int pass = 0;
    int fail = 0;
    int grade;

    do {
        printf("Enter grade (-1 to end): ");
        scanf("%d", &grade);

        if (grade != -1) { // Check if the grade is not -1 before processing
            total = total + grade;
            counter = counter + 1;

            if (grade >= 75) {
                pass = pass + 1;
            } else {
                fail = fail + 1;
            }

            if (grade > highest) {
                highest = grade;
            }

            if (grade < lowest) {
                lowest = grade;
            }
        }
    } while (grade != -1);

    if (counter > 0) {
        int average = total / counter;
        printf("Class average is %d\n", average);
        printf("Number that have passed: %d\n", pass);
        printf("Number that have failed: %d\n", fail);
        printf("The lowest grade is: %d\n", lowest);
        printf("The highest grade is: %d\n", highest);
    } else {
        printf("No grades were entered.\n");
    }

    return 0;
}
