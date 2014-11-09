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
const int maxn = 100005;
struct array
{
    int s,t;
}now;
vector<array>g[maxn];
int a[maxn],b[maxn];
int num[maxn],v[maxn];
int s[maxn];
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int m = unique(b,b+n)-b;
        for(i=0;i<m;i++)
            g[i].clear();
        a[n]=-1;
        int pre=0;
        int ans=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                now.s=pre;now.t=i-1;
                if(i-pre>ans)
                    ans=i-pre;
                int tmp=lower_bound(b,b+m,a[i-1])-b;
                g[tmp].push_back(now);
                pre=i;
            }
        }
        for(i=0;i<m;i++)
        {
            int sum=0;
            int o=g[i].size();
            v[0]=0;
            num[0]=0;
            for(j=0;j<g[i].size();j++)
            {
                num[j+1]=num[j]+g[i][j].t-g[i][j].s+1;
                if(j>=1)
                    v[j]=g[i][j].s-g[i][j-1].t-1+v[j-1];
            }
            int l=0;
            for(j=1;j<o;j++)
            {
                while(v[j]-v[l]>k)
                {
                    l++;
                }
                //cout<<i<<" "<<j<<" "<<l<< " "<<num[j+1]<<" "<<num[l]<<endl;
                ans=max(ans,num[j+1]-num[l]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
