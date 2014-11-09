#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int a[100005];
int main()
{
    int i,j;
    int n,m;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        int now=1;
        for(i=1;;i++)
        {
            if(i==now*m)
            {
                now++;
                if(n==0)break;
                continue;
            }
            n--;
            if(n==0)break;
        }
        cout<<i<<endl;
    }
    return 0;
}
