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
int g[55][55];
double d[10005][55];
int num[55];
double ans[55];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,D;
        scanf("%d%d%d",&n,&m,&D);
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j])num[i]++;
            }
        }
        for(i=1;i<=n;i++)
        {
            memset(d,0,sizeof(d));
            for(j=1;j<=n;j++)
                d[0][j]=1.0/(n);
            for(j=1;j<=D;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(k==i)continue;
                    double sum=0;
                    for(int s=1;s<=n;s++)
                    {
                        if(s==i)continue;
                        if(g[s][k])sum+=d[j-1][s]*1.0/num[k];
                    }
                    //cout<<i<<" "<<j<<"  "<<sum<<endl;
                    d[j][k]+=sum;
                }
            }
            double sum=0;
            for(j=1;j<=n;j++)
            {
                sum += d[D][j];
            }
            ans[i]=sum;
            //cout<<i<<"  "<<sum<<endl;
        }
        for(i=1;i<=n;i++)
        {
            printf("%.10f\n",ans[i]);
        }
    }
    return 0;
}
