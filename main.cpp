#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <string>

using namespace  std;
int main() {
    vector<string> listGame;
    vector<string>::const_iterator iter;
    string guess;
    int choice = 0;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Привет, сейчас " << dt << endl;

    while(guess != "exit"){
        cout << "Перед Вами программа для хранения списка любимых игр.\n";
        cout << "Выберете действие: \n";
        cout << "Введите 1 для отображения существующего списка\n";
        cout << "Введите 2 для добавления нового элемента\n";
        cout << "Введите 3 для удаления элементаё\n";
        cout << "Введите 0  для выхода\n\n";
        cin >> choice;
        switch (choice) {
            case 1:
                for(iter = listGame.begin(); iter != listGame.end(); iter++) {
                    cout << *iter << endl;
                }
                break;
            case 2:
                cin >> guess;
                listGame.push_back(guess);
                break;
            case 3:
                cin >> guess;
                iter = find(listGame.begin(), listGame.end(), guess);
                if(iter != listGame.end()){
                    listGame.erase(iter);
                }
                else{
                    cout << "Увы, такокого элемента нет.\n";
                }
                break;
            default: cout << "Еще увидимся!\n";
                exit(1);
        }

    }

    return 0;
}
