#include <stdio.h>

int main(void)
{
   float income, tax;
   printf("Please enter your taxable income: ");
   scanf("%f", &income);

   if (income < 750.0f) 
      tax = 0.01f * income;
   else if (income < 2250.0f)
      tax = 7.50f + (-(750.00f-income)*0.02f);
   else if (income < 3750.0f)
      tax = 37.50f + (-(2250.00f-income)*0.03f) ;
   else if (income < 5250.0f)
      tax = 82.50f + (-(3750.00f-income)*0.04f);
   else if (income < 7000.0f)
      tax = 142.50f + (-(5250.00f-income)*0.05f);
   else 
      tax = 230.0f +(-(7000.00f-income)*0.06f) ;

   printf("You owe $%0.2f in tax\n", tax);

   return 0;
}
