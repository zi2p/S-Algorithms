#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

long long M, i, tail = 0, head = 0, x, Q[1000001];
char n;
int r;

void DeQueue() {
    x = Q[head];
    head++;
}
 
void EnQueue() {
    Q[tail] = x;
    tail++;
}
 
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    ofstream out;
    in.open("queue.in");
    out.open("queue.out");
 
    in >> M; 
    for (i = 1; i <= M; i++) {
        in >> n;
        if (n == '+') {
            in >> x;
            EnQueue();
        }
        else {
            DeQueue();
            out << x << "\n";
        } 
    }
 
    in.close();
    out.close();
    return 0;
}
