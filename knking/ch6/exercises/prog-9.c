#include <stdio.h>
int main(void)
{
  float loanAmt,interest,monthlyPmt,monthlyInt,balance;
  int numberOpmts;

  printf("Enter loan amount:");
  scanf("%f",&loanAmt);
  printf("Enter interest rate:");
  scanf("%f",&interest);
  printf("Enter monthly payment:");
  scanf("%f",&monthlyPmt);
  printf("Enter number of payments:");
  scanf("%d",&numberOpmts);

 monthlyInt=(interest/100)/12;

 for(int i=0;i<numberOpmts;++i)
 {
   balance=(loanAmt-monthlyPmt)+monthlyInt*loanAmt;
  
   if(i==(numberOpmts-1))
   {
    printf("Balance remaining after %d payments is :%.2f\n",numberOpmts,balance);
    break;
   }
   loanAmt=balance;
 }

 
 return 0;
}
