#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;

int n, i, j, k;
int A, B, C, M[30000100];
 
int Part(int p, int r)
{
    int x, change;
    x = M[p + (rand() % (r - p))];
    i = p;
    j = r;
    while (i <= j) {
        while (M[i] < x)
            i++;
        while (x < M[j])
            j--;
        if (i >= j)
            break;
        swap(M[i++], M[j--]);
    }
    return j;
}
 
void QSort(int p, int r)
{
    int q;
    if (p < r) {
        q = Part(p, r);
        if (k <= q)
            QSort(p, q);
        if (k >= q + 1)
            QSort(q + 1, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    in.open("kth.in");
    in >> n >> k;
    in >> A >> B >> C;
 
    for (i = 1; i <= 2; i++)
        in >> M[i];
    in.close();
 
    for (i = 3; i <= n; i++)
        M[i] = A * M[i - 2] + B * M[i - 1] + C;
 
    ofstream out;
    out.open("kth.out");
    QSort(1, n);
 
    out << M[k];
    out.close();
    return 0;
}
