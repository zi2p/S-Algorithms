#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream in("height.in");
ofstream out("height.out");

struct tree {
    int left;
    int right;
    int value;
};
 
tree Tree[2000001];
 
int H(int knot) {
    if (knot == 0) return 0;
    int left = Tree[knot].left;
    int right = Tree[knot].right;
    if (left == 0 && right == 0) return 1;
    return max(H(right), H(left)) + 1;
}
 
int main() {
  
    int n;
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> Tree[i].value >> Tree[i].left >> Tree[i].right;
    if (n == 0) out << n << "\n";
    else out << H(1) << "\n";
    in.close();
    out.close();
    return 0;
}
