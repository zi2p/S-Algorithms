#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream in("bstsimple.in");
ofstream out("bstsimple.out");
 
class Tree {
private:
    struct TREE {
        int value;
        TREE* parent;
        TREE* left;
        TREE* right;
    };
    TREE head;
    int size = 0;
public:
    void insert(int x) {
        if (size == 0) {
            head.value = x;
            head.parent = nullptr;
            head.left = nullptr;
            head.right = nullptr;
        }
        else {
            bool go_to_left = false;
            TREE* knot = &head;
            TREE* new_tree = new TREE;
            new_tree->value = x;
            new_tree->left = nullptr;
            new_tree->right = nullptr;
            while (knot != nullptr) {
                new_tree->parent = knot;
                if (knot->value > x) {
                    knot = knot->left;
                    go_to_left = true;
                }
                else if (knot->value < x) {
                    knot = knot->right;
                    go_to_left = false;
                }
                else return;
            }
            if (go_to_left) new_tree->parent->left = new_tree;
            else new_tree->parent->right = new_tree;
        }
        size++;
    }
 
    bool exist(int x) {
        if (size == 0) return false;
        TREE* knot = &head;
        while (knot != nullptr) {
            if (knot->value > x) knot = knot->left;
            else if (knot->value < x) knot = knot->right;
            else return true;
        }
        return false;
    }
 
    int next(int x) {
        if (size == 0) return NULL;
        TREE* knot = &head;
        while(1) {
            if (knot->value < x and knot->right != nullptr) knot = knot->right;
            else if (knot->value > x and knot->left != nullptr) knot = knot->left;
            else break;
        }
        if (knot->value > x) return knot->value;
        if (knot->right !=  nullptr) {
            TREE* next;
            next = knot->right;
            while (next->left != nullptr) next = next->left;
            return next->value;
        }
        while (knot != nullptr and knot->value <= x) {
            if (knot->parent == nullptr) return NULL;
            knot = knot->parent;
        }
        return knot->value;
    }
 
    int prev(int x) {
        if (size == 0) return NULL;
        TREE* knot = &head;
        while(1) {
            if (knot->value < x and knot->right != nullptr) knot = knot->right;
            else if (knot->value > x and knot->left != nullptr) knot = knot->left;
            else break;
        }
        if (knot->value < x) return knot->value;
        if (knot->left != nullptr) {
            TREE* prev;
            prev = knot->left;
            while (prev->right != nullptr) prev = prev->right;
            return prev->value;
        }
        while (knot != nullptr and knot->value >= x) {
            if (knot->parent == nullptr) return NULL;
            knot = knot->parent;
        }
        return knot->value;
    }
 
    void del(int x) {
        if (size == 0) return;
        TREE* knot = &head;
        bool _bool = true;
        while (knot != nullptr) {
            if (knot->value < x) {
                knot = knot->right;
                _bool = false;
            }
            else if (knot->value > x) {
                knot = knot->left;
                _bool = true;
            }
            else break;
        }
        if (knot == nullptr) return;
        else size--;
        if (knot->left == nullptr and knot->right == nullptr) {
            if (knot->parent == nullptr) return;
            else if (_bool) knot->parent->left = nullptr;
            else knot->parent->right = nullptr;
        }
        else if (knot->left == nullptr) {
            if (knot->parent == nullptr) {
                knot->right->parent = nullptr;
                head = *(knot->right);
            }
            else {
                if (_bool) knot->parent->left = knot->right;
                else knot->parent->right = knot->right;
                knot->right->parent = knot->parent;
            }
        }
        else if (knot->right == nullptr) {
            if (knot->parent == nullptr) {                             // удаление узла с левым ребенком
                knot->left->parent = nullptr;
                head = *(knot->left);
            }
            else {
                if (_bool) knot->parent->left = knot->left;
                else knot->parent->right = knot->left;
                knot->left->parent = knot->parent;
            }
        }
        else {
            TREE* del_tree;
            del_tree = knot->right;
            while(del_tree->left != nullptr) del_tree = del_tree->left;
            knot->value = del_tree->value;
            if (del_tree->parent->left == del_tree) del_tree->parent->left = del_tree->right;
            else del_tree->parent->right = del_tree->right;
        }
    }
};
 
int main() {
    int x;
    Tree tree;
    int counter = 0;
    while (!in.eof()) {
        string command;
        in >> command >> x;
        if (command == "insert") tree.insert(x);
        if (command == "delete") tree.del(x);
        if (command == "exists") {
            if (tree.exist(x)) out << "true\n";
            else out << "false\n";
        }
        if (command == "next") {
            if (tree.next(x) == NULL) out << "none\n";
            else out << tree.next(x) << '\n';
        }
        if (command == "prev") {
            if (tree.prev(x) == NULL) out << "none\n";
            else out << tree.prev(x) << '\n';
        }
    }
    return 0;
}
