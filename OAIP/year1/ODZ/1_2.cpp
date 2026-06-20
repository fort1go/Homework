#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    string name;
    string alphabet = "ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
    set<char> A = {};
    int B = 0;
    for (int i=0;i<alphabet.length();i++) {A.insert(alphabet[i]);}
    getline(cin, name);
    for (int i=0;i<name.length();i++){
        if (name[i] == ' ') {B++;}
        else if (A.find(name[i]) == A.end()){
            cout << "Неверное имя, используется не русский язык\n";
            return 0;
        }
    }
    if (B != 2) {
        cout << "Неверное имя, должно быть 3 слова\n" << B;
        return 0;
    }
    
    cout << "Верное имя - " << name << "\n";
    return 0;
}
