#include <iostream>
using namespace std;
int main(){
    int rows = 1;
    printf("Enter number of rows:\n");
    scanf("%d",&rows);
    for(int i=0;i<=rows;i++){
            for(int space = rows-1;space >= i;space--){
                printf(" ");
            }
            for(int j=1; j<=i; j++){
            printf("*");
            }
            printf(" ");
            for(int j=1;j<=i;j++){
                printf("*");
            }

            printf("\n");
    }
    return 0;
}
