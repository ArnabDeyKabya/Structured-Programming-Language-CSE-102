#include<stdio.h>
int calendar(int, int, int);
void print_month(int);
int leap_year(int);
int last_few_days_function(int, int);
int main()
{
    int q, y, m, h;
    printf("Enter year = ");
    scanf("%d", &y);
    printf("Enter month(1-12) = ");
    scanf("%d", &m);
    q=1;
    int exact_year=y;
    int exact_month=m;
    if(m==1 ||m==2)
    {
        m=m+12;
        y=y-1;
    }
    h=calendar(q, y, m);
    printf("\nCalendar for :\n\n");
    print_month(exact_month);
    printf(",%d\n\n", exact_year);

    printf("SUN  MON  TUE  WED  THU  FRI  SAT\n");
    if(h==0)
    {
        int space;
        for(space=1; space<=30; space++)printf(" ");
        printf("1\n");
        int day;
        for(day=2; day<=8; day++)printf("%d    ", day);
        printf("\n");
        for(day=9; day<=15; day++)
            if(day>9)printf("%d   ", day);
            else printf("%d    ", day);
        printf("\n");
        for(day=16; day<=22; day++)printf("%d   ", day);
        printf("\n");
        int last_few_days=last_few_days_functions(exact_month, exact_year);
        for(day=23; day<=last_few_days; day++)
        {
            printf("%d   ", day);
            if(day==29)printf("\n");

        }
    }
    else if(h==1)
    {
        int day;
        for(day = 1; day <= 7; day++)printf("%d    ",day);
        printf("\n");

        for(day = 8; day <= 14; day++)
        {
            if(day > 9)printf("%d   ",day);
            else printf("%d    ",day);
        }
        printf("\n");

        for(day = 15; day <= 21; day++)
        {
            printf("%d   ",day);
        }
        printf("\n");

        for(day = 22; day <= 28; day++)printf("%d   ",day);
        printf("\n");

        int last_few_days = last_few_days_functions(exact_month,exact_year);

        if(last_few_days >= 29)
        {
            for(day = 29; day <= last_few_days; day++)printf("%d   ",day);
            printf("\n");
        }
    }
    else if(h==2)
    {
        int space;
        for(space=1; space<=5; space++)printf(" ");
        int day;
        for(day=1; day<=6; day++)printf("%d    ",day);
        printf("\n");
        for(day=7; day<=13; day++)
            if(day>9)printf("%d   ", day);
            else printf("%d    ", day);
        printf("\n");
        for(day=14; day<=20; day++)printf("%d   ",day);
        printf("\n");
        for(day=21; day<=27; day++)printf("%d   ",day);
        printf("\n");
        int last_few_days= last_few_days_functions(exact_month, exact_year);
        for(day=28; day<=last_few_days; day++)printf("%d   ",day);
        printf("\n");


    }
    else if(h==3)
    {
        int space;
        for(space=1; space<=10; space++)printf(" ");
        int day;
        for(day=1; day<=5; day++)printf("%d    ", day);
        printf("\n");
        for(day=6; day<=12; day++)
            if(day>9)printf("%d   ",day);
            else printf("%d    ",day);
        printf("\n");
        for(day=13; day<=19; day++)printf("%d   ",day);
        printf("\n");
        for(day=20; day<=26; day++)printf("%d   ",day);
        printf("\n");
        int last_few_days=last_few_days_functions(exact_month, exact_year);
        for(day=27; day<=last_few_days; day++)printf("%d   ",day);

    }
    else if(h==4)
    {
        int space;
        for(space=1; space<=15; space++)printf(" ");
        int day;
        for(day=1; day<=4; day++)printf("%d    ",day);
        printf("\n");
        for(day=5; day<=11; day++)
            if(day>9)printf("%d   ",day);
            else printf("%d    ",day);
        printf("\n");
        for(day=12; day<=18; day++)printf("%d   ",day);
        printf("\n");
        for(day=19; day<=25; day++)printf("%d   ",day);
        printf("\n");
        int last_few_days=last_few_days_functions(exact_month, exact_year);
        for(day=26; day<=last_few_days; day++)printf("%d   ",day);


    }
    else if(h==5)
    {
        int space;
        for(space=1; space<=20; space++)printf(" ");
        int day;
        for(day=1; day<=3; day++)printf("%d    ",day);
        printf("\n");
        for(day=4; day<=10; day++)
        {
            if(day>9)printf("%d   ",day);
            else printf("%d    ",day);
        }
        printf("\n");
        for(day=11; day<=17; day++)printf("%d   ",day);
        printf("\n");
        for(day=18; day<=24; day++)printf("%d   ",day);
        printf("\n");
        int last_few_days=last_few_days_functions(exact_month, exact_year);
        for(day=25; day<=last_few_days; day++)printf("%d   ",day);


    }
    else if(h==6)
    {
        int space;
        for(space=1; space<=25; space++)printf(" ");
        int day;
        for(day=1; day<=2; day++)printf("%d    ",day);
        printf("\n");
        for(day=3; day<=9; day++)printf("%d    ",day);
        printf("\n");
        for(day=10; day<=16; day++)printf("%d   ",day);
        printf("\n");
        for(day=17; day<=23; day++)printf("%d   ",day);
        printf("\n");
        int last_few_days=last_few_days_functions(exact_month, exact_year);
        for(day=24; day<=last_few_days; day++)
        {
            printf("%d   ",day);
            if(day==30)printf("\n");
        }


    }



}
int calendar(int q, int y, int m)
{
    int h;
    h = (q+abs ((26*(m+1))/10) +y + abs(y/4) +6* abs(y/100)+ abs(y/400))%7;
    return h;
}
void print_month(int n)
{
    if(n == 1)printf("JANUARY");
    if(n == 2)printf("FEBRUARY");
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
int last_few_days_functions(exact_month, exact_year)
{
    int last_few_days=30;
    if(exact_month==2)
    {
        if (leap_year(exact_year))last_few_days=29;
        else last_few_days=28;
    }
    else if(exact_month==1 || exact_month==3 ||exact_month==5 ||exact_month==7 ||exact_month==8 ||exact_month==10 ||exact_month==12)
        last_few_days=31;
    return last_few_days;
}
int leap_year(int exact_year)
{
    if(exact_year%4==0 && exact_year%100!=0 || exact_year%400==0)return 1;
    else return 0;
}

