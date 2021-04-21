#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
 
using namespace std;
 
int n, i;
double h[1000001];
 
double Binary_S() {
    double l = 0, r = h[0];
    while (r - l > 0.0000000001) {
        h[1] = (l + r) / 2;
        bool bool_ = true;
        for (i = 2; i < n; i++) {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;
            if (h[i] < 0) {
                bool_ = false;
                break;
            }
        }
        if (bool_)
            r = h[1];
        else
            l = h[1];
    }
    return h[n - 1];
}
 
int main() {
    ifstream in;
    ofstream out;
    in.open("garland.in");
    out.open("garland.out");
    in >> n;
    in >> h[0];
    double a = Binary_S();
    out << fixed << setprecision(2) << a;
    in.close();
    out.close();
    return 0;
}
