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

    char polipuba[7][7] = { {'�', '�', '�', '�', '�', '�', '�'},
                         {'�', '�', '�', '�', '�', '�', '�'},
                         {'�', '�', '�', '�', '�', '�', '�'},
                         {'�', '�', '�', '�', '�', '�', '�'},
                         {'�', '�', '�', '�', '�', '0', '1'},
                         { '2','3', '4', '5', '6', '7', '8'},
                         {'9', ' ', ',', '.', '!', '?', ';'}
    };
    cout << "������� ����� ��� �������� : " << endl;
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

    cout << "\n��������������:" << endl;
    for (int i = 0; i < Alfav.size(); i++)
    {
        cout << polipuba[Alfav[i].First][Alfav[i].Second];
    }
}
