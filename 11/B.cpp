#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("pathsg.in");
ofstream out("pathsg.out");
int n, l;  // l - текущая вершина
long long min_distant(long long a, long long b) {
    if (a < b) return a;
    return b;
}
 
void distant_(vector < vector < long long > > &M) {
    vector <long long> d;
    vector <long long> v;
    v.resize(n,0);
    d.resize(n, 100000000000);
    int l1 = l;
    for (int i = 0; i < n; i++) d[i] = M[l1][i];   // начальные значение смежным вершинам
    v[l1] = 1;
    for (int i = 0; i < n-1; i++)
    {
        long long minimum = 100000000000;
        int now_minimum = l1;                                // для какой вершины считаем(начинаем со стартовой)
        for (int j = 0; j < n; j++)                               // ищем ближайшую вершину
            if (v[j] == 0 && minimum > d[j]) {
                minimum = d[j];                      // находим минимальное расстояние до следующей вершины
                now_minimum = j;
            }
        l1 = now_minimum;
        v[l1] = 1;
        for (int j = 0; j < n; j++)
            if (v[j] == 0)
                d[j] = min_distant(d[j], M[l1][j] + d[l1]);    // минимальное расстояние до j
    }
    for (int i = 0; i < n; i++) {
        if (i == l) d[i] = 0;
        out << d[i] << " ";
    }
    out << "\n";
}
 
int main()
{
    long long minimum = 100000000000;
    int m;
    in >> n >> m;                               // n - количество вершин, m - количество ребер
    vector < vector <long long> > Matrix(n);
    for (int i = 0; i < n; i++)
        Matrix[i].resize(n, minimum);
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        in >> Matrix[x-1][y-1];
    }
    for (l = 0; l < n; l++) {
        vector < vector < long long > > M = Matrix;
        distant_(M);
    }
    return 0;
}
