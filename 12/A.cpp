#include <iostream>
#include <vector>
 
using namespace std;
 
int n;                      // размер исходной последовательности
 
vector<int> max_seq(vector<int> a) {
 
    int prev_[2001];               // кто его предыдущий товарищ
    int distant[2001];         // "расстояние" до элемента (какой он в подпоследовательности по счету)
 
    for (int i = 0; i < n; i++) {
        distant[i] = 1;
        prev_[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && distant[j] + 1 > distant[i]) {
                distant[i] = distant[j] + 1;
                prev_[i] = j;
            }
        }
    }
 
    int last = 0;                            // индекс последнего элемента подпоследовательности
    int length = distant[0];                      // длина подпоследовательности
    for (int i = 0; i < n; i++) {
        if (distant[i] > length) {
            last = i;
            length = distant[i];
        }
    }
 
    vector <int> seq;           // готовая подпоследовательность (наибольшая)
    while (last != -1) {
        seq.push_back(a[last]);
        last = prev_[last];                   //  по цепочке соседей находим всю подпоследовательность
    }
    reverse(seq.begin(), seq.end());              // делаем правильный порядок
 
    return seq;                     // готово
}
 
int main() {
    vector<int> a;             // последовательность
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
 
    vector<int> result = max_seq(a);
    cout << result.size() << "\n";
    for (auto i : result) cout << i << " ";
 
    return 0;
}
