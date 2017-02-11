#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
 int quarters = 25;
 int dimes = 10;
 int nickels = 5;
 int pennies = 1;
 int count = 0;
 float change;
 int c;
 do
  {
   printf("How Much Change Is Owed?");
   change= GetFloat();
  }
 while(change<0);
 printf("%f Change Is Owed?\n",change);
 change = change * 100;
 int balance = round(change);
 while(balance>=quarters)
  {
   c=balance/quarters;
   count= count + c;
   balance = balance - (c*quarters);
  }
 while(balance>=dimes)
  {
   c=balance/dimes;
   count= count + c;
   balance = balance - (c*dimes);
  }
 while(balance>=nickels)
  {
   c=balance/nickels;
   count= count + c;
   balance = balance - (c*nickels);
  }
 while(balance>=pennies)
  {
   c=balance/pennies;
   count= count + c;
   balance = balance - (c*pennies);
  }
  printf("Your Change is %i coins.\n",count);
  printf("And Remaining Balance is %i.\n",balance);
}
