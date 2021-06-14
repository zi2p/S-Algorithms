#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("game.in");
ofstream out("game.out");

class Node
{
public:
    int win = 0;        // 0-победа второго, 1-победа первого
    int visit = 0;       // проверка использованности(1-первый,2-второй)
    vector<int> neighbors;   // соседи
};
 
void dfs(vector<Node> &Graph, int index) {
    Graph[index].visit = 1;
    if (Graph[index].neighbors.empty()) {
        Graph[index].win = 0;
        return;
    }
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].visit == 0) {      // не посещали
            dfs(Graph, Graph[index].neighbors[i]);
        }
        if (!Graph[Graph[index].neighbors[i]].win && !Graph[index].win) Graph[index].win = 1;
    }
}
int main() {
    int n, m, start;               // число вершин и число ребер, стартовая вершина
    in >> n >> m >> start;
    vector<Node> G(n);           // граф
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        G[x-1].neighbors.push_back(y-1);
    }
    dfs(G, start-1);
    string s[2];
    s[0] = "Second player wins";
    s[1] = "First player wins";
    out << s[G[start-1].win];
    return 0;
}
