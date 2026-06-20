#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct Data{
    int day;
    string month;
    int year;
};


int main() {
    map<string, string> monthMap = {
        {"янв", "01"}, {"фев", "02"}, {"мар", "03"},
        {"апр", "04"}, {"май", "05"}, {"июн", "06"},
        {"июл", "07"}, {"авг", "08"}, {"сен", "09"},
        {"окт", "10"}, {"ноя", "11"}, {"дек", "12"}
    };

    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    Data DATA;
    iss >> DATA.day >> DATA.month >> DATA.year;

    string shortMonth = DATA.month.substr(0, 6);
    string mm = monthMap[shortMonth];
    string dd = (DATA.day < 10) ? "0" + to_string(DATA.day) : to_string(DATA.day);

    cout << DATA.year << ":" << mm << ":" << dd << endl;
    return 0;
}
