#include <iostream>
#include <fstream>

using namespace std; 

int main()    
{
    int a, b;
    ifstream in;
    in.open("aplusb.in");
    in >> a >> b;
    in.close();
    ofstream out;
    out.open("aplusb.out");
    out << a + b;
    out.close();
    return 0;
}
