#include <iostream>
using namespace std;

void box(char map[16][16], int r){
    for (int i = 0; i <= r; i++){
        for(int j = 0;j <=r; j++){
            char map[i][j]=' ';
        }
    }
}

void drawline(char map[16][16],int x1, int y1,int x2,int y2)  
{  
    int dx, dy, p, x, y; 
    dx=x2-x1;  
    dy=y2-y1;  
    x=x1;  
    y=y1;  
    p=2*dy-dx;
    float x = 1;
    float y = 0;
    int angle = 90;
    while(true){
        if(){
            return 0;
        }
        if(){
            angle += 5;
        }      
        else if(){
            angle -= 5;
        }
        if(angle > 360){
            angle -= 360;
        }
        if(angle < 0){
            angle += 360;
        }
        if(angle >= 45 && angle <= 135){
            y = -1 + 1/45.0*(angle-45);
        }
        else if(angle >= 225 && angle <= 315){
            y = 1 - 1/45.0*(angle-225);
        }
        if(angle >= 135 && angle <= 225){
            x = 1 - 1/45.0 * (angle-135);
        }
        else if(angle >= 315){
            x = -1 + 1/45.0 * (angle-315);
        }
        else if(angle <= 45){
            x = 1/45.0 * angle;
        }
        if(angle == 360){
            angle = 0;
        }
    }

int main(){
    box(map,r);
    int r;
    int x2;
    int y2;
    cout<<"enter ending point";
    cin>>x2>>y2;
    cout<<"enter radius:";
    cin>>r;
    int x1 = r;
    int y1 = r;
    char map[16][16];
    for (int i = 0; i <= r*r; i++){
        for(int j =0; j <= r*r; j++){
            map[i][j]=' ';
        }
    }
    map[x1][y1] = '#';
    drawline(map,x1,y1,x2,y2);
    box(map,r);
}

