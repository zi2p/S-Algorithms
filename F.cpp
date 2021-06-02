#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
 
class Node {
public:
    int x;
    int y;
    int visit = 0;       // проверка использованности
    int distant = 0;     // расстояние
    vector<char> S;    // путь
    vector<int> neighbors;   // соседи
};
 
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
 
    int n, m;               // n строк по m символов
    in >> n >> m;
    vector<Node> Graph(10002);   // граф
    queue<int> Queue;
    int M[102][102];
    char x;
    int num = 1;
    int start=0, fin=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            in >> x;
            if (x == 'S' || x == 'T' || x == '.') {
                M[i][j] = num;
                num++;
                if (x == 'S') start = num-1;
                if (x == 'T') fin = num-1;
                Graph[num-1].x=j;
                Graph[num-1].y=i;
            }
            if (x == '#') M[i][j] = 0; // нет пути
        }
    }
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (M[i][j] > 0) {
                if (i > 1 && M[i-1][j] > 0) {
                    Graph[M[i][j]].neighbors.push_back(M[i-1][j]);
                    Graph[M[i-1][j]].neighbors.push_back(M[i][j]);
                }
                if (j > 1 && M[i][j-1] > 0) {
                    Graph[M[i][j]].neighbors.push_back(M[i][j-1]);
                    Graph[M[i][j-1]].neighbors.push_back(M[i][j]);
                }
            }
        }
    }
 
    for (int i = 0; i < Graph[start].neighbors.size(); i++) {
        Queue.push(Graph[start].neighbors[i]);               // добавляем в очередь БЛИЖНИЙ КРУГ СОСЕДЕЙ
        Graph[Graph[start].neighbors[i]].distant++;               // +1 к расстоянию
        Graph[Graph[start].neighbors[i]].visit++;               // её посетили
        Graph[start].visit += 2;                              //  <- эту больше не посещаем
        if (Graph[start].x - Graph[Graph[start].neighbors[i]].x == -1) Graph[Graph[start].neighbors[i]].S.push_back('R');
        if (Graph[start].x - Graph[Graph[start].neighbors[i]].x == 1) Graph[Graph[start].neighbors[i]].S.push_back('L');
        if (Graph[start].y - Graph[Graph[start].neighbors[i]].y == -1) Graph[Graph[start].neighbors[i]].S.push_back('D');
        if (Graph[start].y - Graph[Graph[start].neighbors[i]].y == 1) Graph[Graph[start].neighbors[i]].S.push_back('U');
    }
 
    while (!Queue.empty())         // пока очередь не пуста
    {
        int node = Queue.front();    // выписываем узел из очереди
        Queue.pop();                   // удаляем этот узел
        Graph[node].visit++;           // отмечаем посещаемость узла
        for (int i = 0; i < Graph[node].neighbors.size(); i++)      // проходим по соседям
            if (!Graph[Graph[node].neighbors[i]].visit) {          // если не посещали
                Graph[Graph[node].neighbors[i]].visit++;           // отмечаем посещаемость
                Graph[Graph[node].neighbors[i]].S = Graph[node].S;
                if (Graph[node].x - Graph[Graph[node].neighbors[i]].x == -1) Graph[Graph[node].neighbors[i]].S.push_back('R');
                if (Graph[node].x - Graph[Graph[node].neighbors[i]].x == 1) Graph[Graph[node].neighbors[i]].S.push_back('L');
                if (Graph[node].y - Graph[Graph[node].neighbors[i]].y == -1) Graph[Graph[node].neighbors[i]].S.push_back('D');
                if (Graph[node].y - Graph[Graph[node].neighbors[i]].y == 1) Graph[Graph[node].neighbors[i]].S.push_back('U');
                Queue.push(Graph[node].neighbors[i]);              // добавляем смежные вершины в очередь
                Graph[Graph[node].neighbors[i]].distant = Graph[node].distant + 1;   // записываем расстояние
            }
    }
 
    if (Graph[fin].distant > 0) {
        out << Graph[fin].distant << "\n";
        for (int i = 0; i < Graph[fin].S.size(); i++)
            out << Graph[fin].S[i];
    }
    else out << "-1";
 
    return 0;
}
