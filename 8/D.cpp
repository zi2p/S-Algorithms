#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("components.in");
ofstream out("components.out");
 
class Components
{
public:
    bool visit = false;       // проверка использованности
    int components_number;     // номер компаненты
    vector<int> neighbors;   // соседи
};
 
void Invoice_Components(int index, vector<Components> &Graph, int components) {
    Graph[index].visit = true;
    Graph[index].components_number = components;
    for (int i = 0; i < Graph[index].neighbors.size(); i++)                   // проходим смежные вершины графа
        if (!Graph[Graph[index].neighbors[i]].visit)
            Invoice_Components(Graph[index].neighbors[i], Graph, components);       // смотрим их смежные вершины
 
}
 
int main() {
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Components> Graph(n + 1);   // граф
    for (int i = 1; i <= m; i++) {
        int x, y;
        in >> x >> y;
        Graph[x].neighbors.push_back(y);
        Graph[y].neighbors.push_back(x);
    }
    int components = 0;
    for (int i = 1; i <= n; i++)
        if (!Graph[i].visit)
            Invoice_Components(i, Graph, ++components);
 
    out << components << "\n";
    for (int i = 1; i <= n; i++)
        out << Graph[i].components_number << " ";
    return 0;
}
