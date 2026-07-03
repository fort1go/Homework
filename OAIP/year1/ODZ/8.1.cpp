#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    cout << fact << endl;

    fact = 1;
    int i = 1;
    while (i <= n) {
        fact *= i;
        i++;
    }
    cout << fact << endl;

    fact = 1;
    i = 1;
    if (n > 0) {
        do {
            fact *= i;
            i++;
        } while (i <= n);
    }
    cout << fact << endl;

    return 0;
}
