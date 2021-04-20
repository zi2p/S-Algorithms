#include <iostream>
#include <fstream>

using namespace std;

long long L[300001], R[300001];
long long s = 0;
long long M[300001];

void Merge(long long M[300001], long long p, long long q, long long r)
{
    long long i, j;
    long long n1, n2;                        
    n1 = q - p + 1;
    n2 = r - q;
    for (i = 1; i <= n1; i++)
        L[i] = M[p + i - 1];        
    for (j = 1; j <= n2; j++)
        R[j] = M[q + j];        
    L[n1 + 1] = 1000000001;  
    R[n2 + 1] = 1000000001;
    i = 1;
    j = 1;
    for (long long k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            M[k] = L[i];
            i++;            
        }
        else {
            M[k] = R[j];
            j++;
            s += n1 - i + 1;
        }
    }
}

void MergeSort(long long M[300001], int p, int r)
{
    long long q;
    if (p < r) {
        q = (p + r) / 2;
        MergeSort(M, p, q);
        MergeSort(M, q + 1, r);
        Merge(M, p, q, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    long long n, i;
    ifstream in;
    in.open("inversions.in");
    in >> n;
    for (i = 1; i <= n; i++)
        in >> M[i];
    in.close();
    
    MergeSort(M, 1, n);
    ofstream out;
    out.open("inversions.out"); 
    out << s; 
    out.close();
    return 0;
}
