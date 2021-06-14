#include <fstream>
#include <vector>
 
using namespace std;
 
long long min_distant(long long a, long long b) {
    if (a < b) return a;
    return b;
}
 
int main()
{
    long long minimum = 100000000000;
    int n, s, f, l, now_minimum;
    vector <long long> distant;
    vector <long long> visit;
    ifstream in("pathmgep.in");
    ofstream out("pathmgep.out");
    in >> n >> s >> f;                               // n - количество вершин, s - стартовая, f - конечная
    vector < vector <long long> > Matrix(n);
    l = s-1;                                                // l - текущая вершина
    visit.resize(n,0);
    distant.resize(n, minimum);
    for (int i = 0; i < n; i++) {
        Matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            in >> Matrix[i][j];
            if (Matrix[i][j] == -1 && i != j) Matrix[i][j] = minimum;
        }
    }
    for (int i = 0; i < n; i++) distant[i] = Matrix[l][i];   // начальные значение смежным вершинам
    visit[l] = 1;
    for (int i = 0; i < n-1; i++)
    {
        minimum = 100000000000;
        now_minimum = l;                                // для какой вершины считаем(начинаем со стартовой)
        for (int j = 0; j < n; j++)                               // ищем ближайшую вершину
            if (visit[j] == 0 && minimum > distant[j]) {
                minimum = distant[j];                      // находим минимальное расстояние до следующей вершины
                now_minimum = j;
            }
 
        l = now_minimum;
        visit[l] = 1;
        for (int j = 0; j < n; j++)
            if (visit[j] == 0)
                distant[j] = min_distant(distant[j], Matrix[l][j] + distant[l]);    // минимальное расстояние до j
    }
    if (distant[f-1] == 100000000000) out << "-1";
    else out << distant[f-1];
    return 0;
}
