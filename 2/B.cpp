#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

string M[300001][2], N[300001];
string L[300001], R[300001];
 
void Merge(long long p, long long q, long long r)
{
    cin.tie(NULL);
    if (p >= r || q < p || q > r) return;
    long long j, i, k;
    long long n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
  
    for (i = 1; i <= n1; i++)
        L[i] = M[p + i - 1][1];
    
    for (j = 1; j <= n2; j++)
        R[j] = M[q + j][1];
 
    R[n2 + 1] = L[n1 + 1] = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";
    j = i = 1;
 
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            M[k][1] = L[i];
            i++;
        }
        else {
            M[k][1] = R[j];
            j++;
        }
    }
}

void MergeSort(long long p, long long r)
{
    cin.tie(NULL);
    if (p < r) {
        long long q;
        q = (p + r) / 2;
        MergeSort(p, q);
        MergeSort(q + 1, r);
        Merge(p, q, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, i, j, k;
    ifstream in;
    in.open("race.in");
    in >> n;
    for (i = 1; i <= n; i++) {
        in >> M[i][1] >> N[i];
        int num = i;
        for (j = 5; j >= 0; j--) {
            M[i][1] += char((num / int(pow(10, j)) + '0'));
            num %= int(pow(10, j));
        }
    }
  
    in.close();
  
    for (i = 1; i <= n; i++)
        M[i][2] = M[i][1];
   
    MergeSort(1, n);
  
    ofstream out;
    out.open("race.out");
    for (i = 1; i <= n; i++) {
        int num = 0;
        for (j = strlen(&M[i][1][0]) - 1; j > strlen(&M[i][1][0]) - 7; j--)
            num += pow(10, strlen(&M[i][1][0]) - 1 - j) * (M[i][1][j] - '0');
       
        M[i][1].resize(strlen(&M[i][1][0]) - 6);
        if (i == 1 || M[i - 1][1] != M[i][1])
            out << "=== " << M[i][1] << " ===" << '\n';
        out << N[num] << '\n';
    }
  
    out.close();
    return 0;
}
