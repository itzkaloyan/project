#include <iostream>
using namespace std;

void draw(char map[256][256]);

int main() {
    system("stty cooked");
    FILE * fptr;
    fptr = fopen("./test.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    int h = 0;
    int w = 0;
    char map[256][256];
    int posX;
    int posY;
    fscanf(fptr,"%d %d\n", &posX, &posY);
    for (int i = 0; i < 200; i++)
    {
        char * c = fgets(map[i],200,fptr);
        if(c == 0) {
            break;
        }
    }
    for (short i = 0; i < 256; i++)
    {
        if (map[i][0] == '#') h++;
    }
    for (short i = 0; i < 256; i++)
    {
        if (map[0][i] == '#') w++;
    }
    printf("Size: h: %d w: %d \n", h, w);
    if(posX>=w || posY>=h) {
        cout << "Wrong info\n";
        return EXIT_FAILURE;
    }
    char ch;
    while ((ch = getchar()) != '\e')
    {
        system("stty raw");
        system("clear");
        map[posY][posX] = ' ';
        switch (ch) {
            case 'W': case 'w':
            if (map[posY-1][posX] != '#') posY--;
            break;
            case 'S': case 's':
            if (map[posY+1][posX] != '#') posY++;
            break;
            case 'A': case 'a':
            if (map[posY][posX-1] != '#') posX--;
            break;
            case 'D': case 'd':
            if (map[posY][posX+1] != '#') posX++;
            break;
        }
        map[posY][posX] = '@';
        draw(map);
    }
    system("stty cooked");
    return 0;
}
void draw(char map[256][256]) {
    for (size_t i = 0; i < 200; i++)
       printf("%s \r", map[i]);
}