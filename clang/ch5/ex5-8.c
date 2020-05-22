#include <stdio.h>
#include <stdbool.h>
#include isLeap(x) ((x) = (x) % 4 == 0 && (x) % 100 != 0 || (x) % 400 == 0)
#include valid_year(x) ((x) > 0)
#include valid_month(month) (1 <= (month) && (month) <= 12)
#include valid_day(d) (1 <= (d) && (d) <= 366)

static char daytab[2][13] = {
   {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

//set day of year from month and day
int day_of_year(int year, int month, int day)
{
   bool hasError = false;
   if (hasError = !valid_year(year))
      printf("error (day_of_year): year must be a positive number\n");
   if (hasError = hasError || !valid_month(month))
      printf("error (day_of_year): month must be between 1 and 12");

   if (hasError) return -1;

   int i, leap;
   leap = isLeap(year);
   for (i = 1; i < month; i++) day += daytab[leap][i];
   return day;
}

// set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
   bool hasError = false;
   if (hasError = !valid_year(year))
      printf("error (month_day): year must be a positive number\n");
   if (hasError = hasError || !valid_month(month))
      printf("error (month_day): month must be between 1 and 12");
   if (hasError = hasError || !valid_day(yearday))
      printf("error (month_day): day must be positive and less than 366");
   if (hasError) {
      *pday = -1;
      pmonth = -1;
      return;
   }
   int i, leap;
   leap = isLeap(year);
   for (i = 1; yearday > daytab[leap][i]; i++) yearday -= daytab[leap][i];

   *pmonth = i;
   *pday = yearday;
}
