#include <string>  
#include <Windows.h> 
#include <vector>
#include <iostream>

using namespace std;

struct Cimbol
{
    int First;
    int Second;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string keyword;
    string new_keyword = "";

    char polipuba[7][7] = { {'а', 'б', 'в', 'г', 'д', 'е', 'ё'},
                         {'ж', 'з', 'и', 'й', 'к', 'л', 'м'},
                         {'н', 'о', 'п', 'р', 'с', 'т', 'у'},
                         {'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ'},
                         {'ы', 'ь', 'э', 'ю', 'я', '0', '1'},
                         { '2','3', '4', '5', '6', '7', '8'},
                         {'9', ' ', ',', '.', '!', '?', ';'}
    };
    cout << "Введите текст для шифровки : " << endl;
    getline(cin, keyword);

    vector <Cimbol> Alfav;
    for (int i = 0; i < keyword.length(); i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                if (polipuba[j][k] == keyword[i]) {
                    Cimbol C;
                    C.First = j; C.Second = k;
                    Alfav.push_back(C);
                    cout << j + 1 << k + 1 << ' ';
                    break;
                }
            }
        }
    }

    cout << "\nРасшифровываем:" << endl;
    for (int i = 0; i < Alfav.size(); i++)
    {
        cout << polipuba[Alfav[i].First][Alfav[i].Second];
    }
}
