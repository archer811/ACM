#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
struct array
{
    int x,y;
}s[1005],e[1005];
int cmp(array a,array b)
{
    return a.x<b.x;
}
int vis[1005];
int ans[1005];
int main()
{
    int i,j,n;
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            s[i].x=a;s[i].y=i;
            e[i].x=b;e[i].y=i;
        }
        sort(s+1,s+1+n,cmp);
        sort(e+1,e+1+n,cmp);
//        for(i=1;i<=n;i++)
//            cout<<e[i].x<<" "<<e[i].y<<endl;
        int k=0;
        j=1;
        for(i=1;i<=n;i++)
        {
            if(vis[e[i].y]==0)
            {
                //cout<<i<<" $ "<<endl;
                vis[e[i].y]=1;
                ans[k++]=e[i].x;
                while(s[j].x<=e[i].x&&j<=n)
                {
//                    cout<<i<<" "<<s[j].x<<" "<<e[i].x<<
//                    " "<<s[j].y<<endl;
                    //cout<<s[j].y<<"$%%%"<<vis[1]<<endl;
                    vis[s[j].y]=1;j++;
                }
            }
        }
        cout<<k<<endl;
        for(i=0;i<k;i++)
            cout<<ans[i]<<" ";
    }
}
