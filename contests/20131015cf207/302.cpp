#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
struct array
{
    int num;
    friend bool operator < (array x,array y)
    {
        return x<y;
    }
}tmp;
set<array>s;
set<array>::iterator it;
int main()
{
    tmp.num=1;
    s.insert(tmp);
    tmp.num=3;
    s.insert(tmp);
    tmp.num=2;
    it = s.find(tmp);
    cout<<it->num<<endl;
}
