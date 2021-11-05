#include <stdio.h>
#include <iostream>
using namespace std;
void box(int n,int m,int map[256][256]);
int main()
{
    int n;
    int m;
    int map[256][256];
    do{
        cout << "Enter n:\n";
        cin >> n;
    }
    while(n<0&&n>=256);
    do{
        cout << "Enter m:\n";
        cin >> m;
    }
    while(m<0&&m>=256);
    box(n,m,map);
    return 0;
}
void box(int n, int m,int map[256][256]){
    for(int i=0;i<n;i++){
        for(int y=0;y<m;y++){
        if(i==n-1||i==0||y==0||y==m-1){
            map[n][m]='#';
        }
        else{
            map[n][m]=' ';
        }
        printf("%c", map[n][m]);
        }
        printf("\n");
    }
    
}
