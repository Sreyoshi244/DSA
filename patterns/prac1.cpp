//     1     
//    A B    
//   2 3 4   
//  C D E F  
// 5 6 7 8 9 

#include <iostream>
using namespace std;

void Pattern1(int n) {
    int T=1;
    int L=0;
    for (int i = 0; i < n; i++) {
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        if (i%2 ==0)
        {
            // stars
            
            for (int j = 0; j < i + 1; j++) {
               cout << T++ << " ";
        }
        }
        else
        {
            // stars
            for (int j = 0; j < i + 1; j++) {
               cout << char(65 + L++) << " ";
        }
        }
        
        // space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        cout << endl;
    } // <-- Correct closing of for-loop + function body
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Pattern1(n);

    return 0;
}
