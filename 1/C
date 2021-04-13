#include <iostream>
#include <fstream>

using namespace std; 

int M[1001][1001], m[1001][1001];

int main()    
{
    ios_base::sync_with_stdio(false);
    int h, w, j, i, payoff; 
    ifstream in;
    in.open("turtle.in");
    in >> h >> w;
    
    for (i = h; i > 0; i--) 
        for (j = 1; j < w + 1; j++)
            in >> M[i][j];  
  
    m[1][1] = M[1][1];
    for (i = 2; i < h + 1; i++)
        m[i][1] = m[i - 1][1] + M[i][1]; 
        
    for (i = 2; i < w + 1; i++)
        m[1][i] = m[1][i - 1] + M[1][i]; 
        
    for (i = 2; i < h + 1; i++) 
        for (j = 2; j < w + 1; j++) {
            if (m[i][j - 1] + M[i][j] >= m[i - 1][j] + M[i][j])
                m[i][j] = m[i][j - 1] + M[i][j];
            if (m[i][j - 1] + M[i][j] < m[i - 1][j] + M[i][j])
                m[i][j] = m[i - 1][j] + M[i][j];
        }
        
    payoff = m[h][w];
    in.close();
    ofstream out;
    out.open("turtle.out");
    out << payoff;
    out.close();   
    return 0;
}
