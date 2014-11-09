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
int a[1000005];
int b[1000006];
int vis[1000005];
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        int flag=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>=n){flag=1;continue;}
            b[a[i]]++;
        }
        printf("Case %d: ",++cas);
        if(flag)
        {
            puts("no");
            continue;
        }

        for(i=0; i<n; i++)
        {
            if(b[i]+b[n-i-1]!=2){flag=1;break;}

        }

        if (flag==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
