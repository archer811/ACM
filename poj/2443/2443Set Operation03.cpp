#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int f[10005][32];
int main()
{
    int i,j,k,m,a,b,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            int s = i/32;
            int t = i%32;
            for(j=1;j<=m;j++)
            {
                scanf("%d",&k);
                f[k][s]|=(1<<t);
            }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            bool flag = false;
            for(i=0;i<32;i++)
            {
                if(f[a][i]&f[b][i]){flag=true;printf("Yes\n");break;}
//                else
            }
            if(flag==false)puts("No");
        }
    }
}
