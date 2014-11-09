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
struct O
{
    int a,x;
} g[1005],g2[1005];
int cmp1(O a,O b)
{
    return a.a<b.a;
}
int cmp2(O a,O b)
{
    return a.a>b.a;
}
int d[1005],d2[1005],Max[1005],Max2[1005];
int num[1005],num2[1005],Num[1005],Num2[1005];
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int k=0,k2=0;
        for(i=0; i<m; i++)
        {
            int s;
            scanf("%d",&s);
            if(s==1)scanf("%d%d",&g[k].a,&g[k].x),k++;
            else scanf("%d%d",&g2[k2].a,&g2[k2].x),k2++;
        }
        sort(g,g+k,cmp1);
        sort(g2,g2+k2,cmp2);
        memset(d,-1,sizeof(d));
        memset(d2,-1,sizeof(d2));
        memset(Max,-1,sizeof(Max));
        memset(Max2,-1,sizeof(Max2));
        memset(N,0x3f,sizeof(N));
        memset(num,0x3f,sizeof(num));
        memset(num2,0x3f,sizeof(num2));
        memset(Num2,0x3f,sizeof(Num2));
        Max[0]=0;
        N[0]=0;
        for(i=0;i<k;i++)
        {
            for(j=g[i].x;j<=g[i].a;j++)
            {
                //d[j]=max(d[j],Max[j-g[i].x]+g[i].x);
                if(Max[j-g[i].x]==-1)continue;
                if(d[j]<Max[j-g[i].x]+g[i].x)
                {
                    d[j]=Max[j-g[i].x]+g[i].x;
                    num[j]=N[j-g[i].x]+1;
                }
                else if(d[j]==Max[j-g[i].x]+g[i].x && num[j]>N[j-g[i].x]+1)
                {
                    num[j]=N[j-g[i].x]+1;
                }
            }
            for(j=1;j<=n;j++)
            {
                if(Max[j]<d[j])
                {
                    Max[j]=d[j];
                    N[j]=num[j];
                }
                else if(Max[j]==d[j]&&N[j]>num[j])
                {
                    N[j]=num[j];
                }

                if(Max[j]<Max[j-1])
                {
                    Max[j]=Max[j-1];
                    N[j]=N[j-1];
                }
                else if(Max[j]==Max[j-1] && N[j]>N[j-1])
                {
                    N[j]=N[j-1];
                }
                //Max[j]=max(Max[j],Max[j-1]);
            }
        }
//        for(i=0;i<=n;i++)
//            cout<<i<<"()"<<d[i]<<endl;


        Max2[n+1]=0;
        Num2[n+1]=0;
        for(i=0;i<k2;i++)
        {
            for(j=n-g2[i].x+1;j>=g2[i].a;j--)
            {
                //d2[j]=max(d2[j],Max[j+g2[i].x]+g2[i].x);
                if(Max2[j+g2[i].x]==-1)continue;
                if(d2[j]<Max2[j+g2[i].x]+g2[i].x)
                {
                    d2[j]=Max2[j+g2[i].x]+g2[i].x;
                    num2[j]=Num2[j+g2[i].x]+1;
                }
                else if(d2[j]==Max2[j+g2[i].x]+g2[i].x && num2[j]>Num2[j+g2[i].x]+1)
                {
                    num2[j]=Num2[j+g2[i].x]+1;
                }
            }
            for(j=n;j>=1;j--)
            {
                if(Max2[j]<d2[j])
                {
                    Max2[j]=d2[j];
                    Num2[j]=num2[j];
                }
                else if(Max2[j]==d2[j] && Num2[j]>num2[j])
                {
                    Num2[j]=num2[j];
                }

                if(Max2[j]<Max2[j+1])
                {
                    Max2[j]=Max2[j+1];
                    Num2[j]=Num2[j+1];
                }
                else if(Max2[j]==Max2[j+1] && Num2[j]>Num2[j+1])
                {
                    Num2[j]=Num2[j+1];
                }
               // Max[j]=max(Max[j],Max[j+1]);
            }
        }
        int ans=0,ans2=0;
        for(i=1;i<n;i++)
        {
            //cout<<Max[i]<<" "<<Max2[i+1]<<" "<<N[i]<<" "<<Num2[i+1]<<endl;
            if(Max[i]+Max2[i+1]>ans)
            {
                ans=Max[i]+Max2[i+1];
                ans2=N[i]+Num2[i+1];
            }
            else if(Max[i]+Max2[i+1]==ans && ans2>N[i]+Num2[i+1])
            {
                ans2=N[i]+Num2[i+1];
            }
        }
        printf("Case %d: %d %d\n",++cas,ans,ans2);
    }
    return 0;
}

