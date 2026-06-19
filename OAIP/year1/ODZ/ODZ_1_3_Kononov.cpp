#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main(){
    string line;
    cin >> line;

    int digits = 0;
    int vowels = 0;
    int letters = 0;
    int consonants = 0;
    set<char> punctSet;

    for (char c : line) {
        if (isdigit(c)) {
            digits++;
        } 
        else if (isalpha(c)) {
            letters++;
            if (isVowel(c)) {
                vowels++;
            } else {
                consonants++;
            }
        } 
        else {
            punctSet.insert(c);
        }
    }

    if (digits > letters){cout << "Цифр больше";}
    else if (digits < letters){cout << "Цифр меньше";}
    else {cout << "Поровну";}
    cout << endl;

    cout << "Глас - " << vowels << endl;
    cout << "Соглас - " << consonants << endl;

    cout << "Пункт - ";
    for (char c : punctSet) {
        cout << c << " ";
    }
    cout << endl;

}
