#include <iostream>
using namespace std;

void box(int n, int m, int map[256][256], int posX, int posY);

int main()
{
    system("stty cooked");
    int n;
    int m;
    int map[256][256];
    do
    {
        cout << "Enter n:\n";
        cin >> n;
    } while (n < 0 && n >= 256);
    do
    {
        cout << "Enter m:\n";
        cin >> m;
    } while (m < 0 && m >= 256);
    int posX = n / 2;
    int posY = m / 2;
    char ch;
    system("stty raw");
    while ((ch = getchar()) != 'e') {
        system("stty cooked");
        system("clear");
        if ((ch == 'w' || ch == 'W') && posY != 1) posY -= 1;
        if ((ch == 's' || ch == 'S') && posY != m-2) posY += 1;
        if ((ch == 'a' || ch == 'A') && posX != 1) posX -= 1;
        if ((ch == 'd' || ch == 'D') && posX != n-2) posX += 1;
        box(n, m, map, posX, posY);
        system("stty raw"); 
        cout << endl;
    }
    system("stty cooked");
    return 0;
}

void box(int n, int m, int map[256][256], int posX, int posY)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < m; y++)
        {
            if (i == n - 1 || i == 0 || y == 0 || y == m - 1)
            {
                map[n][m] = '#';
            }
            else
            {
                if (i == posY && y == posX)
                {
                    map[n][m] = '@';
                }
                else
                {
                    map[n][m] = ' ';
                }
            }
            printf("%c", map[n][m]);
        }
        printf("\n");
    }
}