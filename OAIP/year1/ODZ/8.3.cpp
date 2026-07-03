#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    // Вычисляем количество строк (недель)
    int K = (N + M - 1) / 7 + 1;
    
    // Создаем массив (максимум 6 недель)
    int month[6][7];
    
    // Заполняем всё нулями
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 7; j++) {
            month[i][j] = 0;
        }
    }
    
    // Заполняем дни месяца
    int day = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 7; j++) {
            // Пропускаем ячейки до первого дня месяца
            if (i == 0 && j < M - 1) continue;
            
            // Записываем день, если не превысили N
            if (day <= N) {
                month[i][j] = day;
                day++;
            }
        }
    }
    
    // Выводим календарь
    cout << "\nПн Вт Ср Чт Пт Сб Вс" << endl;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 7; j++) {
            if (month[i][j] == 0)
                cout << " . ";
            else{
                if (month[i][j] < 10){cout << ' ';}
                cout << month[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
