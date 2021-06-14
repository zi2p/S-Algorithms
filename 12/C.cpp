#include <string>
#include <vector>
#include <iostream>
#include <bits\stdc++.h>
 
using namespace std;
 
void LCS(const string& x, string y, vector<int>& lastLine) {
 
    vector<vector<int>> two_s(2, vector<int>(y.length() + 1));
 
    for (int j = 0; j <= y.length(); j++) {
        two_s[1][j] = 0;         // первоначально "совпадений нет"
        two_s[0][j] = 0;
    }
 
    for (char i : x) {                                                       // проходимся по строке
        for (int j = 0; j <= y.length(); j++) two_s[0][j] = two_s[1][j];
        for (int j = 1; j <= y.length(); j++) {
            if (i == y[j - 1]) two_s[1][j] = two_s[0][j - 1] + 1;             // если элементы совпадают, то сколько в предыдущей ++
            else two_s[1][j] = max(two_s[1][j - 1], two_s[0][j]);              // если не совпали, то сохраняем наибольшее
        }
    }
 
    for (int j = 0; j <= y.length(); j++) lastLine[j] = two_s[1][j];          // сохраняем элементы последней строки "матрицы" в массив
}
 
void two_string(string x, string y) {
 
    if (y.empty()) return;    // если строка нулевая, то выходим
    if (x.length() == 1) {    // если строка состоит из 1 символа, то ищем его в другой строке, и если находим, то выводим его
        if (find(y.begin(), y.end(), x[0]) != y.end()) cout << x;
        return;
    }
 
    int middle = x.length() / 2;                                         // ищем середину строки
 
    vector<int> first_s(y.length() + 1);
    vector<int> second_s(y.length() + 1);
 
    LCS(x.substr(0, middle), y, first_s);   // substr возвращает подстроку от 0 до середины
 
    string x2 = x, y2 = y;                            // копии строк
    reverse(x2.begin(), x2.end());          // развернули строки
    reverse(y2.begin(), y2.end());
    LCS(x2.substr(0, x.length() - middle), y2, second_s);  // проверяем оставшуюся часть
 
    int maximal = second_s[0];                       // тут будем хранить максимальную длину подпоследовательности
    int index_maximal = 0;                     // туть ее индекс в массиве
 
    for (int j = 0; j <= y.length(); j++)
        if (first_s[j] + second_s[y.length() - j] > maximal) {      // массив секонд_с "перевернут" поэтому такая странная индексация
            maximal = first_s[j] + second_s[y.length() - j];
            index_maximal = j;
        }
 
    if (first_s[y.length()] > maximal) index_maximal = y.length();
 
    if (middle == 0) middle++;
 
    two_string(x.substr(0, middle), y.substr(0, index_maximal));          // запускаем алгоритм от первой "половины" строки и части где найдено наибольшее количество совпадений
    two_string(x.substr(middle, x.length()), y.substr(index_maximal, y.length()));       // аналогично от второй половины
}
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    two_string(s1, s2);
    return 0;
}
