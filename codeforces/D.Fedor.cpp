#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;
#define ll __int64
map<string,int>M;
int tot2;
struct O
{
    int num,id;
    ll len;
}g[200005];
int a[200005],Num[200005],Len[200005];
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void func(string &x,int len)
{
    for(int i=0;i<len;i++)
    {
        if(x[i]>='A'&&x[i]<='Z')
            x[i]^=32;
    }
}
int calc(string x,int len)
{
    int s=0;
    for(int i=0;i<len;i++)
    {
        if(x[i]=='r')s++;
    }
    return s;
}
int cmp(O x, O y)
{
    if(x.num==y.num)return x.len<y.len;
    return x.num<y.num;
}
int d[200005],d2[200005];
void dfs(int x,int a,int b)
{

    if(d[x]==-1 || (d[x]>a) || (d[x]==a&&d2[x]>b))
    {
        //cout<<x<<" () "<<a<<"  "<<b<<endl;
        d[x]=a;
        d2[x]=b;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            //cout<<x<<"ZZZ"<<v<<endl;
            dfs(v,a,b);
        }
    }
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&m)!=EOF)
    {
        M.clear();
        tot2 = 1;
        string s;
        int k=0;
        for(i=1;i<=m;i++)
        {
            cin>>s;
            int len=s.length();
            func(s,len);
            if(M[s]==0)
            {
                M[s]=tot2++;
                g[k].num=calc(s,len);
                Num[tot2-1]=g[k].num;
                Len[tot2-1]=len;
                g[k].len=len;
                g[k++].id=tot2-1;
            }
            a[i]=M[s];
        }
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        memset(d,-1,sizeof(d));
        tot=0;
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>s;
            int len=s.length();
            func(s,len);
            if(M[s]==0)
            {
                M[s]=tot2++;
                g[k].num=calc(s,len);
                Num[tot2-1]=g[k].num;
                Len[tot2-1]=len;
                g[k].len=len;
                g[k++].id=tot2-1;
            }
            //cout<<s<<"()"<<endl;
            a = M[s];

            cin>>s;
            len=s.length();
            func(s,len);
            if(M[s]==0)
            {
                M[s]=tot2++;
                g[k].num=calc(s,len);
                Num[tot2-1]=g[k].num;
                Len[tot2-1]=len;
                g[k].len=len;
                g[k++].id=tot2-1;
            }
            //cout<<s<<"*"<<endl;
            b = M[s];
            add(b,a);
            //cout<<b<<"*"<<a<<endl;
        }


        sort(g,g+k,cmp);
        for(i=0;i<k;i++)
            dfs(g[i].id,g[i].num,g[i].len);
        ll sum=0,sum2=0;
//        for(i=1;i<tot2;i++)
//        {
//            cout<<i<<"  "<<d[i]<<"  "<<d2[i]<<endl;
//        }
        for(i=1;i<=m;i++)
        {
            sum += d[a[i]];
            sum2 += d2[a[i]];
        }
        printf("%I64d %I64d\n",sum,sum2);
    }
    return 0;
}
