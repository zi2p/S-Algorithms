#include <fstream>
#include <vector>
 
using namespace std;

ifstream in("negcycle.in");
ofstream out("negcycle.out");
 
struct edge {
    int from;
    int to;
    int weight;
};
 
int MAXIMUM = 1000000000;
int n;   // кол-во вершин
int start = -1;
vector<edge> G;
vector<int> d;
vector<int> parent;
 
void find_distant() {
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        start = -1;
        for (edge e : G) {
            if (d[e.to] > d[e.from] + e.weight) { // если расстояние до конца ребра сейчас больше, чем пройти через него, то заменяем
                d[e.to] = d[e.from] + e.weight;
                parent[e.to] = e.from;                     // запоминаем порядок вершин
                start = e.to;                      // запоминаем конечную вершину
            }
        }
    }
}
 
int main() {
    in >> n;
    G.resize(n);
    d.resize(n, MAXIMUM);
    parent.resize(n);                     // откуда-куда
 
    for (int i = 0; i < n; i++) {                // откуда
        for (int j = 0; j < n; j++) {              //  куда
            int w;                         //   вес
            in >> w;
            G.push_back({i, j, w});
        }
    }
 
    find_distant();
 
    if (start != -1) {                     //  если цикл есть
        vector<int> way;
        int finish = start;
        for (int i = 0; i < n; i++) {    // находим начало
            finish = parent[finish];
        }
 
        for (int now = finish; now != finish || way.empty(); now = parent[now]) way.push_back(now);  // записываем цикл
        way.push_back(finish);                 // первая и последняя (одна и таже)
        reverse(way.begin(), way.end());        //  разворачиваем
        out << "YES\n";
        out << way.size() << "\n";
        for (int v : way) out << v + 1 <<" ";
    }
 
    else out << "NO";
    return 0;
}
