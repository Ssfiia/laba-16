#include "Header.h"

//класс проверок
bool Check::is_leaf(Node* node) {
    return node && !node->left && !node->right;
}

int Check::check_the_number_in_range(const std::string& prompt, int min_value, int max_value) {
    using namespace std;
    int value;
    bool valid_input = false;
    string input;

    do {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "Ошибка: ввод не может быть пустым" << endl;
            continue;
        }

        bool is_valid = true;
        for (char c : input) {
            if (!isdigit(c) && c != '-') {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            cout << "Ошибка: введите целое число" << endl;
            continue;
        }

        value = stoi(input);

        if (value < min_value || value > max_value) {
            cout << "Ошибка: число должно быть от " << min_value << " до " << max_value << endl;
        }
        else {
            valid_input = true;
        }

    } while (!valid_input);

    return value;
}

int Check::check_the_number_simple(const std::string& prompt) {
    using namespace std;
    int value;
    bool valid_input = false;
    string input;

    do {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            cout << "Ошибка: ввод не может быть пустым" << endl;
            continue;
        }

        bool is_valid = true;
        for (char c : input) {
            if (!isdigit(c) && c != '-') {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            cout << "Ошибка: введите целое число" << endl;
            continue;
        }

        value = stoi(input);
        valid_input = true;

    } while (!valid_input);

    return value;
}

void Check::check_tree_empty(Node* root) {
    using namespace std;
    if (!root) {
        cout << "Ошибка: дерево пустое" << endl;
    }
}

//класс узла
Node::Node(int val) : key(val), left(nullptr), right(nullptr) {}

Node::Node(const Node& other) : key(other.key), left(nullptr), right(nullptr) {
    if (other.left) {
        left = new Node(*other.left);
    }
    if (other.right) {
        right = new Node(*other.right);
    }
}

Node::~Node() {
}

// класс дерева
Tree::Tree() : root(nullptr) {}

Tree::Tree(const Tree& other) : root(nullptr) {
    if (other.root) {
        root = copy_tree_recursive(other.root);
    }
}

Tree& Tree::operator=(const Tree& other) {
    if (this != &other) {
        delete_tree_recursive(root);
        root = nullptr;

        if (other.root) {
            root = copy_tree_recursive(other.root);
        }
    }
    return *this;
}

Tree::~Tree() {
    delete_tree_recursive(root);
}

Node* Tree::copy_tree_recursive(Node* node) {
    if (!node) return nullptr;

    Node* new_node = new Node(node->key);
    new_node->left = copy_tree_recursive(node->left);
    new_node->right = copy_tree_recursive(node->right);

    return new_node;
}

void Tree::delete_tree_recursive(Node* node) {
    if (!node) return;
    delete_tree_recursive(node->left);
    delete_tree_recursive(node->right);
    delete node;
}

Node* Tree::get_root() {
    return root;
}

void Tree::add_to_tree(int data) {
    add_to_tree_recursive(root, data);
}

void Tree::add_to_tree_recursive(Node*& node, int data) {
    if (!node) {
        node = new Node(data);
        return;
    }

    if (data < node->key) {
        add_to_tree_recursive(node->left, data);
    }
    else if (data > node->key) {
        add_to_tree_recursive(node->right, data);
    }
}

void Tree::input_random(int count, int min_val, int max_val) {
    using namespace std;
    if (count <= 0) return;

    srand(time(0));
    root = new Node(min_val + rand() % (max_val - min_val + 1));

    vector<Node*> nodes;
    nodes.push_back(root);

    for (int i = 1; i < count; i++) {
        int val = min_val + rand() % (max_val - min_val + 1);
        Node* new_node = new Node(val);

        int random_index = rand() % nodes.size();
        Node* parent = nodes[random_index];

        int side = rand() % 2;
        bool inserted = false;

        if (side == 0 && !parent->left) {
            parent->left = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        else if (side == 1 && !parent->right) {
            parent->right = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        if (!inserted) {
            for (int j = 0; j < nodes.size() && !inserted; j++) {
                if (!nodes[j]->left) {
                    nodes[j]->left = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
                else if (!nodes[j]->right) {
                    nodes[j]->right = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
            }
        }
    }

    cout << "Случайное дерево создано (" << count << " узлов, диапазон ["
        << min_val << ", " << max_val << "])\n";
}

void Tree::input_console() {
    using namespace std;
    int n = Check::check_the_number_in_range("Введите количество узлов: ", 1, 100);

    cout << "Введите " << n << " чисел:\n";

    string prompt = "  Число 1: ";
    int val = Check::check_the_number_simple(prompt);
    root = new Node(val);

    vector<Node*> nodes;
    nodes.push_back(root);

    for (int i = 2; i <= n; i++) {
        string prompt2 = "  Число " + to_string(i) + ": ";
        int val2 = Check::check_the_number_simple(prompt2);
        Node* new_node = new Node(val2);

        int random_index = rand() % nodes.size();
        Node* parent = nodes[random_index];

        int side = rand() % 2;
        bool inserted = false;

        if (side == 0 && !parent->left) {
            parent->left = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        else if (side == 1 && !parent->right) {
            parent->right = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        if (!inserted) {
            for (int j = 0; j < nodes.size() && !inserted; j++) {
                if (!nodes[j]->left) {
                    nodes[j]->left = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
                else if (!nodes[j]->right) {
                    nodes[j]->right = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
            }
        }
    }

    cout << "Дерево создано (" << n << " узлов)\n";
}

void Tree::input_from_file(const std::string& filename) {
    using namespace std;

    // Инициализируем генератор случайных чисел
    srand((unsigned int)time(nullptr));

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    int n;
    file >> n;

    if (n <= 0) {
        cout << "Ошибка: некорректное количество узлов" << endl;
        file.close();
        return;
    }

    int val;
    file >> val;
    root = new Node(val);

    vector<Node*> nodes;
    nodes.push_back(root);

    for (int i = 2; i <= n; i++) {
        if (!(file >> val)) {
            cout << "Ошибка: недостаточно данных в файле (ожидалось " << n << " чисел)" << endl;
            file.close();
            return;
        }

        Node* new_node = new Node(val);

        int random_index = rand() % nodes.size();
        Node* parent = nodes[random_index];

        int side = rand() % 2;
        bool inserted = false;

        if (side == 0 && !parent->left) {
            parent->left = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        else if (side == 1 && !parent->right) {
            parent->right = new_node;
            nodes.push_back(new_node);
            inserted = true;
        }
        if (!inserted) {
            for (int j = 0; j < nodes.size() && !inserted; j++) {
                if (!nodes[j]->left) {
                    nodes[j]->left = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
                else if (!nodes[j]->right) {
                    nodes[j]->right = new_node;
                    nodes.push_back(new_node);
                    inserted = true;
                }
            }
        }
    }

    file.close();
    cout << "Дерево загружено из файла " << filename << " (" << n << " узлов)\n";
}

void Tree::input_search_from_random(int n, int min_val, int max_val) {
    using namespace std;
    if (n <= 0) return;

    srand((unsigned int)time(nullptr));

    cout << "Случайные числа (диапазон [" << min_val << ", " << max_val << "]): ";
    for (int i = 0; i < n; i++) {
        int val = min_val + rand() % (max_val - min_val + 1);
        cout << val << " ";
        add_to_tree(val);
    }
    cout << endl;
}

void Tree::input_search_from_console() {
    using namespace std;
    int n = Check::check_the_number_in_range("Введите количество узлов: ", 1, 100);

    cout << "Введите " << n << " чисел:\n";

    for (int i = 0; i < n; i++) {
        string prompt = "  Число " + to_string(i + 1) + ": ";
        int val = Check::check_the_number_simple(prompt);
        add_to_tree(val);
    }
}

void Tree::input_search_from_file(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    int n;
    file >> n;

    for (int i = 0; i < n; i++) {
        int val;
        if (!(file >> val)) {
            cout << "Ошибка: некорректные данные в файле" << endl;
            file.close();
            return;
        }
        add_to_tree(val);
    }

    file.close();
    cout << "Дерево поиска загружено из файла " << filename << endl;
}

void Tree::inorder_print() {
    using namespace std;
    vector<int> result = get_inorder_vector();
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

std::vector<int> Tree::get_inorder_vector() {
    std::vector<int> result;
    inorder_recursive(root, result);
    return result;
}

void Tree::inorder_recursive(Node* node, std::vector<int>& result) {
    if (!node) return;
    inorder_recursive(node->left, result);
    result.push_back(node->key);
    inorder_recursive(node->right, result);
}

void Tree::print_leaves_right_to_left() {
    print_leaves_right_to_left_recursive(root);
}

void Tree::print_leaves_right_to_left_recursive(Node* node) {
    if (!node) return;

    print_leaves_right_to_left_recursive(node->right);

    if (!node->left && !node->right) {
        std::cout << node->key << " ";
    }

    print_leaves_right_to_left_recursive(node->left);
}

void Tree::print_tree_side() {
    print_tree_side_recursive(root, 0);
}

void Tree::print_tree_side_recursive(Node* node, int level) {
    using namespace std;
    if (!node) return;

    print_tree_side_recursive(node->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
    cout << node->key << endl;

    print_tree_side_recursive(node->left, level + 1);
}

int Tree::count_nodes() {
    return count_nodes_recursive(root);
}

int Tree::count_nodes_recursive(Node* node) {
    if (!node) return 0;
    return 1 + count_nodes_recursive(node->left) + count_nodes_recursive(node->right);
}

int Tree::find_max() {
    if (!root) {
        return INT_MIN;
    }
    return find_max_recursive(root);
}

int Tree::find_max_recursive(Node* node) {
    if (!node->right) {
        return node->key;
    }
    return find_max_recursive(node->right);
}

void Tree::insert_value(int x) {
    insert_value_recursive(root, x);
}

void Tree::insert_value_recursive(Node*& node, int x) {
    if (!node) {
        node = new Node(x);
        return;
    }

    if (x < node->key) {
        insert_value_recursive(node->left, x);
    }
    else if (x > node->key) {
        insert_value_recursive(node->right, x);
    }
}

// Проверка на идеально-сбалансированное дерево
bool Tree::is_perfectly_balanced() {
    int nodeCount = 0;
    return is_perfectly_balanced_recursive(root, nodeCount);
}

bool Tree::is_perfectly_balanced_recursive(Node* node, int& nodeCount) {
    if (!node) {
        nodeCount = 0;
        return true;
    }

    int leftCount = 0, rightCount = 0;

    bool leftBalanced = is_perfectly_balanced_recursive(node->left, leftCount);
    bool rightBalanced = is_perfectly_balanced_recursive(node->right, rightCount);

    nodeCount = leftCount + rightCount + 1;

    bool condition = (abs(leftCount - rightCount) <= 1);
    return leftBalanced && rightBalanced && condition;
}

