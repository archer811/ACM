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
ll a[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        ll ans=0;
        ll pre=0;
        ll en=0;
        for(i=1;i<=n;i++)
        {
            if(pre>=a[i])
            {
                en += pre-a[i];
                //cout<<en<<" "<<pre<<" "<<a[i]<<endl;
            }
            else
            {
                ll tmp = a[i]-pre;
                if(tmp<=en)
                {
                    en-=tmp;

                }
                else
                {
                    ans += (tmp-en);
                    en=0;
                }

            }pre=a[i];
            //cout<<i<<"  "<<ans<<  "   "<<en<<  "  "<<pre<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
