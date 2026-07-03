#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int digit1 = X / 100; 
    int digit2 = (X / 10) % 10;
    int digit3 = X % 10;

    char letter1 = digit1 + '0';
    char letter2 = digit2 + '0';
    char letter3 = digit3 + '0';

    cout << letter1 << " " << letter2 << " " << letter3 << endl;

    return 0;
}
