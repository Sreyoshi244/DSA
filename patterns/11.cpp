#include <iostream>
using namespace std;

void Pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        int start = (i % 2 == 0) ? 1 : 0;
        
        for(int j = 1; j <= i; j++) {
            cout << start;
            start = 1 - start; // alternate
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        Pattern1(t);
        
        if (i < n - 1) cout << endl; // blank line after each pattern except last
    }
    
    return 0;
}
