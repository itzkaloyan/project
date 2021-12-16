#include <iostream>
#include <math.h>
using namespace std;

void drawline(char map[128][128],int x1, int y1,int x2,int y2)  {  
    int lastX = x2;
    int lastY = y2;
    float err;
    int x = x1;
    int y = y1;
    float tang = float((y2-y1)/(x2-x1));
    if(x1<=x2){
        while(x != x2){
            err += tang;
            cout << "(" << x << "," << y << ")\n";
            map[y][x]='#';
            x++;
            if (err > 0){
                y++;
            }
        }
    }
    if(x1>=x2){
        while(x != x2){
            map[y][x]='#';
            x--;
        }
    }
    if(y1<=y2){
        while(y != y2){
            map[y][x]='#';
            y++;
        }
    }
    if(y1>=y2){
        while(y != y2){
            map[y][x]='#';
            y--;
        }
    }
}

void box(char map[128][128], int size, int x1, int y1,int x2,int y2){
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            map[i][j]= '.';
        }
    }
    drawline(map,x1,y1,x2,y2);
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    int radius = 3;
    int size = radius*2+1;
    int x2;
    cin>>x2;
    int y2;
    cin>>y2;
    int x1 = radius;
    int y1 = radius;
    char map[128][128];
    box(map, size, x1, y1, x2, y2);
    
}

