#include <iostream>
#include <fstream>

using namespace std;

int main()    
{
    int n, i, j, penniless, central, rich, minimal;
    float change, less, full, half;
    ifstream in;
    in.open("sortland.in");
    in >> n;
    float M[10001][2];
    
    for (i = 0; i < n; i++)
        door >> M[i][1];
     
    for (i = 0; i < n; i++)
        M[i][2] = M[i][1];
    
    for (i = 0; i < n - 1; i++) {
        minimal = i;
        for (j = i + 1; j < n; j++)
            if (M[j][1] < M[minimal][1])
                minimal = j; 
        change = M[i][1];
        M[i][1] = M[minimal][1];
        M[minimal][1] = change;
    }
    
    less = M[0][1];
    full = M[n - 1][1];
    half = M[n / 2][1];
    
    for (i = 0; i < n; i++) {
        if (M[i][2] == full)
            rich = i;
        if (M[i][2] == less)
            penniless = i;
        if (M[i][2] == half)
            central = i; 
    }
 
    in.close();
    ofstream out;
    out.open("sortland.out");
    out << penniless + 1 << " " << central + 1 << " " << rich + 1;
    out.close();    
    return 0;
}
