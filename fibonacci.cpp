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
    printf("Number of elements:%d\n", num);
    int* arr = new int[num];
    int sum=0;
    for(int i=0;i<num;i++)
    {
        fscanf(fptr,"%d",&arr[num]);
            sum +=arr[num];
    }
    
    int i=0;

    printf("Sum of numbers is: %i\n", sum);
    fclose(fptr);
    printf("File read succesfully\n");
    delete [] arr;   
    return 0;
}