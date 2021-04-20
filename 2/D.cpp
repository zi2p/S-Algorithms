#include <iostream>
#include <fstream>
 
using namespace std;

long long n, i;
long long M[300001], change;

void AntiS()
{
    for (i = 2; i < n; i++) {
        change = M[i];
        M[i] = M[i / 2];
        M[i / 2] = change;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    in.open("antiqs.in");
    in >> n;    
    for (i = 0; i < n; i++)
        M[i] = i + 1;
    in.close();   
    AntiS();
    ofstream out;
    out.open("antiqs.out");
    for (i = 0; i < n; i++)
        out << M[i] << " ";
    out.close();
    return 0;
}
