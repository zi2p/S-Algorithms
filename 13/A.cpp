#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
 
int main() {
    ifstream in("search1.in");
    ofstream out("search1.out");
    string S, P;
    vector<int> str;
    in >> P >> S;
    for (int i = 0; i < S.size(); i++) {
        int j = 0;
        for (; j < P.size(); j++) {
            if (S[i + j] != P[j]) break;
        }
        if (j == P.size())
            str.push_back(i + 1);
    }
    out << str.size() << "\n";
    if (!str.empty())
        for (auto i : str) out << i << " ";
}
