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
    int m,start_time,end_time,s;
    friend bool operator < (array x,array y)
    {
        return x.s<y.s;
    }
} tmp;
struct array2
{
    int m,p;
} ans[10005];
multiset<array>myset;
multiset<array>::iterator it;
multiset<array>::iterator it2;
int main()
{
    tmp.s = 1;
    myset.insert(tmp);
    for(it=myset.begin();it!=myset.end();it++)
    {
        cout<<it->s<<endl;
        it2 = it;
        myset.erase(it2);
    }
}
