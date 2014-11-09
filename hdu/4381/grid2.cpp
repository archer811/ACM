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
const int maxn = 2005;
int dl[maxn],dr[maxn];
struct O
{
    int a,x;
} g[maxn],g2[maxn];
int cmp1(O a,O b)
{
    return a.a<b.a;
}
int cmp2(O a,O b)
{
    return a.a>b.a;
}
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(dl,0x3f,sizeof(dl));
        memset(dr,0x3f,sizeof(dr));
        int k=0,k2=0;
        while(m--)
        {
            int s;
            scanf("%d",&s);
            if(s==1)
            {
                scanf("%d%d",&g[k].a,&g[k].x);
                k++;
            }
            else
            {
                scanf("%d%d",&g2[k2].a,&g2[k2].x);
                k2++;
            }
        }
        sort(g,g+k,cmp1);
        sort(g2,g2+k2,cmp2);
        dl[0]=0;
        dr[n+1]=0;
        int inf = n+1;
        for(i=0; i<k; i++)
        {
            for(j=g[i].a; j>=g[i].x; j--)
            {
                if(dl[j-g[i].x]<inf)
                {
                    //cout<<j<<" "<<dl[j-g[i].x]<<endl;
                    dl[j]=min(dl[j],dl[j-g[i].x]+1);
                }
            }
        }
        for(i=0; i<k2; i++)
        {
            for(j=g2[i].a; j<=n-g2[i].x+1; j++)
            {
                if(dr[j+g2[i].x]<inf)
                {
                    //cout<<j+g[i].x<<"**"<<dr[j+g[i].x]<<endl;
                    dr[j]=min(dr[j],dr[j+g2[i].x]+1);
                    //cout<<j<<"!"<<dr[j]<<endl;
                }

            }
        }
        int ans=0,ans2=0;

        for(i=1; i<=n; i++)
        {
            int tmp = dl[i];
            if(tmp<inf)
            {
                if(i>ans)
                {
                    ans=i;
                    ans2=tmp;
                }
                else if(i==ans&&ans2>tmp)
                    ans2=tmp;
            }
            tmp = dr[i];
            if(tmp<inf)
            {
                if(n-i+1>ans)
                {
                    ans=n-i+1;
                    ans2=tmp;
                }
                else if(n-i+1==ans&&ans2>tmp)
                    ans2=tmp;
            }
            for(j=i+1; j<=n; j++)
            {
                tmp = dl[i]+dr[j];
                //cout<<i<<" "<<j<<" "<<n-j+1<<" "<<tmp<<endl;
                if(tmp<inf)
                {
                    if(i+n-j+1>ans)
                    {
                        ans=i+n-j+1;
                        ans2=tmp;
                    }
                    else if(i+n-j+1==ans&&ans2>tmp)
                        ans2=tmp;
                }
            }
        }
        printf("Case %d: %d %d\n",++cas,ans,ans2);
    }
    return 0;
}

