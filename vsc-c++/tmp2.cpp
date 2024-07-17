#include <iostream>
#include <set>
using namespace std;
struct node
{
    int b;
    friend bool operator<(const node &n1, const node &n2)
    {
        return n1.b < n2.b;
    }
};
int main()
{
    node y;
    y.b = 1;
    set<node> uu;
    uu.insert(y);
    set<node>::iterator it = uu.begin();
    cout << (*it).b << endl;
    return 0;
}