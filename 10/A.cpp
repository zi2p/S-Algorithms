#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int n, m; // число вершин и число ребер
 
int main() {
    in >> n >> m;
    vector<int> M[101];
 
    for (int i = 1; i <= m; i++) {
        int x, y;
        in >> x >> y;
        M[x].push_back(y);
        M[y].push_back(x);
    }
 
    for (int i = 1; i <= n; i++) {
        out << M[i].size() << " ";
    }
    return 0;
}
