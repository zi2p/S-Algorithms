#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int n; // число вершин
 
int main() {
    in >> n;
    int M[102][102];
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> M[i][j];
 
    bool t = true;
 
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (M[i][j]!=M[j][i] || (M[i][j]==1 && i==j))
                t=false;
 
 
    if (t) out << "YES";
    else out << "NO";
    return 0;
}
