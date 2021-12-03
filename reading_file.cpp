#include <stdio.h>
#include <stdlib.h>

void parse() {


    const int size = 6;
    char line[] = "3.2 4.6 5.8 6.3 6.1 9.9";
    float numbers[size] = {0};
    char * p=line;

    for (int i = 0; i < size; i++) {
        printf("Number[%d] = %f\n", i, numbers[i]);
    }
}


int main()
{
    //parse();
    //return 0;

    int n=0;//number of lines
    int m=0;//# of numbers on a line
    const int numChars = 100;//max chars readable on a line
    char num[numChars];
    FILE * fptr;
    fptr = fopen("test.txt", "r");
    if(fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fptr,"%d", &n);//n = 6 => 6 lines
    //for(int i = 0; i < n; i++)//looping n times
    {
        float sum=0;
        fscanf(fptr,"%d",&m);//scanning the first number of the line to define line lenght
        fgets(num,numChars,fptr);//reading from num, numChars=max chars readable
        float currentNum=0;
        sscanf(num,"%f", &currentNum);//reading the array num 
        for (int l=0;l<numChars;l++) {
            const char ab = num[l];
            if(num[l]=='\0'){
                break;
            }
            else if(num[l]==' '&&num[l]=='\n'){
                sum += currentNum;//finding the sum of a single line
                if(currentNum=' '){
                    currentNum=0;
                }
            }
            printf("%f ",currentNum);
            
        }
        float avg=sum/float(m);//finding average of a single line
        printf("Avg of the line is:%f\n",avg);
    }
    fclose(fptr);
    return 0;
}
