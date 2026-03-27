#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;

struct Call {
    string op, num, time;
    double cost;
};

int toSec(string t) {
    int p = t.find(':');
    return stoi(t.substr(0, p)) * 60 + stoi(t.substr(p + 1));
}

int main() {
    ifstream f("input.txt");
    Call c[100];
    int n = 0;
    
    while (f >> c[n].op >> c[n].num >> c[n].time >> c[n].cost)
        n++;
    
    map<string, set<string>> clients;
    map<string, double> profit;
    map<string, int> tt;
    
    for (int i = 0; i < n; i++) {
        clients[c[i].op].insert(c[i].num);
        int sec = toSec(c[i].time);
        profit[c[i].op] += sec / 60.0 * c[i].cost;
        tt[c[i].num] += sec;
    }
    
    string op1, op2, num3;
    int maxC = 0, maxT = 0;
    double maxP = 0;
    
    for (auto& p : clients)
        if (p.second.size() > maxC) {
            maxC = p.second.size();
            op1 = p.first;
        }
    
    for (auto& p : profit)
        if (p.second > maxP) {
            maxP = p.second;
            op2 = p.first;
        }
    
    for (auto& p : tt)
        if (p.second > maxT) {
            maxT = p.second;
            num3 = p.first;
        }
    
    cout << "1) " << op1 << endl;
    cout << "2) " << op2 << endl;
    cout << "3) " << num3 << endl;
}
