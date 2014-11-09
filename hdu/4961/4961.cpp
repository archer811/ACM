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
const int maxn = 100006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int a[maxn];
ll b[maxn],c[maxn];
int pre[maxn],bk[maxn];
int main()
{
    int i,j,t,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll ans=0;
        memset(pre,-1,sizeof(pre));
        memset(bk,-1,sizeof(bk));
        for(i=1;i<=n;i++)
        {

            int x = -1;
            for(j=1;j*a[i]<=100000;j++)
            {
                int tmp = j*a[i];
                if(pre[tmp]!=-1)
                    x = max(x,pre[tmp]);
            }
            if(x==-1)x=i;
            //cout<<i<<" "<<a[x]<<endl;
            b[i]=a[x];
            if(pre[a[i]] == -1 || pre[a[i]]<i)
                pre[a[i]]=i;
        }
        for(i=n;i>=1;i--)
        {

            int x = 100001;
            for(j=1;j*a[i]<=100000;j++)
            {
                int tmp = j*a[i];
                if(bk[tmp]!=-1)
                    x = min(x,bk[tmp]);
            }
            if(x==100001)x=i;
           // cout<<i<<" "<<a[x]<<endl;
            c[i]=a[x];
            ans = ans + (ll)b[i]*(ll)c[i];
            if(bk[a[i]] == -1 || bk[a[i]]>i)
                bk[a[i]]=i;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
