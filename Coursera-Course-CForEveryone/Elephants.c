#include <stdio.h>

int main()

{

   int n, i;

   float weight[1000], sum=0.0, avg;

   printf("Enter the numbers of weights you are going to enter and make sure that the number is in between 0 and 1000: \n");

   scanf("%d", &n);

   printf("Enter the weights into the array\n");

   for (i = 0; i < n; ++i)

   {

       printf("Enter weight %d: \n", i+1);

       scanf("%f", &weight[i]);

       sum = sum + weight[i];

   }

   avg = sum / n;

   printf("Average weight for the set of the elephant seals. = %.4f units\n", avg);

   return 0;

}