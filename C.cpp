#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int n, m; // число вершин и число ребер
 
int main() {
    in >> n >> m;
    int M[102][102];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) M[i][j] = 0;
 
    for (int i = 1; i <= m; i++) {
        int x, y;
        in >> x >> y;
        M[x][y] += 1;
    }
    bool t=false;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if ((M[i][j] == M[j][i] && M[i][j] >= 1) || (M[i][j] > 1))
                t = true;
    if (t) out << "YES";
    else out << "NO";
    return 0;
}
