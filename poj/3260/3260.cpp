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
int n,T;
int v[105];
int V;
int f[100000],c[105],f2[100000];
void zeroOnepack(int cost,int weight)
{
    int i;
    for(i=V;i>=cost;i--)
        f[i]=min(f[i],f[i-cost]+weight);
}
void completepack(int cost,int weight)
{
    int i;
    for(i=cost;i<=V;i++)
        f[i]=min(f[i],f[i-cost]+weight);
}
void completepack2(int cost,int weight)
{
    int i;
    for(i=cost;i<=V;i++)
        f2[i]=min(f2[i],f2[i-cost]+weight);
}
void multiplepack(int cost,int weight,int amount)
{
    if(cost*amount>=V)
        completepack(cost,weight);
    else
    {
        int k =1;
        while(k<amount)
        {
            zeroOnepack(cost*k,weight*k);
            amount=amount-k;
            k*=2;
        }
        zeroOnepack(amount*cost,amount*weight);
    }
}
const int inf  = 0x3fffffff;
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        V=100000;
        memset(f,0x3f,sizeof(f));
        memset(f2,0x3f,sizeof(f2));
        f[0]=0;
        f2[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            completepack2(v[i],1);
        }
//        for(i=1;i<=10;i++)
//            cout<<f2[i]<<" ";
//        cout<<endl;

        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            multiplepack(v[i],1,c[i]);
        }
        int ans=inf;
        for(i=T;i<=V;i++)
        {
            int x = f[i];
            int y = f2[i-T];
            if(x<V&&y<V)
            {
                ans = min(ans,x+y);
            }
        }
        if(ans==inf)ans=-1;
        printf("%d\n",ans);

    }
    return 0;
}
