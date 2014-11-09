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
ll d[1505][1505];
int main()
{
    ll i,j;
    int g;
    scanf("%d",&g);
    int cas=0;
    while(g--)
    {
        int n;
        ll x,y,z,t;
        scanf("%d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
        memset(d,0,sizeof(d));
        d[0][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i-j-1>=0)
                d[i][j]=max(d[i][j],d[i-1][j]+y*(i-j-1)*(t+j*z));

                if(j-1>=0)
                d[i][j]=max(d[i][j],d[i-1][j-1]+y*(i-j)*(t+(j-1)*z));
            }
        }

        ll ans=0;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=i;j++)
            {
                ll tmp = d[i][j];
                tmp = tmp+(t+j*z)*((n-i)*(x+(i-j)*y));
                if(ans<tmp)ans=tmp;
                //cout<<i<<" "<<j<<" "<<d[i][j]<<" "<<tmp<<endl;
            }
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}
