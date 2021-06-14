#include <fstream>
#include <vector>
 
using namespace std;
 
int d[101][2];
vector<vector<int> > tree;
vector<int> weight;
 
void dfs(int v) {
    d[v][0] = 0;
    d[v][1] = weight[v];
    for (auto u : tree[v])
        dfs(u);
    for (auto u : tree[v]) {
        d[v][1] += d[u][0];
        d[v][0] += max(d[u][0], d[u][1]);
    }
}
 
int main() {
    ifstream in("selectw.in");
    ofstream out("selectw.out");
    int root;
    int n;
    weight.resize(101, 0);
    tree.resize(101);
    in >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        in >> x >> weight[i];                 // предок
        if (x == 0) root = i;
        else tree[x].push_back(i);             // ребенок
        d[x][0]=0;
        d[x][1]=1;
        d[i][0]=0;
        d[i][1]=1;
    }
    dfs(root);
    out << max(d[root][0], d[root][1]);
    return 0;
}
