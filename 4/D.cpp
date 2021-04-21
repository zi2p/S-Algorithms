#include <iostream>
#include <fstream>
#include <string>
  
using namespace std;

long long i, tail = 0;
int Q[1000001];
char x;
 
void DeQueue() {
 
    if (x == '+') {
        Q[tail - 2] = Q[tail - 1] + Q[tail - 2];
        tail = tail - 1;
    }
    if (x == '-') {
        Q[tail - 2] = Q[tail - 2] - Q[tail - 1];
        tail = tail - 1;
    }
    if (x == '*') {
        Q[tail - 2] = Q[tail - 2] * Q[tail - 1];
        tail = tail - 1;
    }
}
 
void EnQueue() {
    Q[tail] = x - '0';
    tail++;
}
 
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    ofstream out;
    in.open("postfix.in");
    out.open("postfix.out");
 
    while (!in.eof())
    {
        in >> x;
        if (x == '+' || x == '-' || x == '*')
            DeQueue();
        else
            EnQueue(); 
    }
 
    out << Q[0];
    in.close();
    out.close();
    return 0;
}
