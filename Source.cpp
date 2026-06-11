#include "Header.h"

void TaskTreeWork6() {
    using namespace std;

    Tree tree;

    cout << "Выберите способ ввода:\n";
    cout << "1. Случайные числа\n";
    cout << "2. Ввод с консоли\n";
    cout << "3. Ввод из файла\n";
    int choice = Check::check_the_number_in_range("Ваш выбор: ", 1, 3);

    switch (choice) {
    case 1: {
        int n = Check::check_the_number_in_range("Введите количество узлов: ", 1, 100);
        int min_val = Check::check_the_number_in_range("Введите минимальное значение: ", -1000, 1000);
        int max_val = Check::check_the_number_in_range("Введите максимальное значение: ", min_val, 1000);
        tree.input_search_from_random(n, min_val, max_val);
        break;
    }
    case 2:
        tree.input_search_from_console();
        break;
    case 3: {
        string filename;
        cout << "Первое число файла. кол-во узлов\n";
        cout << "Введите название файла: ";
        cin >> filename;
        cin.ignore(10000, '\n');
        tree.input_search_from_file(filename);
        break;
    }
    }

    if (!tree.get_root()) {
        cout << "Ошибка: дерево пустое\n";
        return;
    }
    cout << "ДЕРЕВО ПОИСКА: \n";
    tree.print_tree_side();

    cout << "\nИнфиксный обход (ЛКП): ";
    tree.inorder_print();
    cout << endl;

    cout << "\nУказатель на корень дерева: " << tree.get_root() << endl;
    cout << "Значение в корне: " << tree.get_root()->key << endl;

    int max_val = tree.find_max();

    cout << "\n РЕЗУЛЬТАТ: \n";
    cout << "Максимальное значение в дереве: " << max_val << endl;

    cout << "\nДЕРЕВО ПОИСКА после нахождения максимума (без изменений)\n";
    tree.print_tree_side();
}

void TaskTreeWork10() {
    using namespace std;

    Tree tree;

    cout << "Выберите способ ввода:\n";
    cout << "1. Случайные числа\n";
    cout << "2. Ввод с консоли\n";
    cout << "3. Ввод из файла\n";
    int choice = Check::check_the_number_in_range("Ваш выбор: ", 1, 3);

    switch (choice) {
    case 1: {
        int n = Check::check_the_number_in_range("Введите количество узлов: ", 1, 100);
        int min_val = Check::check_the_number_in_range("Введите минимальное значение: ", -1000, 1000);
        int max_val = Check::check_the_number_in_range("Введите максимальное значение: ", min_val, 1000);
        tree.input_search_from_random(n, min_val, max_val);
        break;
    }
    case 2:
        tree.input_search_from_console();
        break;
    case 3: {
        string filename;
        cout << "Первое число файла. кол-во узлов\n";
        cout << "Введите название файла: ";
        cin >> filename;
        cin.ignore(10000, '\n');
        tree.input_search_from_file(filename);
        break;
    }
    }

    if (!tree.get_root()) {
        cout << "Ошибка: дерево пустое\n";
        return;
    }

    cout << "ДЕРЕВО ПОИСКА до вставки:\n";
    tree.print_tree_side();

    cout << "\nИнфиксный обход (ЛКП): ";
    tree.inorder_print();
    cout << endl;

    cout << "\nУказатель на корень дерева: " << tree.get_root() << endl;
    cout << "Значение в корне: " << tree.get_root()->key << endl;

    int x = Check::check_the_number_simple("Введите значение X для вставки: ");
    tree.insert_value(x);

    cout << "\n РЕЗУЛЬТАТ: \n";
    cout << "ДЕРЕВО ПОИСКА после вставки\n";
    tree.print_tree_side();

    cout << "\nИнфиксный обход (ЛКП) (после вставки): ";
    tree.inorder_print();
    cout << endl;

    cout << "\nУказатель на корень дерева: " << tree.get_root() << endl;
    cout << "Значение в корне: " << tree.get_root()->key << endl;
}

void TaskTreeWork19() {
    using namespace std;
    Tree tree;
    cout << "Выберите способ ввода:\n";
    cout << "1. Случайный ввод\n";
    cout << "2. Ввод с консоли\n";
    cout << "3. Ввод из файла\n";
    int choice = Check::check_the_number_in_range("Ваш выбор: ", 1, 3);

    switch (choice) {
    case 1: {
        int count = Check::check_the_number_in_range("Введите количество узлов: ", 1, 100);
        int min_val = Check::check_the_number_in_range("Введите минимальное значение: ", -1000, 1000);
        int max_val = Check::check_the_number_in_range("Введите максимальное значение: ", min_val, 1000);
        tree.input_random(count, min_val, max_val);
        break;
    }
    case 2:
        tree.input_console();
        break;
    case 3: {
        string filename;
        cout << "Первое число файла. кол-во узлов\n";
        cout << "Введите название файла: ";
        cin >> filename;
        cin.ignore(10000, '\n');
        tree.input_from_file(filename);
        break;
    }
    }

    if (!tree.get_root()) {
        cout << "Ошибка: дерево пустое\n";
        return;
    }

    cout << "БИНАРНОЕ ДЕРЕВО:\n";
    tree.print_tree_side();

    bool result = tree.is_perfectly_balanced();

    cout << "\n РЕЗУЛЬТАТ: \n";
    if (result) {
        cout << "True - дерево является идеально-сбалансированным" << endl;
    }
    else {
        cout << "False - дерево НЕ является идеально-сбалансированным" << endl;
    }

    cout << "\nБИНАРНОЕ ДЕРЕВО после проверки (без изменений)\n";
    tree.print_tree_side();
}