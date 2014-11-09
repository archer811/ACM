#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
ll a[3005],b[3005],c[3005];
ll d[3005][2][2];
ll max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            cin>>b[i];
        for(i=1;i<=n;i++)
            cin>>c[i];
        memset(d,-1,sizeof(d));
        d[1][0][0]=a[1];
        d[1][0][1]=b[1];
        for(i=2;i<=n;i++)
        {
            d[i][0][0]=max(d[i-1][0][1],d[i-1][1][1])+a[i];
            d[i][0][1]=max(d[i-1][0][1],d[i-1][1][1])+b[i];
            d[i][1][0]=max(d[i-1][0][0],d[i-1][1][0])+b[i];
            d[i][1][1]=max(d[i-1][0][0],d[i-1][1][0])+c[i];
        }
       cout<<max(d[n][0][0],d[n][1][0])<<endl;
    }
}
