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
int n;
char s[2005][2005];
int v[2005];
int flag=0;
void dfs(int x,int r)
{
    if(flag)return;
    v[x]=1;
    for(int y=0; y<n; y++)
    {
        if(s[x][y]=='1')
        {
            if(!v[y])
            {
                dfs(y,x);
            }
            else if(r!=-1&&s[y][r]=='1')
            {
                flag=1;
            }
        }
    }
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        gets(*s);
        flag=0;
        for(i=0; i<n; i++)
            //scanf("%s",s[i]);
            gets(s[i]);
        memset(v,0,sizeof(v));
        printf("Case #%d: ",++cas);
        for(i=0; i<n; i++)
        {
            if(!v[i])
                dfs(i,-1);
        }

        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}
