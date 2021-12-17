#include <iostream>
#include <math.h>
using namespace std;

void drawline(char map[128][128],int x1, int y1,int x2,int y2,int size)  {  
    float dx = x2 - x1;
    float dy = y2 - y1;
    float err = 0;
    int x = x1;
    int y = y1;
    if(x2==size-1){
        float tang = float(dy/dx);
        while(x != x2+1){
            err += tang;
            cout << "(" << x << "," << y << "," << err << ")\n";
            map[y][x]='#';
            x++;
            if(y>=y2){
                if(err <= 0.5){
                    y--;
                    err += 1;
                }
            }
            if(y<y2){
                if(err >= 0.5){
                    y++;
                    err -= 1;
                }
            }
        }
    }
    if(x2==0){
        float tang = float(dy/dx);
        while(x != x2-1){
            err += tang;
            cout << "(" << x << "," << y << "," << err << ")\n";
            map[y][x]='#';
            x--;
            if(y>y2){
                if(err >= 0.5){
                    y--;
                    err -= 1;
                }
            }
            if(y<y2){
                if(err <= 0.5){
                    y++;
                    err += 1;
                }
            }
        }
    }
    if(y2==0&&x2!=0){
        float tang = float(dx/dy);
        while(y != y2-1){
            err += tang;
            cout << "(" << x << "," << y << "," << err << ")\n";
            map[y][x]='#';
            y--;
            if(x>x2){
                if(err >= 0.5){
                    x--;
                    err += 1;
                }
            }
            if(x<x2){
                if(err <= 0.5){
                    x++;
                    err -= 1;
                }
            }
        }
    }
    if(y2==size-1){
        float tang = float(dx/dy);
        while(y != y2+1){
            err += tang;
            cout << "(" << x << "," << y << "," << err << ")\n";
            map[y][x]='#';
            y++;
            if(x>x2){
                if(err <= 0.5){
                    x--;
                    err += 1;
                }
            }
            if(x<x2){
                if(err >= 0.5){
                    x++;
                    err -= 1;
                }
            }
        }
    }
}

void box(char map[128][128], int size, int x1, int y1,int x2,int y2){
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            map[i][j]= '.';
        }
    }
    drawline(map,x1,y1,x2,y2,size);
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
    int x1 = radius;
    int y1 = radius;
    char map[128][128];
    int x2;  
    int y2;
    do{
    cin>>x2;
    cin>>y2;
    box(map, size, x1, y1, x2, y2);
    }while(true);
}

