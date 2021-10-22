#include <stdio.h>
#include <stdlib.h>

int Getstringlength(char* str) {
    int n;
    while (str[n] != '\0')
    {
        n++;
    }
    return n;
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
   
    char lett[256];
    fscanf(fptr,"%s",lett); 
    int i=Getstringlength(lett);
    for(int j=0;j<(i/2);j++){
        char c=lett[j];
        lett[j]=lett[i-j-1];
        lett[i-j-1]=c;
    }
    printf("Output = %s\n", lett);
    fclose(fptr);
    return 0;
}
