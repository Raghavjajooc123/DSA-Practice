#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
 int radius;
 printf("Enter radius:\n");
 scanf("%d", &radius);
 printf("volume is : %f \n\n", PI*4*radius*radius*radius/3 );
 return 0;
}