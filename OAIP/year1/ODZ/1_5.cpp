#include <iostream>
#include <string>

using namespace std;

struct Data{
    int day;
    int month;
};

struct Student{
    string second_name;
    int number;
    int mark;
};

struct Exam{
    string subject;
    string group;
    Data data;
    Student a[25];
};


int main() {
    return 0;
}
