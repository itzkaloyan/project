#include <iostream>
using namespace std;

void function() {

    int number;
    cout << "Enter Number\n";
    cin >> number;
    int n1 = 0;
    int n2 = 1;
    int n3;
    
    for(int i=0; i < number - 1; ++i) {
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    cout<<n3<<endl;
}

int main() {
    
    function();
    return 0;
}