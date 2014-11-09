#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const ll mod = 1000000007;
int mark[1035];
int k;
int a[12];
int judge(int x,int K)
{
    int i,j;

    for(i=0; i<K; i++)
        a[i]=((x&(1<<i))>0);
    j = K-1;
    i = 0;
    while(i<j)
    {
        if(a[i]!=a[j])return 1;//buduicheng
        i++;
        j--;
    }
    return 0;
}
ll d[406][1035];
int f[(1<<11)+5][2];
int mark2[(1<<11)+5];
int ff(int x,int num)
{
    int i,j;

    for(i=0; i<k; i++)
        a[i]=((x&(1<<i))>0?1:0);
    int sum =0;
    j =0;
    for(i=1; i<k; i++)
    {
        if(a[i])
            sum = sum + (1<<j);
        j ++;
    }
    if(num==0)return sum;
    return sum + (1<<j);
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int g = 1<<k;
        memset(d,0,sizeof(d));
        for(i=0; i<g; i++)
        {
            mark[i]=judge(i,k);
            f[i][0]=ff(i,0);
            f[i][1]=ff(i,1);
        }
        for(i=0; i<(1<<(k+1)); i++)
        {
            mark2[i]=judge(i,k+1);
        }
        if(k>n)
        {
            ll ans = 1;
            for(i=1; i<=n; i++)
            {
                ans = ans*(ll)2%mod;
            }
            printf("%lld\n",ans);
            continue;
        }
        for(i=0; i<g; i++)
        {
            d[k][i]=mark[i];
        }
        for(i=k+1; i<=n; i++)
        {
            for(j=0; j<g; j++)
            {

                int sta=j<<1;
                int sta1=(sta&((1<<k)-1));
                if (mark2[sta]&&mark[sta1])
                {
                    d[i][sta1] = (d[i][sta1]+d[i-1][j])%mod;
                }
                sta=(j<<1)+1;
                sta1=(sta&((1<<k)-1));
                if (mark2[sta]&&mark[sta1])
                {
                    d[i][sta1] = (d[i][sta1]+d[i-1][j])%mod;
                }
            }
        }
        ll sum=0;
        for(i=0; i<g; i++)
        {
            sum = (sum+d[n][i])%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
