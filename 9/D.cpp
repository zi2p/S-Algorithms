#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("cond.in");
ofstream out("cond.out");
 
class Node
{
public:
    int visit = 0;       // проверка использованности(1-белый(не посещена),2-серый(частично посещена),3-черный(работа окончена))
    int component = 0;
    vector<int> neighbors;   // соседи
};
 
vector<int> ORD;
int col = 1;
 
void dfs2(vector<Node> &Graph, int index) {
    Graph[index].component = col;                       // счёт компонент
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].component == 0) dfs2(Graph, Graph[index].neighbors[i]);
    }
}
 
void dfs1(vector<Node> &Graph, int index) {
    Graph[index].visit = 1;
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].visit == 0) dfs1(Graph, Graph[index].neighbors[i]);
    }
    ORD.push_back(index);  // порядок выхода
}
 
int main() {
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Node> G(n), H(n);           // граф
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        G[x-1].neighbors.push_back(y-1);
        H[y-1].neighbors.push_back(x-1);
    }
    for (int i = 0; i < G.size(); i++) {
        if (G[i].visit == 0) dfs1(G, i);          // обходим граф в глубину, смотрим порядок выхода
    }
    int size = ORD.size();
    for (int i = 0; i < size; i++) {
        if (H[ORD[ORD.size()-i-1]].component == 0) {           //  в обратном порядке запускаем счет компонент
            dfs2(H, ORD[ORD.size()-i-1]);
            col++;
        }
    }
    out << col - 1 << "\n";
    for (int i = 0; i < G.size(); i++) {
        out << H[i].component << " ";
    }
    return 0;
}
