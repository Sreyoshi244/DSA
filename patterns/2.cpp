// *
// **
// ***
// ****
// *****

#include <iostream>

using namespace std;

void Pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>> t;
        Pattern1(t);
    }
    
    
    
    return 0;
}