// * * * * * * *
//   * * * * *
//     * * *
//       *

#include <iostream>
using namespace std;

void Pattern1(int n) {
    for (int i = 0; i < n; i++) {
        // space
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // stars
        for (int j = 0; j < 2*n- (2 * i + 1); j++) {
            cout << "*";
        }
        // space  
        for (int j = 0; j < i; j++) {
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
