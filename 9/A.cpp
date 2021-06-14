#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
 
ifstream in("topsort.in");
ofstream out("topsort.out");
 
class Node
{
public:
    int visit = 1;       // проверка использованности(1-белый(не посещена),2-серый(частично посещена),3-черный(работа окончена))
    vector<int> neighbors;   // соседи
};
 
stack<int> Stack;
bool can_sort = true;
 
void dfs_visit(vector<Node> &Graph, int index) {
    Graph[index].visit = 2;                                  // посетили 1 раз
    for (int i = 0; i < Graph[index].neighbors.size(); i++) {
        if (Graph[Graph[index].neighbors[i]].visit == 1)       // не посещали
            dfs_visit(Graph, Graph[index].neighbors[i]);
        else if (Graph[Graph[index].neighbors[i]].visit == 2)  // посетили 1 раз
            can_sort = false;                                     // невозможно отсортировать(предыдущая вершина уже покрашена в черный)
    }
    Graph[index].visit = 3;                             // закончили работу с этой вершиной
    Stack.push(index);                                  // добавляем ее в стек
}
 
void dfs(vector<Node> &Graph) {
    for (int i = 0; i < Graph.size(); i++)
        if (Graph[i].visit == 1)
            dfs_visit(Graph, i);
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
    if (!can_sort) {
        out << "-1";
        return 0;
    }
    int size_stack = Stack.size();
    for (int i = 0; i < size_stack; i++) {
        out << Stack.top() + 1 << " ";
        Stack.pop();
    }
    return 0;
}
