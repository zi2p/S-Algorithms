#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("hamiltonian.in");
ofstream out("hamiltonian.out");
 
class Node
{
public:
    int visit = 1;       // проверка использованности(1-белый(не посещена),2-серый(частично посещена),3-черный(работа окончена))
    vector<int> neighbors;   // соседи
};
 
vector<int> Hamiltonian;        // Гамильтонов путь
 
void dfs_visit(vector<Node> &Graph, int index) {
    Graph[index].visit = 2;                                  // посетили 1 раз
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].visit == 1)       // не посещали
            dfs_visit(Graph, Graph[index].neighbors[i]);
    }
    Graph[index].visit = 3;                             // закончили работу с этой вершиной
    Hamiltonian.push_back(index);
}
 
void dfs(vector<Node> &Graph) {
    for (int i = 0; i < Graph.size(); i++)
        if (Graph[i].visit == 1)
            dfs_visit(Graph, i);
}
 
bool correct(vector<Node> &Graph, int from, int to) {
    for (int i = 0; i < Graph[from].neighbors.size(); i++)
        if (Graph[from].neighbors[i] == to)
            return true;
    return false;
}
 
int main() {
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Node> Graph(n);           // граф
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        Graph[x-1].neighbors.push_back(y-1);
    }
    dfs(Graph);
    for (int i = n - 1; i > 0; i--)
        if (!correct(Graph, Hamiltonian[i], Hamiltonian[i - 1])) {   // проверка на соседство вершин
            out << "NO";
            return 0;
        }
    out << "YES";
    return 0;
}
