#include <iostream>
using namespace std;


int main() { 
    unsigned int x;
    cin >> x;
    
    if (x == 0) return 0;
    
    int count = 0;
    while (x > 0) {
        count++;
        x >>= 1;
    }

    cout << count << endl;
    
    return 0;
}
