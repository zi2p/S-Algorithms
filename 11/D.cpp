#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("path.in");
ofstream out("path.out");
 
class edge {
public:
    long long from;
    long long to;
    long long weight;
};
 
long long n, m, s;                       // количество вершин, ребер и стартовая вершина
long long MAXIMUM = 9199999999999999999;
vector<vector <long long> > G;         // граф
vector<bool> v;                      // посещение
vector<long long> d;             // расстояние до
vector<edge> edges;             // ребра
 
void dfs(long long from) {
    v[from] = true;                  // посещаем те вершины которые достиглись из отрицательного веса цикла
    for (long long to : G[from])
        if (!v[to]) dfs(to);
}
 
void new_distantion() {
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < m; ++j)
            if (d[edges[j].from] < MAXIMUM && d[edges[j].to] > d[edges[j].from] + edges[j].weight)       // запоминаем наименьшее расстояние до этой вершины
                d[edges[j].to] = max(-MAXIMUM, d[edges[j].from] + edges[j].weight);
}
 
void find_cycle() {
    for (int i = 0; i < m; ++i)
        if (d[edges[i].from] < MAXIMUM && d[edges[i].to] > d[edges[i].from] + edges[i].weight)   // внимание! найден цикл отрицательного веса!
            dfs(edges[i].to);
}
 
int main() {
 
    in >> n >> m >> s;
    G.resize(n);
    v.resize(n, false);
    d.resize(n, MAXIMUM);
 
    for (long long i = 0; i < m; i++) {
        long long from, to, weight;
        in >> from >> to >> weight;
        edges.push_back({from - 1, to - 1, weight});
        G[from - 1].push_back(to - 1);
    }
    d[s-1] = 0;
    new_distantion();
    find_cycle();
    for (long long i = 0; i < n; ++i) {
        if (v[i]) out << "-\n";
        else if (d[i] == MAXIMUM) out << "*\n";
        else out << d[i] << "\n";
    }
    return 0;
}
