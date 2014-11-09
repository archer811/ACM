#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int c1,c2,c3,c4,n,m;
int main()
{
    int i,j,k;
    while(scanf("%d%d%d%d",&c1,&c2,&c3,&c4)!=EOF)
    {
        scanf("%d%d",&n,&m);
        int ans=0;
        int gg=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            int tmp = c1*j;
            tmp = min(tmp,c2);
            //cout<<j<<" ** "<<tmp<<endl;
            gg += tmp;
        }
        if(gg>c3)gg=c3;
        ans += gg;
        gg = 0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            int tmp = c1*j;
            tmp = min(tmp,c2);
           // cout<<j<<" "<<tmp<<endl;
            gg += tmp;
        }
        if(gg>c3)gg=c3;
        ans += gg;
        if(ans>c4)ans=c4;
        cout<<ans<<endl;
    }
}
