#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int ans;
const int maxn = 0x3fffffff;
int i,j,n,m,a,b;
void f(int x,int y)
{
    int t1 = x-i;
    int t2 = y-j;
    if(t1<0)t1=-t1;
    if(t2<0)t2=-t2;
    if(t1%a||t2%b||(t1/a)%2!=(t2/b)%2)return;
    int t = t1/a;
    t = max(t,t2/b);
    if(t==t1/a)
    {
        if(t>t2/b)
        {
            if(m<b+1)return;
            //return;
        }
    }
    if(t==t2/b)
    {
        if(t>t1/a)
        {
            if(n<a+1)return;
        }
    }
    if(ans==-1)ans=t;
    else ans=min(ans,t);
}
int main()
{

    while(cin>>n>>m>>i>>j>>a>>b)
    {
        ans = -1;
        f(1,1);
        f(1,m);
        f(n,1);
        f(n,m);
        if(ans==-1)puts("Poor Inna and pony!");
        else
        cout<<ans<<endl;
    }
}
