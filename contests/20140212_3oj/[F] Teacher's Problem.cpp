#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
char s[100005][11];
int a[100005];
int n;
int word[1000006];
int sz;
int ch[1000005][26];
int head[100005];
int f[100005];
struct array
{
    int to,next;
} edge[4000005];
int tot;
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u)
{
    int i,j;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
        a[u]+=a[v];
    }
}
void init()
{
    sz=1;
    memset(ch[0],0,sizeof(ch[0]));
}
void insert(char *s,int v)
{
    int len = strlen(s),i,j;
    int p=0;
    for(i=0; i<len; i++)
    {
        j = s[i]-'a';
        if(ch[p][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            word[sz]=0;
            ch[p][j]=sz++;
        }
        p = ch[p][j];
    }
    word[p]=v;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=1; i<=n; i++)
        {
            scanf("%s",s[i]);
            insert(s[i],i);
            f[i]=0;
        }
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=n; i++)
        {
            int len = strlen(s[i]);
            int tmp=-1;
            int p=0;
            for(j=0; j<len; j++)
            {
                p = ch[p][s[i][j]-'a'];
                if(word[p]==i)continue;
                int gg=word[p];
                if(gg==0)continue;

                if(gg>tmp)tmp=gg;

            }
            if(tmp==-1)
            {
                f[i]=1;
                continue;
            }
            if(tmp==i)continue;
            add(tmp,i);
            //cout<<tmp<<" "<<i<<endl;
        }
        for(i=1; i<=n; i++)
        {
            if(f[i])dfs(i);
        }
        for(i=1; i<=n; i++)
        {
            if(i==1)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        puts("");
    }
}
