#include<stdio.h>
void print_month(int);
int calendar(int, int, int);
int main()
{
    int q, y, m, h;
    printf("Enter year = ");
    scanf("%d", &y);
    printf("Enter month (1-12) = ");
    scanf("%d", &m);
    printf("Enter day = ");
    scanf("%d", &q);
    int exact_month = m;
    int exact_year = y;
    if(m==1 || m==2)
        {
            m= m+12;
            y =y-1;
        }
     h= calendar( q,  y,  m);
     print_month(exact_month);
     printf(" %d, %d is", q,exact_year);
     if(h==0)
     {
         printf(" SATURDAY");
     }
     else if(h==1)
     {
         printf(" SUNDAY");
     }
     else if(h==2)
     {
         printf(" MONDAY");
     }

     else if(h==3)
     {
         printf(" TUESDAY");
     }
     else if(h==4)
     {
         printf(" WEDNESDAY");
     }

     else if(h==5)
     {
         printf(" THURSDAY");
     }

    else if(h==6)
     {
         printf(" FRIDAY");
     }
    return 0;
}

void print_month(int n)
{
    if(n == 1)printf("January");
    if(n == 2)printf("February");
    if(n == 3)printf("March");
    if(n == 4)printf("April");
    if(n == 5)printf("May");
    if(n == 6)printf("June");
    if(n == 7)printf("July");
    if(n == 8)printf("August");
    if(n == 9)printf("September");
    if(n == 10)printf("October");
    if(n == 11)printf("November");
    if(n == 12)printf("December");
}

int calendar(int q, int y, int m)
{
    int h;
    h = (q+abs ((26*(m+1))/10) +y + abs(y/4) +6* abs(y/100)+ abs(y/400))%7;

     return h;
}

