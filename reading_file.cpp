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
    printf("Input a valid date:\n");
    scanf("%d %d %d",&d,&m,&y);
    int x = dayofweek(d, m, y);
    if(d<=31&&d>0&&m<=12&&m>0){
        switch (x){
                case 0:
                    printf ("Sunday");
                    break;
                case 1:
                    printf ("Monday");
                    break;
                case 2:
                    printf ("Tuesday");
                    break;
                case 3:
                    printf ("Wednesday");
                    break;
                case 4:
                    printf ("Thursday");
                    break;
                case 5:
                    printf ("Friday");
                    break;
                case 6:
                    printf ("Saturday");
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
