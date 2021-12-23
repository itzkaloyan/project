#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

void setMap(char map[128][128], int x, int y, char c) {
    map[y][x]=c;
}

void drawline(char map[128][128],int x1, int y1,int x2,int y2,int size, int radius)  {  
    assert(map != nullptr);
    float dx = x2 - x1;
    float dy = y2 - y1;
    float err = 0;
    int x = x1;
    int y = y1;
    float limit;
    if(x2==size-1){
        float tang = float(dy)/dx;
        while(x != x2+1){
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            err += tang;
            cout << "(" << x << "," << y << "," << "," << limit << ")\n";
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
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
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            err += tang;
            cout << "(" << x << "," << y << "," << "," << limit << ")\n";
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
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
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            err += tang;
            cout << "(" << x << "," << y << "," << "," << limit << ")\n";
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
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
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            err += tang;
            cout << "(" << x << "," << y << "," << "," << limit << ")\n";
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
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

void box(char map[128][128], int size, int x1, int y1,int x2,int y2, int radius){
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            //map[i][j]= '.';
            setMap(map,i, j, '.');
        }
    }
    drawline(map,x1,y1,x2,y2,size,radius);
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    int radius = 10;
    int size = radius*2+1;
    int x1 = radius;
    int y1 = radius;
    char map[128][128];
    int x2;  
    int y2;
    do{
        cin>>x2;
        cin>>y2;
        box(map, size, x1, y1, x2, y2, radius);
    }while(true);
}

