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
struct array
{
    int c,p,index;
} s[1005];
int cmp(array x,array y)
{
    if(x.p==y.p)return x.c<y.c;
    return x.p>y.p;
}
struct ao
{
    int x,y;
}r[1005];
int cmp2(ao a,ao b)
{
    return a.x<b.x;
}
vector<ao>ans;
int vis[1005];
int main()
{
    int i,j,n,k;
    while(cin>>n)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&s[i].c,&s[i].p);
            s[i].index=i;
        }
        sort(s+1,s+1+n,cmp);
        cin>>k;
        for(i=1; i<=k; i++)
        {
            scanf("%d",&r[i].x);
            r[i].y=i;
        }
        sort(r+1,r+1+k,cmp2);
        int sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(vis[j])continue;
                if(r[j].x>=s[i].c)
                {
                    vis[j]=1;
                    sum+=s[i].p;
                    ao now;
                    now.x=s[i].index;now.y=r[j].y;
                    ans.push_back(now);break;
                }
            }
        }
        printf("%d %d\n",ans.size(),sum);
        for(i=0;i<ans.size();i++)
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
}
