#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <climits>

// Узел дерева
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val);
    Node(const Node& other);
    ~Node();
};

// Класс Дерево
class Tree {
public:
    Tree();
    Tree(const Tree& other);
    ~Tree();

    Tree& operator=(const Tree& other); // Оператор присваивания

    // Добавление значения в дерево поиска
    void add_to_tree(int data);

    // Ввод для дерева
    void input_random(int count, int min_val, int max_val);
    void input_console();
    void input_from_file(const std::string& filename);

    // Ввод для дерева поиска
    void input_search_from_random(int n, int min_val, int max_val);
    void input_search_from_console();
    void input_search_from_file(const std::string& filename);

    // Инфиксный обход (ЛКП)
    void inorder_print();
    std::vector<int> get_inorder_vector();

    // Вывод листьев справа налево
    void print_leaves_right_to_left();

    // Поиск максимального значения
    int find_max();

    // Вставка значения X
    void insert_value(int x);

    // Проверка на идеально-сбалансированное дерево
    bool is_perfectly_balanced();

    // Визуализация дерева
    void print_tree_side();

    // Геттеры
    Node* get_root();
    int count_nodes();

private:
    Node* root;

    void add_to_tree_recursive(Node*& node, int data);
    void inorder_recursive(Node* node, std::vector<int>& result);
    void print_leaves_right_to_left_recursive(Node* node);
    void print_tree_side_recursive(Node* node, int level);
    void delete_tree_recursive(Node* node);
    int count_nodes_recursive(Node* node);

    // Вспомогательные методы для копирования
    Node* copy_tree_recursive(Node* node);

    // Вспомогательные методы
    int find_max_recursive(Node* node);
    void insert_value_recursive(Node*& node, int x);
    bool is_perfectly_balanced_recursive(Node* node, int& nodeCount);
    int get_node_count(Node* node);
    bool is_search_tree_recursive(Node* node, int min_val, int max_val);
};

// Класс проверок
class Check {
public:
    Check() = default;
    Check(const Check& other) = default;
    ~Check() = default;

    static bool is_leaf(Node* node);
    static int check_the_number_in_range(const std::string& prompt, int min_value, int max_value);
    static int check_the_number_simple(const std::string& prompt);
    static void check_tree_empty(Node* root);
};

void TaskTreeWork6();
void TaskTreeWork10();
void TaskTreeWork19();