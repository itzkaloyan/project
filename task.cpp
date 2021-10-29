#include <iostream>
using namespace std;
int main(){
    int rows = 1;
    int num = 1;
    printf("Enter number of rows:\n");
    scanf("%d",&rows);
    for(int i=0;i<rows;i++){
        for(int space = 1;space <= rows-i;space++)
            printf("  ");
            for(int j = 0;j <= i;j++){
                if (j == 0 || i == 0){
                    num = 1;
                }
                else {
                    num = num*(i-j+1)/j;
                }
                printf("%3d ",num);
            }
            printf("\n");
    }
    return 0;
}
