#include <iostream>
#include <fstream>

using namespace std; 

int main()    
{
    int n, i, j, minimum, change;
    ifstream in;
    in.open("smallsort.in");
    in >> n;
    int M[10001];
    for (i = 0; i < n; i++)
        door >> M[i];
    for (i = 0; i < n - 1; i++) {
        minimum = i;
        for (j = i + 1; j < n; j++)
            if (M[j] < M[minimum])
                minimum = j; 
        change = M[i];
        M[i] = M[minimum];
        M[minimum] = change;
    }    
     
    in.close();
    ofstream out;
    out.open("smallsort.out");
    for (i = 0; i < n; i++)
        out << M[i] << " ";     
    out.close();  
    return 0;
}
