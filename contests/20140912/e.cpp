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
int main()
{
    int i,j;
    int n,m,a,b;
    while(cin>>n>>m>>a>>b)
    {
        int ans=-1;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i+j*m>=n)
                {
                   int tmp = a*i+b*j;
                   if(ans==-1||ans>tmp)
                        ans=tmp;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
