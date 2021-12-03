#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=0;
    int m=0;
    float num[100];
    FILE * fptr;
    fptr = fopen("test.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fptr,"%d", &n);
    for(int i = 0; i < n; i++)
    {
        int sum=0;
        fscanf(fptr,"%d",&m);
        for (int l=0;l<m;l++) {
            fgets(num[],m,fptr);
            sum +=num;
        }
        float avg=sum/float(m);
        printf("Avg of the line is:%f %d %d\n",avg, sum, m);
    }
    fclose(fptr);  
    return 0;
}