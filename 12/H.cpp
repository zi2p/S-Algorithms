#include <iostream>
#include <vector>
 
using namespace std;
 
int n;
vector<long long> T_shirt;
vector<vector<long long> > d;
 
int main() {
    cin >> n;
    T_shirt.resize(n);
    d.resize(n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++) {
        cin >> T_shirt[i];
        d[i][i] = 1;
    }
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            if (T_shirt[j] == T_shirt[j + i])
                d[j][j + i] = (d[j + 1][j + i] % 1000000000 + d[j][j + i - 1] % 1000000000 + 1) % 1000000000;
            else
                d[j][j + i] = (d[j + 1][j + i] % 1000000000 + d[j][j + i - 1] % 1000000000 - d[j + 1][j + i - 1] % 1000000000) % 1000000000;
        }
    }
    cout << (d[0][n - 1] + 1000000000) % 1000000000;
    return 0;
}
