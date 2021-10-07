#include <iostream>
using namespace std;
int main(){
int n1, n2, n3, elements,i;
cout<<"Number of elements";
cin>>elements;
for(i=0;i<elements;i++)
{
n3=n1+n2;
cout<<n3;
n1=n2;
n2=n3;
}
return 0;
}