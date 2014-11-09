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
#include<iostream>
#include<stack>
const int MAXN=111;
using namespace std;
const int maxn = 150+5;
int in[maxn];
int g[maxn][maxn];
int fa[maxn];
stack<int>S;
int n,m;

void dfs(int x)
{
    S.push(x);
    for(int i=1; i<=n; i++)
    {
        if(g[x][i]>0)
        {
            g[i][x]=g[x][i]=0;//删除此边
            dfs(i);
            break;
        }
    }
}

//Fleury算法的实现
void Fleury(int x)
{
    S.push(x);
    int flag=0;
    int g2=0;
    while(!S.empty())
    {
        int b=0;
        for(int i=1; i<=n; i++)
        {
            if(g[S.top()][i]>0)
            {
                b=1;
                break;
            }
        }
        if(b==0)
        {

            g2++;
            if(g2<=n)
            {
                if(flag)printf(" ");
                flag=1;
                printf("%d",S.top());
            }

            S.pop();
        }
        else
        {
            int y=S.top();
            S.pop();
            dfs(y);//如果有，就dfs
        }
    }
    printf("\n");
}

int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void add(int u,int v)
{
    int x = find(u);
    int y = find(v);
    if(x!=y)
        fa[y]=x;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,0,sizeof(g));
        for(i=1; i<=n; i++)
            in[i]=0,fa[i]=i;
        for(i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(g[a][b]==0)
            {
                g[a][b]=1;
                g[b][a]=1;
                in[a]++;
                in[b]++;
                add(a,b);
            }
        }
        int flag=0;
        for(i=1; i<=n; i++)
        {
            find(i);
            if(fa[i]!=fa[1])
            {
                flag=1;
                break;
            }
            if(in[i]&1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            puts("no solution");
            continue;
        }
        Fleury(1);
    }
    return 0;
}
