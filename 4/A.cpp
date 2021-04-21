#include <iostream>
#include <fstream>
#include <string>
   
using namespace std;
 
long long M, i, m, s_index = 0, S[1000001];
char n;
int r;


void SE() {
    if (s_index == 0) r = 0;
    else r = 1;
}
 
void Push() {
    s_index++;
    S[s_index] = m;
}
 
void Pop() {
    if (!r) s_index--;
}
 
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    ofstream out;
    in.open("stack.in");
    out.open("stack.out");
 
    in >> M;
    for (i = 1; i <= M; i++) {
        in >> n;
        if (n == '+') {
            in >> m;
            Push();
        }
        else {
            Pop();
            out << S[s_index + 1] << "\n";
        } 
    }
 
    in.close();
    out.close();
    return 0;
}
