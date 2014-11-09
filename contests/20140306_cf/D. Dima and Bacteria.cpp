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
int n,m,k;
const int maxn = 100005;
int mark[maxn];
int fa[maxn];
struct array
{
    int a,b,c;
}edge[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void add(int a,int b)
{
    int x = find(a),y = find(b);
    if(x!=y)
        fa[x]=y;
}
int c[maxn];
int sum[maxn];
int num[maxn];
int d[505][505];
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        j=1;
        sum[0]=0;
        for(i=1;i<=k;i++)
        {
            scanf("%d",&c[i]);
            sum[i]=sum[i-1]+c[i];
            for(int t=0;t<c[i];t++)
            {
                mark[j++]=i;
            }
        }
        for(i=1;i<=n;i++)
            fa[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
            if(edge[i].c==0)
            {
                add(edge[i].a,edge[i].b);
            }
        }
        int f=0;
        memset(num,0,sizeof(num));
        for(i=1;i<=k;i++)
        {
            int tmp = find(sum[i-1]+1);
            for(j=sum[i-1]+2;j<=sum[i];j++)
            {
                int tt = find(j);
                if(tt!=tmp)f=1;
            }
        }
//        for(i=1;i<=n;i++)
//            cout<<fa[i]<<" ";
//        cout<<endl;
//        cout<<f<<endl;
        if(f)
        {
            puts("No");
        }
        else
        {
            puts("Yes");
            memset(d,-1,sizeof(d));
            for(i=1;i<=k;i++)
            {
                d[i][i]=0;
                for(j=i+1;j<=k;j++)
                {
                    if(find(sum[i])==find(sum[j]))
                        d[i][j]=d[j][i]=0;
                }
            }

            for(i=0;i<m;i++)
            {
                if(edge[i].c)
                {
                    int x = mark[edge[i].a];
                    int y = mark[edge[i].b];
                    int tmp = d[x][y];

                    if(tmp==-1||tmp>edge[i].c)
                        d[x][y]=edge[i].c;
                    //cout<<tmp<<"   "<<d[x][y]<<endl;
                    tmp = d[y][x];
                    if(tmp==-1||tmp>edge[i].c)
                        d[y][x]=edge[i].c;
                }
            }
//            for(i=1;i<=k;i++)
//            {
//                for(j=1;j<=k;j++)
//                    cout<<d[i][j]<<" ";
//                cout<<endl;
//            }
            for(int t=1;t<=k;t++)
            {
                for(i=1;i<=k;i++)
                {
                    for(j=1;j<=k;j++)
                    {
                        if(d[i][t]!=-1&&d[t][j]!=-1&&i!=j)
                        {
                            if(d[i][j]==-1||d[i][j]>d[i][t]+d[t][j])
                                d[i][j]=d[i][t]+d[t][j];
                        }
                    }
                }
            }
            for(i=1;i<=k;i++)
            {
                for(j=1;j<=k;j++)
                    cout<<d[i][j]<<" ";
                cout<<endl;
            }
        }
    }
}
