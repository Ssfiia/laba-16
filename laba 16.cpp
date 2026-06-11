#include "Header.h"    
SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
int main(){
    using namespace std;
    

    int choice;
    while (true) {
        cout << "\n Главное меню \n";
        cout << "1. TreeWork6 - Нахождение минимума\n";
        cout << "2. TreeWork10 - Вставка значения в дерево \n";
        cout << "3. TreeWork19 - Является ли дерево идеально-сбалансированным\n";
        cout << "0. �����\n";

        choice = Check::check_the_number_in_range("Ваш выбор: ", 0, 3);
        cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            TaskTreeWork6();
            break;
        case 2:
            TaskTreeWork10();
            break;
        case 3:
            TaskTreeWork19();
            break;
        case 0:
            cout << "������� �� ��������\n";
            return 0;
        default:
            cout << "�������� �����! ���������� �����.\n";
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}