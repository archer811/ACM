#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int mp[5010][5010];
int n, oper;
bool flag;
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
bool logic(int x,int y)
{
    return 1<=x&&x<=n&&1<=y&&y<=n;
}
void bfs(int x,int y)
{
    if(mp[x][y]==2)return;
    mp[x][y] = 1;
    queue<int>q;
    if(x == 1 && mp[x][y] != 2)q.push(100000*x+y), mp[x][y] = 2;
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(logic(x1,y1)&&mp[x1][y1]==2)
            {
                q.push(100000*x+y), mp[x][y] = 2;
                break;
            }
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int x1=u/100000;
        int y1=u%100000;
        if(x1==n)flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int x2=x1+dx[i];
            int y2=y1+dy[i];
            if(logic(x2,y2)&&mp[x2][y2]== 1)
                q.push(100000*x2+y2),mp[x2][y2]=2;
        }
    }
}
int main()
{
    while(scanf("%d %d", &n, &oper)!=EOF)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
               mp[i][j] = 0;
        flag = false;
        char op[10];
        while(oper--)
        {
            scanf("%s",op);
            if(op[0]== 'C')printf("%d\n", flag);
            else
            {
                int x, y;
                scanf("%d %d",&x,&y);
                if(op[0]=='O')bfs(x,y);
                else printf("%d\n", mp[x][y]==2);
            }

        }
    }
    return 0;
}
