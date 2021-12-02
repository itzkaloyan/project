#include<iostream>
using namespace std;

int main(){
   int price;
   bool ac;
   int speed;
   int usb;
   cout<<"Enter price:";
   cin>>price;
   cout<<"Enter max speed:";
   cin>>speed;
   cout<<"Enter number of USBs:";
   cin>>usb;
   cout<<"Does it support 802.11ac, 1 for yes, 0 for no\n";
   cin>>ac;
   if(price>130||price<80&&price>70){
      cout<<"Won't buy a router";
      return 0;
   }
   if(price>80){
      if(ac==false||speed<200||usb<2){
         cout<<"Won't buy a router";
         return 0;
      }
      else{
         cout<<"Will buy a router with "<<speed<<" Mbps max speed, 802.11ac support and "<<usb<<" USB ports";
         return 0;
      }
   }
   else{
      if(usb<2){
         cout<<"Won't buy a router";
         return 0;
      }
      else if(ac==false){
         cout<<"Will buy a router with "<<speed<<" Mbps max speed, without 802.11ac support and "<<usb<<" USB ports";
         return 0;
      }
      else{
         cout<<"Will buy a router with "<<speed<<" Mbps max speed, 802.11ac support and "<<usb<<" USB ports";
         return 0;
      }
   }
}
