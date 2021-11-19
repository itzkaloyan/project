#include<bits/stdc++.h>
#include<iostream>
using namespace std;
  
void line(int x1, int y1, int x2, int y2)
{
   int m_new = 2 * (y2 - y1);
   int nextY = m_new - (x2 - x1);
   for (int x = x1, y = y1; x <= x2-1; x++)
   {
      cout << "(" << x << "," << y << ")\n";

      nextY += m_new;

      if (nextY >= 0)
      {
         y++;
         nextY -= 2 * (x2 - x1);
      }
   }
   cout << "(" << x2 << "," << y2 << ")\n";
}
  
int main()
{
    int x1;
    int y1;
    int x2;
    int y2;
    cout<<"Enter starting point of the line:"<<endl;
    cin>>x1>>y1;
    cout<<"Enter ending point of the line:"<<endl;
    cin>>x2>>y2;
    line(x1, y1, x2, y2);
    return 0;
}