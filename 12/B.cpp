#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long n;                      // размер исходной последовательности
 
long long max(long long a, long long b) {
    if (a > b) return a;
    return b;
}
 
vector<long long> max_seq(vector<long long> a) {
 
    vector <long long> distant;                                   // наибольшее число подпоследовательности
    distant.resize(n + 1, 999999999999990999);
    distant[0] = -999999999999990999;
    vector <long long> last_of_seq;                               // индекс наибольшего числа подпоследовательности
    last_of_seq.resize(n + 1, -1);
    vector <long long> prev_;                                 // предыдущий элемент
    prev_.resize(n);
    long long length = 0;
 
 
    for (long long i = 0; i < n; i++) {
        long long j = (long long)(upper_bound(distant.begin(), distant.end(), a[i]) - distant.begin()); // поиск первого встречного большего(равного данному)
        if (distant[j - 1] < a[i] && a[i] < distant[j]) {     // запоминание большего
            distant[j] = a[i];
            last_of_seq[j] = i;
            prev_[i] = last_of_seq[j - 1];                 //  запоминание последовательности элементов
            length = max(length, j);
        }
    }
 
    vector<long long> result;                         // готовая подпоследовательность
    long long last = last_of_seq[length];
    while (last != -1) {
        result.push_back(a[last]);                   // "раскручиваем" порядок подпоследовательности
        last = prev_[last];
    }
    reverse(result.begin(), result.end());                // делаем правильный порядок
    return result;                                       // готово
}
 
int main() {
    vector<long long> a;             // последовательность
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
 
    vector<long long> result = max_seq(a);
    cout << result.size() << "\n";
    for (auto i : result) cout << i << " ";
 
    return 0;
}
