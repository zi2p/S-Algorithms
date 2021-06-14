#include <fstream>
#include <vector>
#include <set>

using namespace std;
 
ifstream in("pathbgep.in");
ofstream out("pathbgep.out");

int n, l;
 
void distant_(vector < vector < pair <int, int> > > &M) {
    vector <int> d;
    set < pair < int, int> > ss;
    d.resize(n, 1000000000);
    d[l] = 0;
    ss.insert(make_pair(0,0));
    for (int i = 0; i < n; i++)
    {
        l = ss.begin()->second;
        ss.erase(ss.begin());
        for (int j = 0; j < M[l].size(); j++){
            if(M[l][j].second + d[l] < d[M[l][j].first]){              // минимальное расстояние до j
                ss.erase(make_pair(d[M[l][j].first], M[l][j].first));
                d[M[l][j].first] = M[l][j].second + d[l];
                ss.insert(make_pair(d[M[l][j].first], M[l][j].first));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) d[i] = 0;
        out << d[i] << " ";
    }
}
 
int main()
{
    int m;
    in >> n >> m;                               // n - количество вершин, m - количество ребер
    vector < vector <pair<int, int> > > Matrix(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        in >> x >> y >> w;
        Matrix[x-1].push_back(make_pair(y-1, w));
        Matrix[y-1].push_back(make_pair(x-1, w));
    }
    l = 0;
    distant_(Matrix);
 
    return 0;
}
