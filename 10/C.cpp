#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
long long min_w = 0;  // вес
 
ifstream in("spantree3.in");
ofstream out("spantree3.out");
 
class Edge {                             // ребро
public:
    int vertex_1;
    int vertex_2;
    int weight = 0;
};
 
bool Comparison(const Edge e1, const Edge e2) {     // упорядочевание
    return (e1.weight < e2.weight);
}
 
int find(int x, vector<int> &color) {              // поиск корня
    if (color[x] == x) return x;
    return color[x] = find(color[x], color);
}
 
void unite(int x, int y, vector<int> &sizeof_vertex, vector<int> &color) {    // соединение корней
    if (sizeof_vertex[x] < sizeof_vertex[y])
        color[x] = y;                                                              // приравнивание цвета корня
    else {
        color[y] = x;
        if (sizeof_vertex[x] == sizeof_vertex[y])
            ++sizeof_vertex[x];                                                // количество вершин в дереве
    }
}
 
int main() {
    int n, m;
    in >> n >> m;
    vector<Edge> Graph(m);
    vector<int> color(n, 0);
    vector<int> sizeof_vertex(n, 0);
 
    for (int i = 0; i < n; i++)             // всем свой цвет
        color[i] = i;
 
    for (int i = 0; i < m; i++)
        in >> Graph[i].vertex_1 >> Graph[i].vertex_2 >> Graph[i].weight;
 
    sort(Graph.begin(), Graph.end(), Comparison);    // сортировка по возрастанию
    for (auto i : Graph) {
        int root_1 = find(i.vertex_1-1, color);       // поиск корней вершин одного ребра
        int root_2 = find(i.vertex_2-1, color);
        if (root_1 != root_2) {                            // если корни не равны, нужно объединить
            min_w += i.weight;
            unite(root_1, root_2, sizeof_vertex, color);
        }
    }
    out << min_w;
    return 0;
}
