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
#define ll  __int64

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
ll d[maxn][3];
inline void add(ll &x,ll y)
{
    if(x==-1)x=y;
    else x=x+y;
}
char c;
int Scan()
{
	int res = 0;
	c = getchar();
	while(!isdigit(c))c=getchar();
	while(c>='0'&&c<='9')
    {
        res = res*10+c-'0';
        c = getchar();
    }
	return  res;
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        //scanf("%d",&n);
        n = Scan();
        for(i=1; i<=n; i++)
        {
            //scanf("%d",&a[i]);
            a[i] = Scan();
            d[i][0]=d[i][1]=d[i][2]=-1;
        }
        a[0]=0;
        d[0][0]=-1;
        d[0][1]=-1;
        d[0][2]=1;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=3; j++)
            {
                if(d[i-1][0]!=-1)
                {
                    if(a[i-1]+j==a[i])
                    {
                        add(d[i][0],d[i-1][0]);
                    }
                    if(a[i-1]-j>0&&a[i-1]-j==a[i])
                    {
                        add(d[i][0],d[i-1][0]);
                    }
                    if(a[i-1]-j==0&&a[i-1]-j==a[i])
                    {
                        add(d[i][2],d[i-1][0]);
                    }
                    if(a[i-1]-j<0&&j-a[i-1]==a[i])
                    {
                        add(d[i][1],d[i-1][0]);
                    }
                }
                if(d[i-1][1]!=-1)
                {
                    if(a[i-1]+j==a[i])
                    {
                        add(d[i][1],d[i-1][1]);
                    }
                    if(a[i-1]-j>0&&a[i-1]-j==a[i])
                    {
                        add(d[i][1],d[i-1][1]);
                    }
                    if(a[i-1]-j==0&&a[i-1]-j==a[i])
                    {
                        add(d[i][2],d[i-1][1]);
                    }
                    if(a[i-1]-j<0&&j-a[i-1]==a[i])
                    {
                        add(d[i][0],d[i-1][1]);
                    }
                }
                if(d[i-1][2]!=-1)
                {
                    if(j==a[i])
                    {
                        add(d[i][0],d[i-1][2]);
                        add(d[i][1],d[i-1][2]);
                    }
                }
            }
           // cout<<i<<"  "<<d[i][0]<<" "<<d[i][1]<<" "<<d[i][2]<<endl;
        }
        ll ans=0;
        for(i=0;i<=2;i++)
        {
            if(d[n][i]!=-1)ans += d[n][i];
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}
