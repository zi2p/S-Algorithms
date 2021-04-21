#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

int n, x, M[100001];
int m, m_, l, r, rl, i;
 
void binary_S_last() {
    rl = r - 1;
    for (int j = r; j <= n; j++) {
        if (M[j] == x) rl++;
        if (M[j] != x) break;
    }
}
 
void binary_S_first() {
    l = 0;
    r = n + 1;
    while (r > l + 1) {
        m_ = (l + r) / 2;
        if (M[m_] < x)
            l = m_;
        else r = m_;
    }
    if (r <= n && M[r] == x)
        binary_S_last();
    else {
        rl = -1;
        r = -1;
    }
}
 
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    ofstream out;
    in.open("binsearch.in");
    out.open("binsearch.out");
  
    in >> n;
  
    for (i = 1; i <= n; i++)
        in >> M[i];
  
    in >> m;
  
    for (i = 1; i <= m; i++) {
        in >> x;
        binary_S_first();
        out << r << " " << rl << '\n';
    }
 
    in.close();
    out.close();
    return 0;
}
