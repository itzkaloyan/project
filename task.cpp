#include <iostream>
using namespace std;
int main(){
    int rows = 0;
    int space =0;
    int line = 0;
    printf("Enter number of rows:\n");
    scanf("%d",&rows);
    for(int i=0;i<rows;i++){
        for (line = i; line <= rows; line++){
            printf(" ");
        }
        printf("/");
        for (space=0;space<i+i;space++){
            printf(" ");
        }
        if(line > space){
            printf("_");
        }
        printf("\\");
        printf("\n");
        
    }  
    return 0;
}
