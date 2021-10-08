#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 1000
int main()
{
    char data[DATA_SIZE];
    FILE * fptr;
    fptr = fopen("test.txt", "r");

    if(fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter contents to store in file:\n");
    fgets(data, DATA_SIZE, fptr);
    
    fclose(fptr);
    printf("File created and saved successfully\n");
    
    FILE * fptr2;
    fptr2 = fopen("test2.txt", "w");
    
    if(fptr2 == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fputs(data, fptr2);
    fclose(fptr2);
    return 0;
}