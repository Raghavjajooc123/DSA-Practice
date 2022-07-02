#include<stdio.h>
#include<math.h>
int main(void)
{ 
 float x;
 printf("Enter the value of x: \n");
 scanf("%f", &x);
 printf("sin(%f) is: %f", x, sin(x));
 return 0;
}