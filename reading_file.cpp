#include <iostream>
using namespace std;

void print(char map[16][16], int &r){
    for (int i = 0; i <= r*r; i++){
        for(int j =0; j <= r*r; j++)
        {
        printf("%c", map[i][j]);
    }
    printf("\n");
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
    if(dx>=0&&dy>=0){
        cout<<"Kvadrant 1";
        while(x<x2)
        {  
            map[x][y]='#';
            if(p>=0)  
            {  
                y+=1;  
                p=p+2*dy-2*dx; 
                x+=1;
            }  
            else  
            {  
                p=p+2*dy; 
                x+=1;  
            }
        }
    }
    if(dx<0&&dy>=0){
        cout<<"Kvadrant 2";
        while(x2<x)
        {
            map[x][y]='#';
            if(p>=0)  
            {  
                y+=1;  
                p=p+2*dy+2*dx; 
                x-=1;
            }  
            else  
            {  
                p=p+2*dy; 
                x-=1;  
            }
        }
    }
    if(dx<0&&dy<0){
        cout<<"Kvadrant 3";
        while(x2<x)
        {
            map[x][y]='#';
            if(p>=0)  
            {  
                y-=1;  
                p=p+2*dy+2*dx; 
                x-=1;
            }  
            else  
            {  
                p=p+2*dy; 
                x-=1;  
            }
        }
    }
    if(dx>=0&&dy<0){
        cout<<"Kvadrant 4";
        while(x<x2)
        {
            map[x][y]='#';
            if(p>=0)  
            {  
                y-=1;  
                p=p+2*dy-2*dx; 
                x+=1;
            }  
            else  
            {  
                p=p+2*dy; 
                x+=1;  
            }
        }
    }
}

int main(){
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
    print(map,r);

}

