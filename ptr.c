#include <stdio.h>

int A, B, C;
float X, Y, Z;

void StopTracingNow(int X, int Y, int Z)
{
 int A, B, C;
 A = 1; B = 2; C = 3;
 X = X + C; Y = Y * B; Z = Z - A;
 printf("3rd %d %d %d \n",A,B,C);
 printf("3rd %d %d %d \n",X,Y,Z);
}

void DoThisTwice(int X, int Y, int Z)
{
 X = X + C; Y = Y * B; Z = Z - A;
 printf("1st %d %d %d \n",X,Y,Z);
}


int main(void)
{
          X = 3.5; Y = 5.5; Z = 7.5;
          A = 5; B = 10; C = 15;
          DoThisTwice(A,B,C);
          printf("2nd %.1f %.1f %.1f \n",X,Y,Z);
          StopTracingNow(A,B,C);
          printf("5th %d %d %d \n",A,B,C);
          getchar();
          return 0;
          
}


