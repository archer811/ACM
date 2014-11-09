#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct array
{
    int x,y;
}ans[205];
int cmp(array a,array y)
{
    if(a.x==y.x)return a.y<y.y;
    return a.x<y.x;
}
int main()
{
    int i,j,k,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ans[i].x),ans[i].y=1;
        for(i=n+1;i<=n+m;i++)
            scanf("%d",&ans[i].x),ans[i].y=2;
        sort(ans+1,ans+1+n+m,cmp);
//        for(i=1;i<=n+m;i++)
//            cout<<ans[i].x<<" "<<ans[i].y<<endl;
        int flag=0;
        int ant;
        for(i=1;i<=n;i++)
            if(ans[i].y!=1)flag=1;
        if(flag==0&&ans[1].x*2<ans[n+1].x&&ans[n+1].x>ans[n].x)
        {
            printf("%d\n",max(ans[1].x*2,ans[n].x));
        }
        else puts("-1");
    }
}
