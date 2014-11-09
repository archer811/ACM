#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
const ll mod = 1000000007;
int n,m;
vector<int>g[105];
int vis[105];
int num[105],f[105];
int mark[105][105];
int find(int x)
{
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void add(int u,int v)
{
    int x = find(u), y = find(v);
    if(x==y)return;
    if(x<y)
    {
        f[y]=x;
        num[x]+=num[y];
    }
    else
    {
        f[x]=y;
        num[y]+=num[x];
    }
}
int d[105];
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
            f[i]=i,num[i]=1;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            mark[i][j]=mark[j][i]=1;
        }
        int r2=0,r1=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(mark[i][j])add(i,j),d[i]++,d[j]++;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(d[i]!=2)r2=1;
            if(find(i)!=find(1))r1=1;
        }
        //cout<<r2<<" "<<r1<<endl;
        if(r2==0&&r1==0)
        {
            puts("2");
            continue;
        }
        else if(r2==0&&r1)
        {
            puts("0");
            continue;
        }
//        for(i=1;i<=n;i++)
//            cout<<i<<"*"<<d[i]<<endl;
        int fuck=0,flag=0;
        for(i=1;i<=n;i++)
        {
            if(d[i]>=3)flag=1;
            if(find(i)==find(1))
            {
                fuck++;
            }
        }
        //cout<<flag<<endl;
        if(flag)
        {
            puts("0");
            continue;
        }
        int num1 =0,num2=0;
        flag=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                int sum=0;
                flag=1;
                //cout<<i<<"*"<<endl;
                for(j=1;j<=n;j++)
                {
                    if(find(j)==find(i))
                    {
                        if(d[j]==1)flag=0;
                        vis[j]=1;
                        sum++;
                    }
                }

                if(sum<=2)flag=0;
                //cout<<sum<<" "<<flag<<endl;
                if(flag)break;

                num1++;
                if(sum>=2)num2++;
            }
        }
       // cout<<flag<<endl;
        if(flag)
        {
            puts("0");
            continue;
        }
        //cout<<num1<<" "<<num2<<endl;
        ll ans =1;
        num1-=1;
        if(fuck>=2)num2-=1;
        if(fuck>=2)ans=2;
        for(i=1;i<=num1;i++)
        {
            ans = (ans*(ll)i)%mod;
        }
        for(i=1;i<=num2;i++)
            ans = ans*(ll)2%mod;
        if(n==2)ans=1;
        printf("%I64d\n",ans);
    }
}
