#include <stdio.h>
#include <stdlib.h>

char* GetLine(char * line) {
    int n;
    while (line[n] != '\0'){
        n++;
    }
    for(int i=0;i<n;i++){
        scanf("%c",line);
        return line;
    }
}
int main()
{
    FILE * fptr;
    fptr = fopen("reverse.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    char line[256];
    GetLine(line);
    printf("%s\n",line);
    return 0;
}
