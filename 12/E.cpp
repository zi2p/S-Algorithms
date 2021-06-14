#include <iostream>
#include <vector>
using namespace std;
 
int d[101][2];
vector<vector<int> > tree;
 
void dfs(int v) {
    d[v][0] = 0;
    d[v][1] = 1;
    for (auto u : tree[v])
        dfs(u);
    for (auto u : tree[v]) {
        d[v][1] += d[u][0];
        d[v][0] += max(d[u][0], d[u][1]);
    }
}
 
int main() {
    int root;
    int n;
    tree.resize(101);
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;                 // предок
        if (x == 0) root = i;
        else tree[x].push_back(i);             // ребенок
        d[x][0]=0;
        d[x][1]=1;
        d[i][0]=0;
        d[i][1]=1;
    }
    dfs(root);
    cout << max(d[root][0], d[root][1]);
    return 0;
}
