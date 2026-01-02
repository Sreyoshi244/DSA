// 12345
// 1234
// 123
// 12
// 1

#include <iostream>

using namespace std;

void Pattern1(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            cout<< j << " ";
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