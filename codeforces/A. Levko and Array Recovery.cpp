#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 5005;
int n,m;
int a[maxn],vis[maxn];
int t[maxn],L[maxn],R[maxn],d[maxn];
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            a[i]=1e9,vis[i]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&t[i],&L[i],&R[i],&d[i]);
            if(t[i]==1)
            {
                for(j=L[i];j<=R[i];j++)
                    a[j]+=d[i];
            }
            else
            {
                for(j=L[i];j<=R[i];j++)
                {
                    a[j]=min(a[j],d[i]);
                }
            }
        }
        for(i=m;i>=1;i--)
        {
            if(t[i]==1)
            {
                //cout<<i<<" fdsaf "<<L[i]<<" "<<d[i]<<endl;
                for(j=L[i];j<=R[i];j++)
                    a[j]-=d[i];
            }
            else
            {
                int flag=0;
                for(j=L[i];j<=R[i];j++)
                {
                   if(a[j]==d[i])
                   {
                       flag=1;
                        vis[j]=1;
                        break;
                   }
                }
                if(flag==0)
                {
                    puts("NO");return 0;
                }
            }
        }
        puts("YES");
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
}
