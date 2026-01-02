// 1
// 22
// 333
// 4444
// 55555

#include <iostream>

using namespace std;

void Pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
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