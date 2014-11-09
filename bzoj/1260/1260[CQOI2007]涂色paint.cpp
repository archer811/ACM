#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[105];
int vis[105][105];
const int inf = 0x3fffffff;
int dfs(int x,int y)
{
    if(vis[x][y]!=-1)return vis[x][y];
    if(x>y)return vis[x][y]=0;
    if(x==y)return vis[x][y]=1;
    int ans = inf;
    int l=x,r=y;
    while(s[l]==s[y]&&l<=y)
        l++;
    while(s[r]==s[x]&&r>=l&&r>=x)
        r--;
    if(l==x&&r==y)ans=inf;
    else
    ans = min(ans,1+dfs(l,r));

    for(int i=x;i<y;i++)
    {
        ans = min(ans,dfs(x,i)+dfs(i+1,y));
    }
//    if(s[x]==s[y])
//    {
//        for(int i=x+1;i<y;i++)
//            ans = min(ans,dfs(x,i)+dfs(i+1,y-1));
//    }
    return vis[x][y]=ans;
}
int main()
{
    int i,j,k;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        memset(vis,-1,sizeof(vis));
        printf("%d\n",dfs(0,len-1));
    }
}
