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
int a[50005],b[50005],n;
int f(int mid)
{
    int s1=0,s2=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s1+=a[i];
        s2+=b[i];
        int t1=0,t2=0;
        if(s1>mid)
        {
            t1=s1-mid;
        }
        if(s2>mid)
        {
            t2=s2-mid;
        }
        //if(mid==5)cout<<i<<" "<<s<<" "<<t1<<" "<<t2<<endl;
        if(t1+t2>s)return 0;
        if(s1==0&&s2)
        {
            s2--;
        }
        else if(s1&&s2==0)
        {
            s1--;
        }
        else if(s1&&s2&&s<(s1+s2))s++;
    }
    return 1;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int s1=0,s2=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            s1 += a[i];
            s2 += b[i];
        }

        int l=1,r=max(s1,s2);
//        for(i=l;i<=r;i++)
//        {
//            cout<<i<<" "<<f(i)<<endl;
//        }
        while(l<r)
        {
            int mid = (l+r)/2;
            if(f(mid))r=mid;
            else l=mid+1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}
