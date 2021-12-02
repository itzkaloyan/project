#include<iostream>
using namespace std;

int main(){
   bool ssd;
   int price;
   int ram;
   int usb;
   cout<<"Enter number of USBs:";
   cin>>usb;
   cout<<"Enter Price:";
   cin>>price;
   cout<<"Enter gb of RAM:";
   cin>>ram;
   cout<<"Is there a SSD, 1 for yes, 0 for no:\n";
   cin>>ssd;
   if(price>1500){
      cout<<"Wont buy a laptop";
      return 0;
   }
   if(price<1000&&price>800){
      cout<<"Wont buy a laptop";
      return 0;
   }
   if(price>1000){
      if(usb<3||ram<8||ssd==false){
         cout<<"Wont buy a laptop";
         return 0;
      }
      else{
         cout<<"Will buy a laptop with "<<ram<<" RAM, with SSD and "<<usb<<" USB ports";
         return 0;
      }
   }
   if(price<800){
      if(usb<3){
         cout<<"Wont buy a laptop";
         return 0;
      }
      else if(ssd==true){
         cout<<"Will buy a laptop with "<<ram<<" RAM, with SSD and "<<usb<<" USB ports";
         return 0;
      }
      else{
         cout<<"Will buy a laptop with "<<ram<<" RAM, without SSD and "<<usb<<" USB ports";
         return 0;
      }
   }
}
