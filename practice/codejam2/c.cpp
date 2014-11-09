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
int a[60],b[60],k[60];
int x[33];
#define ll long long
ll dfs(int index,int l,int r)
{
    if(index==-1)return 0;
    int a0,a1,b0,b1;
    if(l==a[index])a0=1,a1=0;
    else
    {
        a0=x[index];
        a1=1;
    }

    if(r==b[index])b0=1,b1=0;
    else
    {
        b0=x[index];
        b1=1;
    }
    ll sum=0;

    if(k[index]==0)
    {

        if(a[index]==0&&b[index]==0)
        {
            sum += dfs(index-1,0,0);
        }
        else if(a[index]==0&&b[index]==1)
        {
            sum += dfs(index-1,0,0);
            sum += dfs(index-1,0,1);
        }
        else if(a[index]==1&&b[index]==0)
        {
            sum += dfs(index-1,0,0);
            sum += dfs(index-1,1,0);
        }
        else
        {
            sum += dfs(index-1,0,0);
            sum += dfs(index-1,0,1);
            sum += dfs(index-1,1,0);
        }
    }
    else
    {
        sum += a0*b0;
        sum += a0*b1;
        sum += a1*b0;
        if(a[index]==1&&b[index]==1)
        sum += dfs(index-1,1,1);
    }
//    cout<<a0<< " "<<a1<<" "<<b0<<" "<<b1<<endl;
//    cout<<index<<" "<<k[index]<<" "<<l<<" "<<r<<" "<<sum<<endl;
    return sum;
}
int main()
{
    int i,j,t;
    x[0]=1;
    for(i=1; i<=30; i++)
        x[i]=x[i-1]*2;
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    scanf("%d",&t);
    int A,B,K;
    int cas=0;
    while(t--)
    {
        scanf("%d%d%d",&A,&B,&K);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(k,0,sizeof(k));
        j=0;
        while(A)
        {
            a[j++]=A%2;
            A/=2;
        }
        j=0;
        while(B)
        {
            b[j++]=B%2;
            B/=2;
        }
        j=0;
        while(K)
        {
            k[j++]=K%2;
            K/=2;
        }

        for(i=0; i<30; i++)
            cout<<a[i];
        cout<<endl;
        for(i=0; i<30; i++)
            cout<<b[i];
        cout<<endl;
        for(i=0; i<30; i++)
            cout<<k[i];
        cout<<endl;

        ll ans = dfs(29,a[29],b[29]);
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
