#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
 
ifstream in("bipartite.in");
ofstream out("bipartite.out");
 
class Node
{
public:
    int color = 0; // раскраска (1-белый,2-черный)
    vector<int> neighbors;   // соседи
};
bool can = true;
 
void dfs_visit(vector<Node> &Graph, int index, int color) {
    Graph[index].color = color;
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].color == 0) {
            if (color == 1) dfs_visit(Graph, Graph[index].neighbors[i], 2);
            else dfs_visit(Graph, Graph[index].neighbors[i], 1);
        }
        else if (Graph[Graph[index].neighbors[i]].color == Graph[index].color)
        {
            can = false;
            return;
        }
    }
}
 
void dfs(vector<Node> &Graph) {
    for (int i = 0; i < Graph.size(); i++)
        if (Graph[i].color == 0)
            dfs_visit(Graph, i, 1);
}
 
int main() {
    int n, m;               // число вершин и число ребер
    in >> n >> m;
    vector<Node> Graph(n);           // граф
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        Graph[x-1].neighbors.push_back(y-1);
        Graph[y-1].neighbors.push_back(x-1);
    }
    dfs(Graph);
    if (can) out << "YES";
    else out << "NO";
    return 0;
}
