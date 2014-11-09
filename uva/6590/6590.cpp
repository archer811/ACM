#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
const int maxn = 30;
struct
{
    int to,next;
}edge[30*30*2];
int head[maxn],stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top,tot;
void add(int x,int y)
{
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
void tarjan(int u)
{
    int i,j,t;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        j=edge[i].to;
        if(!dfn[j])
        {
            tarjan(j);
            if(low[u]>low[j])
               low[u]=low[j];
        }
        else if(instack[j]&&dfn[j]<low[u])
            low[u]=dfn[j];
    }
    if(dfn[u]==low[u])
    {
        scnt++;
        do
        {
            t=stack[--top];
            instack[t]=0;
            belong[t]=scnt;
        }while(t!=u);
    }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=0;i<26;i++)
      if(!dfn[i])
        tarjan(i);
}

int v[27][27];
char s[2];
int in[27];
int ans[22];
queue<int>q;
int b[27];
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(v,0,sizeof(v));
        memset(b,0,sizeof(b));
        int k=-1;
        int ant=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            v[s[0]-'a'][s[1]-'a']=1;
        }
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                if(v[i][j]==0)
                    add(i,j);
            }
        }
        solve();
        for(i=0;i<26;i++)
        {
            //cout<<belong[i]<<"()"<<b[1]<<endl;
            b[belong[i]]++;
        }
        for(i=1;i<=scnt;i++)
        {
            //cout<<i<<" "<<b[i]<<endl;
            if(b[i]>1)
            {
                k=i;break;
            }
        }
        //cout<<k<<endl;
        if(k!=-1)
        {
            for(i=0;i<26;i++)
            {
                if(belong[i]==k)
                {
                    ans[ant++]=i;
                    break;
                }
            }
            for(i=1;i<20;i++)
            {
                for(j=0;j<26;j++)
                {
                    if(v[ans[ant-1]][j]==0)
                    {
                        ans[ant++]=j;
                        break;
                    }
                }
            }
        }
        else
        {

        }
    }
    return 0;
}
