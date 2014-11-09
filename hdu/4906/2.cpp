#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll __int64
const ll mod = 1e9+7;
const int N = (1<<20)+10;
ll d[N];
int main()
{
    int i,j,t;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        ll l;
        scanf("%d%d%I64d",&n,&k,&l);
        memset(d,0,sizeof(d));
        d[0]=1;
        ll extra=0;
        if(l>k)extra=l-k;

    }
    return 0;
}
