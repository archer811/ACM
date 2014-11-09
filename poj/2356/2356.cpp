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
const int maxn = 10006;
int a[maxn];
int pre[maxn];
int vis[maxn];
int b[maxn],c[maxn],v[maxn];
vector<int>ans;
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(pre,-1,sizeof(pre));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int k=0;
        b[k++]=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            int k2=0;
            for(j=0;j<k;j++)
            {
                int tp = (b[j]+a[i])%n;
                if(vis[tp]==0)
                {
                    vis[tp]=1;

                    //cout<<tp<<" * "<<b[j]<<endl;
                    c[k2++]=tp;
                }
                if(pre[tp]==-1)
                {
                    pre[tp]=b[j];
                    v[tp]=a[i];
                }
            }
            for(j=0;j<k2;j++)
                b[k++]=c[j];
        }
        ans.clear();
        int o=0;
        int f=0;
        while(pre[o]!=-1)
        {
            ans.push_back(v[o]);
            o=pre[o];
            if(o==0)break;
        }
        printf("%d\n",ans.size());
        for(i=0;i<ans.size();i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

