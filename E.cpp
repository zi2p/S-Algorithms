#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
 
ifstream in("pathbge1.in");
ofstream out("pathbge1.out");
 
class Node {
public:
    int visit = 0;       // проверка использованности
    int distant = 0;                  // расстояние
    vector<int> neighbors;   // соседи
};
 
int main() {
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Node> Graph(n + 1);   // граф
    queue<int> Queue;
    for (int i = 1; i <= m; i++) {
        int x, y;
        in >> x >> y;
        Graph[x].neighbors.push_back(y);
        Graph[y].neighbors.push_back(x);
    }
 
    for (int i = 0; i < Graph[1].neighbors.size(); i++) {
        Queue.push(Graph[1].neighbors[i]);               // добавляем в очередь БЛИЖНИЙ КРУГ СОСЕДЕЙ
        Graph[Graph[1].neighbors[i]].distant++;               // +1 к расстоянию
        Graph[Graph[1].neighbors[i]].visit++;               // её посетили
        Graph[1].visit += 2;                              //  <- эту больше не посещаем
    }
 
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        Graph[node].visit++;
        for (int i = 0; i < Graph[node].neighbors.size(); i++)
            if (!Graph[Graph[node].neighbors[i]].visit) {
                Graph[Graph[node].neighbors[i]].visit++;
                Queue.push(Graph[node].neighbors[i]);
                Graph[Graph[node].neighbors[i]].distant = Graph[node].distant + 1;
            }
    }
 
    for (int i = 1; i <= n; i++)
        out << Graph[i].distant << " ";
    return 0;
}
