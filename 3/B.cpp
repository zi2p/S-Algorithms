#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int n, i, A[100000000];
 
void Heap(int* number, int l, int r) {
  
    int max_; 
    int done = 0; 
    while ((l * 2 <= r) && (!done)) {
        if (l * 2 == r)
            max_ = l * 2;     
        else
            if (number[l * 2] > number[l * 2 + 1])
                max_ = l * 2;
            else
                max_ = l * 2 + 1;
 
        if (number[l] < number[max_]) {
            swap(number[l], number[max_]);
            l = max_;
        }
        else
            done = 1;
    }
}
 
void heapSort(int* number, int a_size) {
 
    for (int i = (a_size / 2) - 1; i >= 0; i--)
        Heap(number, i, a_size - 1);
 
    for (int i = a_size - 1; i >= 1; i--) {
        swap(number[0], number[i]);
        Heap(number, 0, i - 1);
    }
}
 
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in;
    in.open("sort.in");
    in >> n;
    for (i = 0; i < n; i++)
        in >> A[i];
    in.close();
 
    heapSort(A, n);
 
    ofstream out;
    out.open("sort.out");
    for (i = 0; i < n; i++)
        out << A[i] << " "; 
    out.close();
 
    return 0;
}
