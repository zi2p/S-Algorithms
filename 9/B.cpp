#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
ifstream in("cycle.in");
ofstream out("cycle.out");
 
class Node
{
public:
    int visit = 1;       // проверка использованности(1-белый(не посещена),2-серый(частично посещена),3-черный(работа окончена))
    vector<int> neighbors;   // соседи
};
 
int start = -1, finish = -1;
 
bool dfs_visit1(vector<Node> &Graph, int index, vector<int> &cycle) {
    Graph[index].visit = 2;                                  // посетили 1 раз
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].visit == 1) {      // не посещали
            cycle[Graph[index].neighbors[i]] = index;
            if (dfs_visit1(Graph, Graph[index].neighbors[i], cycle)) return true;
        }
        else if (Graph[Graph[index].neighbors[i]].visit == 2) { // посетили 1 раз
            start = Graph[index].neighbors[i];
            finish = index;
            return true;
        }
    }
    Graph[index].visit = 3;                             // закончили работу с этой вершиной
    return false;
}
 
void dfs(vector<Node> &Graph, vector<int> &cycle) {
    for (int i = 0; i < Graph.size(); i++)
        if (dfs_visit1(Graph, i, cycle)) break;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Node> Graph(n);           // граф
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        Graph[x-1].neighbors.push_back(y-1);
    }
    vector<int> cycle;
    cycle.resize(n, -1);
    dfs(Graph, cycle);
    vector<int> write;
    if (start != -1) {
        out << "YES\n";
        write.push_back(finish + 1);
        while (cycle[start] != cycle[finish]) {
            int j = cycle[finish];
            write.push_back(j + 1);
            finish = j;
        }
    }
    else {
        out << "NO";
        return 0;
    }
    for (int i = write.size() - 1; i >= 0; i--) {
        out << write[i] << " ";
    }
    return 0;
}
