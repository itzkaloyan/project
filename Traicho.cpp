#include<iostream>
using namespace std;

int main(){
   int price;
   int ram;
   bool ssd;
   bool processor;
   int vram;
   cout<<"enter price:";
   cin>>price;
   cout<<"enter ram:";
   cin>>ram;
   cout<<"SSD? 1=yes 0-no:";
   cin>>ssd;
   cout<<"Intel Core i7 8th Generation? 1=yes 0-no:";
   cin>>processor;
   cout<<"enter vram:";
   cin>>vram;
   bool laptop=((price<1500&&ssd==true&&ram==8)
   &&(price>1300&&processor==true&&vram>=2)||
   (price>1000&&(processor==true||vram>=2)));
   if(laptop==1){
      cout<<"Will buy a laptop";
   }
   else{
      cout<<"Wont buy a laptop";
   }
}

