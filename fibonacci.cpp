#include <iostream>
using namespace std;
int main() {
    int num;
    FILE *fptr;
    fopen("test.txt","w");
    if(fptr == NULL)
   {
      printf("Error");   
      exit(1);             
   }
   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);

    return 0;
}