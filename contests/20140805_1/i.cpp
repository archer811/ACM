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
#define ll long long
const ll mod = 1000000007;
const int maxn = 1000006;
int f[maxn],vis[maxn],mark[maxn],num[maxn];
int main()
{
    int i,j;
    int n,m,x;
    while(scanf("%d%d%d",&n,&m,&x)!=EOF)
    {
        int k=1;
        for(i=2;i<=n;i+=2)
        {
            f[k]=i;
            vis[i]=0;
            k++;
        }
        for(i=1;i<=n;i+=2)
        {
            f[k]=i;
            vis[i]=0;
            k++;
        }
        int M=1;
        for(i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;
            int sum=1;
            mark[i]=M;
            int t=i;
            while(vis[f[t]]==0)
            {
                vis[f[t]]=1;
                mark[f[t]]=M;
                t=f[t];
                sum++;
            }
            num[M]=sum;
            M++;
        }
        for(i=1;i<=x;i++)
        {
            int tmp = m%num[mark[i]];
            //cout<<m<<"   "<<num[mark[i]]<<"  "<<tmp<<endl;
            int k=i;
            for(j=0;j<tmp;j++)
            {
                k=f[k];
            }
            if(i==1)printf("%d",k);
            else printf(" %d",k);
        }
        puts("");
    }
    return 0;
}
