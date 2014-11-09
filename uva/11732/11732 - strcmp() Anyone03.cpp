#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
const int nodenum = 4105005;
struct array
{
    int to,next,num;
}edge[nodenum];
int sz;
int head[nodenum];
int val[nodenum];
int ceng[nodenum];
int n;
int tot;
ll sum;
void add(int u,int v,int t)
{
    edge[tot].to=v;
    edge[tot].num=t;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int inx(char s)
{
    if(s>='a'&&s<='z')return s-'a';
    else if(s>='A'&&s<='Z')return 26+s-'A';
    else if(s=='#')return 62;
    else return 52+s-'0';
}
void insert(char *s)
{
    int len = strlen(s);
    s[len]= '#';
    len++;
    int  u = 0;
    int i,j;
    for(i=0;i<len;i++)
    {
        int v = inx(s[i]),t=-1;
        //cout<<u<<"*"<<head[u]<<endl;
        for(j=head[u];j!=-1;j=edge[j].next)
        {
            int g = edge[j].num;
            //cout<<u<<"        "<<g<<endl;
            if(g==v)
            {
                t = edge[j].to;break;
            }
        }
        if(t==-1)
        {
            t = sz++;
            //cout<<t<<" "<<v<<endl;
            ceng[t] = ceng[u]+1;
            add(u,t,v);
        }
        val[t]++;
        u=t;
    }
}
void dfs(int u)
{
    ll sum1 = 0;
    int i,j;
    ll tmp = ceng[u]*2+1;

    for(i=head[u];i!=-1;i=edge[i].next)
    {
        j = edge[i].to;
        sum1 += val[j];
    }//cout<<u<<" * "<<tmp<<" "<<sum1<<endl;
    if(sum1==0)
    {
        if(val[u]>=2)
        {
             sum += (tmp-1)*val[u]*(val[u]-1);
        }

    }
    else
    {
        //cout<<sum1<<endl;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            j = edge[i].to;
            sum += val[j]*(sum1-val[j])*tmp;
            dfs(j);
        }
    }
}
char s[1005];
int main()
{
    int i,j,n;
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        sz  = 1;
        tot = 0;
        memset(head,-1,sizeof(head));
        memset(val,0,sizeof(val));
        memset(ceng,0,sizeof(ceng));
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        //dfs1(0);
        sum = 0;
        dfs(0);

        printf("Case %d: %lld\n",++cas,sum/2);
    }
}
