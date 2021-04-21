#include <iostream>
#include <fstream>
 
using namespace std;
long long n, i, M[100000000];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    in.open("isheap.in");
    in >> n;
    for (i = 1; i <= n; i++)
        in >> M[i];
    in.close();
  
    if (n % 2 == 1) 
        for (i = 1; i <= n / 2 + 1; i++) 
            if (!(2 * i + 1 <= n && M[i] <= M[2 * i + 1]))
                break; 
    else
        for (i = 1; i <= n / 2; i++)    
            if (!((2 * i <= n && M[i] <= M[2 * i])))
                break;
     
    ofstream out;
    out.open("isheap.out");
    if ((i >= n / 2 + 1 && n % 2 == 1) || (i >= n / 2 && n % 2 == 0))
        out << "YES";
    else out << "NO";
    out.close();
    return 0;
}
