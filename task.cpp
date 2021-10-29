#include <bits/stdc++.h>
using namespace std;

int dayofweek(int d,int m,int  y){
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int x=( y + y / 4 - y / 100 +y / 400 + t[m - 1] + d) % 7;
    return x;
}
int main(){
    int d;
    int m;
    int y;
    int MonthDays;
    printf("Input a valid date:\n");
    scanf("%d %d %d",&d,&m,&y);
    enum Months{
        InvalidMonths,
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
        MaxMonths,
    };
    enum Weekdays{
        InvalidDays=-1,
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        MaxDays,
    };
    switch(m){
        case January:case March:case May:case July:case August:case October:case December:
        MonthDays=31;
        break;
        case April:case June:case September:case November:
        MonthDays=30;
        break;
        case February:
        if(y%4==0&&y%100!=0||y%400==0){
            MonthDays=29;
        }
        else{
            MonthDays=28;
        }
    }
    int x = dayofweek(d, m, y);
    if(d<=MonthDays&&d>InvalidDays&&m<MaxMonths&&m>InvalidMonths){
        switch (x){
                case Monday:
                    printf ("Monday");
                    break;
                case Tuesday:
                    printf ("Tuesday");
                    break;
                case Wednesday:
                    printf ("Wednesday");
                    break;
                case Thursday:
                    printf ("Thursday");
                    break;
                case Friday:
                    printf ("Friday");
                    break;
                case Saturday:
                    printf ("Saturday");
                    break;
                case Sunday:
                    printf ("Sunday");
                    break;
                default:
                    printf ("Error");
        }
    }
    else {
            printf ("Invalid date");
            }
    return 0;
}
