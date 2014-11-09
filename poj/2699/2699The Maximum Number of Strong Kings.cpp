#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[1000];
int a[14];
int f()
{
    int len  = strlen(s),i,j,k;
    j = 1;
    k =0;
    int flag=0;
//    cout<<"ff"<<endl;
    for(i=0; i<len; i++)
    {
        if(flag==0&&s[i]==' ')continue;
        else if(flag&&(s[i]==' '||s[i]=='\n'))
        {
            a[j++]=k;
            flag=0;
            k=0;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            flag=1;
            k = k*10+s[i]-'0';
        }
    }
    if(flag)
    {
        a[j++]=k;
    }
//    for(i=1;i<j;i++)
//        cout<<i<<" () "<<a[i]<<endl;cout<<"**"<<endl;
    return j-1;
}
#define vm 300
#define em 300000
const int inf = 0x3fffffff;
struct E
{
    int to,next,cap;
} edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c)
{
    edge[e].cap=c;
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
int sap(int s,int t,int n)
{
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int res = 0;
    int u=pre[s]=s;
    int aug = inf;
    gap[0]=n;
    while(dist[s]< n)
    {
loop:
        for(int &i=cur[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dist[u]==dist[v]+1)
            {
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==t)
                {
                    res+=aug;
                    for(u=pre[u]; v!=s; v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=inf;
                }
                goto loop;
            }
        }
        int mindist = n;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindist>dist[v])
            {
                cur[u]=i;
                mindist=dist[v];
            }
        }
        if((--gap[dist[u]])==0)
            break;
        dist[u]=mindist+1;
        gap[dist[u]]++;
        u=pre[u];
    }
    return res;
}
int gg[11][11],tot;
int id[11][11],num;
void build(int k)
{
    memset(gg,0,sizeof(gg));
    e =0;
    memset(head,-1,sizeof(head));
    int ll = tot*tot+1;
    for(int i=1; i<=tot; i++)
    {
        addedge(0,i,a[i]);
    }
    for(int i=tot+1; i<=num;i++)
        addedge(i,num+1,1);
    for(int i = 1; i<=tot; i++)
    {
        for(int j=i+1; j<=tot; j++)
        {
            if(a[i]<a[j])
            {
                addedge(i,id[i][j],1);
                gg[i][j]=1;
            }
        }
    }
    for(int i=1; i<=tot; i++)
    {
        for(int j=1+1; j<=tot; j++)
        {
            if(gg[i][j]==0)
            {
                addedge(i,id[i][j],1);
                addedge(j,id[i][j],1);
            }
        }
    }
}
int main()
{
    int i,j,k,m;
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        gets(s);

        tot = f();

        num = tot;
        for(i=1;i<=tot;i++)
        {
            for(j=i+1;j<=tot;j++)
                id[i][j]=++num;
        }
        int ans;
        //for(i=tot; i>=1; i--)
        {
            build(i);
            cout<<sap(0,num+1,num+2)<<endl;
            {
                //ans=i;break;
            }
        }
        printf("%d\n",ans);
    }
}
