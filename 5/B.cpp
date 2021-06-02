#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream in("check.in");
ofstream out("check.out");
int i;

struct tree
{
    int left;
    int right;
    int value;
    int maximum;
    int minimum;
};

bool yes_or_no = true;
tree Tree[2000001];
 
void check(int knot)
{
    int val=Tree[knot].value;
    int val_left=Tree[knot].left;
    int val_right=Tree[knot].right;
    if (knot == 0) return;
    if ((val_left!=0 and val <= Tree[val_left].maximum) or (val_right !=0 and Tree[val_right].minimum <= val))
    {
        yes_or_no=false;
        return;
    }
    if (val_left) check(val_left);
    if (val_right) check(val_right);
}
 
int maximum_(int knot)
{
    int left = Tree[knot].left;
    int right = Tree[knot].right;
    if (left==0 and right==0) Tree[knot].maximum=Tree[knot].value;
    if (left==0 and right!=0) Tree[knot].maximum=maximum_(right);
    if (left!=0 and right==0) Tree[knot].maximum=maximum_(left);
    if (left!=0 and right!=0) Tree[knot].maximum=max(maximum_(right), maximum_(left));
    return Tree[knot].maximum;
}
 
int minimum_(int knot)
{
    int left = Tree[knot].left;
    int right = Tree[knot].right;
    if (left==0 and right==0) Tree[knot].minimum=Tree[knot].value;
    if (left!=0 and right==0) Tree[knot].minimum=minimum_(left);
    if (left==0 and right!=0) Tree[knot].minimum=minimum_(right);
    if (left!=0 and right!=0) Tree[knot].minimum=min(minimum_(right), minimum_(left));
    return Tree[knot].minimum;
}
 
int main()
{
    int n;
    in >> n;
  
    for (i = 1; i <= n; i++)
        in >> Tree[i].value >> Tree[i].left >> Tree[i].right;
    
    minimum_(1);
    maximum_(1);
    check(1);
    if (yes_or_no) out << "YES";
    else out << "NO";
    return 0;
}
