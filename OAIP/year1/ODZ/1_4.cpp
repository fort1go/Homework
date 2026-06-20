#include <iostream>


using namespace std;

struct Time{
    int hours;
    int minutes;
    int seconds;
};

int main(){
    Time today = Time{9, 32, 51};
    cout << today.hours << ":" << today.minutes << ":" << today.seconds << endl;
    return 0;
}
