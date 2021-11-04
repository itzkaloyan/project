#include <iostream>
using namespace std;
void firstline(int rows);
void lastline(int rows);
void midlines(int rows);
int main(){
    int rows;
    cout << "Enter length:\n";
    cin >> rows;
    firstline(rows);
    midlines(rows);
    lastline(rows);
    return 0;
}
void firstline(int rows){
    for(int i=0;i<rows-1;i++){
        cout << " ";
    }
    for(int i=0;i<rows;i++){
        cout << "* ";
    }
    cout << endl;
}
void midlines(int rows){
    for(int i=1; i<rows-1; i++){
        for(int j=0;j<i+1;j++){
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }
}
void lastline(int rows){
    for(int i=0;i<rows+rows-1;i++){
        cout << "* ";
    }
}
