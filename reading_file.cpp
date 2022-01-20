#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <unistd.h>

using namespace std;

void setMap(char map[128][128], int x, int y, char c) {
    map[y][x]=c;
}
void spin(int* x, int* y, int size) {
    int x1 = *x;
    int y1 = *y;
    //cout<<x1<<":"<<y1<<endl;
    if (x1 >= 0 && x1 < size && y1 == 0) {
        x1++;
    }
    else if (x1 >= size && y1 >= 0 && y1 < size) {
        y1++;
    }
    else if (x1 > 0 && x1 <= size && y1 == size) {
        x1--;
    }
    else if (x1 == 0 && y1 > 0 && y1 <= size) {
        y1--;
    }
    cout<<x1<<":"<<y1<<endl;
    *x = x1;
    *y = y1;
}
void drawline(char map[128][128],int x1, int y1,int x2,int y2,int size, int radius)  {  
    assert(map != nullptr);
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float err = 0;
    int x = x1;
    int y = y1;
    float limit;
    if(x2==size-1){
        assert(dx != 0);
        float tang = float(dy)/dx;
        while(x != x2+1){
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            err += tang; 
            int step = (y>=y2) ? -1 : 1;
            if(err >= 0.5){
                err -=1;
                y += step;
            }
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
            x++;
            
        }
    }
    else if(x2==0){
        assert(dx != 0);
        float tang = float(dy/dx);
        while(x != x2-1){
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            int step = (y>=y2) ? -1 : 1;
            if(err >= 0.5) {
                err -=1;
                y += step;
            }
            err += tang;
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
            x--;

        }
    }
    else if(y2==0&&x2!=0){
        assert(dy != 0);
        float tang = float(dx/dy);
        while(y != y2-1){
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);  
            int step = (x>=x2) ? -1 : 1;
            if(err >= 0.5){
                err -=1;
                x += step;
            }
            err += tang;
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
            y--;
        }
    }
    else if(y2==size-1){
        assert(dy != 0);
        float tang = float(dx/dy);
        while(y != y2+1){
            limit = sqrt(((y1-y)*(y1-y))+((x1-x)*(x1-x)));
            assert(x >= 0 && y >= 0 && x <= size + 1 && y <= size + 1);
            int step = (x>=x2) ? -1 : 1;
            if(err >= 0.5){
                err -= 1;
                x += step;
            }
            err += tang;
            if (limit < radius) {
                setMap(map,x, y, '#');
            }
            y++;
        }
    }
}

void initMap(char map[128][128], int size) {
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            setMap(map,i, j, '.');
        }
    }
}
void box(char map[128][128], int size, int x1, int y1,int x2,int y2, int radius){
    //Initilize the grid with . everywhere
    initMap(map, size);

    // Draw the Radar line on the grid
    drawline(map,x1,y1,x2,y2,size,radius);

    // Draw the final result on the screen
    for (int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    int radius = 6;
    int size = (radius*2)+1;
    int x1 = radius;
    int y1 = radius;
    char map[128][128];
    int x2 = radius;  
    int y2 = 0;
    char key;
    
    if (0) {
        x2=0; y2=4;
        box(map, size, x1, y1, x2, y2, 100);
    } else {
        do{
            
            spin(&x2, &y2, size -1);
            box(map, size, x1, y1, x2, y2, 100);
            // system("stty raw");
            // cin>>key;
            // system("stty cooked");
            // if (key=='e') {
            //     return 0;
            // }
            // if (key=='d') {
                
            // }
            // if(key=='a') {

            // }
            usleep(1000*1000);
            system("clear");
            
        }while(true);
    }
}


