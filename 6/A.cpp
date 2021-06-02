#include <iostream>
#include <fstream>

using namespace std;

ifstream in("set.in");
ofstream out("set.out");

#define FULL 100000

struct List {
    int value;
    List *next;
};

class Set {
private:
    List *start;                           // начало списка
public:
    Set() {
        start = new List();                           // новый элемент списка
        start->value = -1;
        start->next = NULL;                            // адрес следующего элемента NULL
    }
    void Insert(int val) {
        if (!Exists(val)) {                           // есть ли он уже
            List *news = new List();                             // новый элемент списка
            news->value = val;
            news->next = start->next;                   // следующий элемент -> следующий после старта
            start->next = news;                                    // обновляем следующий
        }
    }
  
    void Delete(int value) {
        List *numb = start;                             // счетчик
        while (numb->next != NULL) {
            if (numb->next->value == value) {
                List *del = numb->next;
                numb->next = numb->next->next;
                delete del;                                      // удаляем элемент
                break;
            }
            else numb = numb->next;
        }
    }
  
    bool Exists(int value) {
        List *numb = start;
        while (numb->next != NULL) {
            if (numb->next->value == value) return true;
            else numb = numb->next;
        }
        return false;
    }
};

class GOOD_Set {
private:
    Set tabl[FULL];
public:
    int find(int element) {
        int res = element % FULL;
        if (res < 0) res += FULL;
        return res;
    }
  
    void Insert(int element) {
        if (!Exists(element))
            tabl[find(element)].Insert(element);
    }
  
    bool Exists(int element) {
        return tabl[find(element)].Exists(element);
    }
  
    void Delete(int element) {
        tabl[find(element)].Delete(element);
    }
};

int main() {
    GOOD_Set Set_;
    string cmd;
    while (in >> cmd) {
        int x;
        in >> x;
        if (cmd == "insert") Set_.Insert(x);
        else if (cmd == "delete") Set_.Delete(x);
        else {
            if (Set_.Exists(x)) out << "true\n";
            else out << "false\n";
        }
    }
  
    return 0;
}
