#include <fstream>
#include <vector>
#include <cmath>
 
using namespace std;
 
struct Point {
    int x;
    int y;
};
class Node {
public:
    int visit = 0; //  (0-белый, 1-черный)
    vector<int> segment;   // расстояние между вершинами
    double distant = 1000000000;  // расстояние
};
 
int segment_size(Point a, Point b) {          // расстояние между вершинами
    return ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
 
void distant(int start, int n, vector<Node> &graph) {
    graph[start].distant = 0;
    for (int i = 0; i < n; i++) {                                                  // пробегаемся по всем вершинам
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!graph[j].visit && (v == -1 || graph[j].distant < graph[v].distant))  // находим минимальное расстояние
                v = j;                                                               // записываем при какой вершине достигается
        graph[v].visit = 1;
        for (int j = 0; j < n; j++)
            if (!graph[j].visit && graph[v].segment[j] < graph[j].distant && v != j)   // записываем значение этого минимального расстояния
                graph[j].distant = graph[v].segment[j];
    }
}
 
int main() {
    ifstream in("spantree.in");
    ofstream out("spantree.out");
    int n;
    in >> n;  // количество вершин
    vector<Node> Graph(n);
    vector<Point> points(n);
    points.resize(n);
    for (int i = 0; i < n; i++) {
        in >> points[i].x >> points[i].y;
        Graph[i].segment.resize(n);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Graph[i].segment[j] = segment_size(points[i], points[j]);
    distant(0, n, Graph);
    double result = 0;
    for (int i = 0; i < n; i++)
        result += sqrt(Graph[i].distant);
    out.precision(10);
    out << result;
    return 0;
}
