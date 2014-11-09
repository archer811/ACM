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
#define ll __int64
ll a[1000005];
ll d[1000005][2];
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        int M=-1;
        for(j=0;j<n;j++)
        {
            int k;
            scanf("%d",&k);
            if(k>M)M=k;
            a[k]++;
        }
        for(i=0;i<=M+1;i++)
        {
            ll tmp=0;
            if(i>=1)
                tmp = max(d[i-1][0],d[i-1][1]);
                //cout<<tmp<<"()"<<endl;
            d[i][0]=tmp;


            tmp=0;
            if(i>=1)
                tmp = d[i-1][0];
            else tmp=0;
            if(i>=2)
                tmp = max(tmp,d[i-2][0]),tmp = max(tmp,d[i-2][1]);
                //cout<<i<<"*"<<tmp<<endl;
            if(a[i])
                d[i][1]=tmp+i*a[i];
            else
                d[i][1]=tmp;
        }
        ll ans=-1;
        for(i=0;i<=M+1;i++)
        {
            if(d[i][0]>ans)ans=d[i][0];
            if(d[i][1]>ans)ans=d[i][1];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
