#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE * fptr;
    fptr = fopen("test.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    int num;
    fscanf(fptr,"%d", &num);
    printf("Number of lines:%d\n", num);
    
    int sum=0;
    int Fnum=0;
    int Snum=0;
    for(int i = 0; i < num; i++)
    {
        int res = fscanf(fptr,"%d %d\n",&Fnum,& Snum);
        if (res != 2) {
            printf("Invalid input line %d\n", i);
            continue;
        }
        sum=Fnum+Snum;
        printf("Sum of numbers is: %i\n", sum); 

    }
    fclose(fptr);
    printf("File read succesfully\n");   
    return 0;
}