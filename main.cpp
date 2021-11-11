#include <iostream>
using namespace std;

void box(int n, int m, char map[256][256], int posX, int posY, FILE * fptr);
void print(char map[256][256]);

int main()
{
    system("stty cooked");
    int n = 22;
    int m = 10;
    char map[256][256];
    FILE * fptr;
    fptr = fopen("test.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    int posX;
    int posY;
    fscanf(fptr,"%d %d\n", &posX, &posY);
    if(posX>=n||posY>=m){
        cout << "Wrong info\n";
        return 0;
    }
    char ch;
    system("stty raw");
    
    box(n, m, map, posX, posY, fptr);
    
    while ((ch = getchar()) != 'e') {
        print(map);
        if ((ch == 'w' || ch == 'W') && map[posX][posY-1] != '#'){
            posY -= 1;
        }
        if ((ch == 's' || ch == 'S') && map[posX][posY+1] != '#'){
            posY += 1;
        }
        if ((ch == 'a' || ch == 'A') && map[posX-1][posY] != '#'){
            posX -= 1;
        }
        if ((ch == 'd' || ch == 'D') && map[posX+1][posY] != '#'){
            posX += 1;
        }
        system("clear");
    }
    system("stty cooked");
    return 0;
}
void box(int n, int m, char map[256][256], int posX, int posY, FILE * fptr)
{
    printf("\n\r");
    int i = 0;
    map[posX][posY+1]= '@';
    for (i; i < 200; i++)
    {
        char * c = fgets(map[i],200,fptr);
        if(c == 0){
            break;
        }
    }
}
void print(char map[256][256]){
    for(int i; i < 200; i++){
    printf("%d %s\r", i, map[i]);
    }
}

