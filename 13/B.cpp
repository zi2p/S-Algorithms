#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
 
using namespace std;
 
const int abc_size = 'z' - 'A' + 1;
 
int main() {
    ifstream in("search2.in");
    ofstream out("search2.out");
    string S, T;
    in >> S >> T;   // вхождение строки S в T
 
    int *p = new int[S.size() + 1];   // временная "префикс функция", работающая по алгоритму КМП
    p[0] = 0;
    p[1] = 0;
    for (int i = 1, j = 0; i < S.size();) {
        if (S[i] == S[j]) {                  // если совпали, то увеличиваем на 1
            p[i + 1] = j + 1;
            i++;
            j++;
        }
        else if (j > 0) j = p[j];               // если не так, и следующий больше 0, перемещаемся назад на это значение
        else {
            p[i + 1] = 0;     // если и то условие не выполнилось, то ноль
            i++;
        }
    }
 
    auto transitions = *(new vector<map<int, int> >(S.size() + 1)); // переход связанный со значением буквы
 
    for (int i = 0; i < S.size(); i++)
        transitions[i][S[i] - 'A'] = i + 1;
 
    for (int i = 1; i <= S.size(); i++) {
        for (int j = 0; j < abc_size; j++)                            // ищем вхождения и запоминаем положение
            if (transitions[i].find(j) == transitions[i].end() && transitions[p[i]].find(j) != transitions[p[i]].end())
                transitions[i][j] = transitions[p[i]][j];
    }
 
    vector<int> positions;               //   положения
    int current = 0;
    for (int i = 0; i < T.size(); i++) {
        current = transitions[current][T[i] - 'A'];    // ищем положение соответствующего значения
        if (current == S.size())
            positions.push_back(i - S.size() + 1 + 1);  // запоминаем положение (т.к. с нуля нумеруем + размер(+1))
    }
 
    out << positions.size() << "\n";
    for (auto position : positions) out << position << " ";
}
