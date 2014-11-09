#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<vector>
using namespace std;
const int maxn = 305;
struct twosat
{
    int n;
    vector<int>G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;
    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for (int i=0 ; i<G[x].size() ; i++)
        {
            if (!dfs(G[x][i])) return false;
        }
        return true;
    }
    void init(int n)
    {
        this->n=n;
        for (int i=0 ; i<2*n ; i++) G[i].clear();
        memset(mark,0,sizeof(mark));
    }
    void add_clause(int x,int xval,int y,int yval)
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }
    bool solve()
    {
        for (int i=0 ; i<2*n ; i+=2)
        {
            if (!mark[i] && !mark[i+1])
            {
                c=0;
                if (!dfs(i))
                {
                    while (c>0) mark[S[--c]]=false;
                    if (!dfs(i+1)) return false;
                }
            }
        }
        return true;
    }
};
const double eps = 1e-7;
int vis[maxn][2];
struct array
{
    double x,y,z;
} t[maxn][2];
twosat solver;
int n;
double d[maxn][2][maxn][2];
double dis(int x,int a,int y,int b)
{
    return sqrt((t[x][a].x-t[y][b].x)*(t[x][a].x-t[y][b].x)
                +(t[x][a].y-t[y][b].y)*(t[x][a].y-t[y][b].y)
                +(t[x][a].z-t[y][b].z)*(t[x][a].z-t[y][b].z));
}
int test(double mid)
{
    solver.init(n);
    for(int i=0; i<n; i++)
    {
        for(int a=0; a<2; a++)
        {
            if(vis[i][a])continue;
            for(int j=i+1; j<n; j++)
            {
                for(int b=0; b<2; b++)
                {
                    if(vis[j][b])continue;
                    double tmp = d[i][a][j][b];
                    if(tmp<mid*2)solver.add_clause(i,a^1,j,b^1);
                }
            }
        }
    }
    return solver.solve();
}
#define ll long long


int ff(double x,double y,double z)
{
    if(x<0||x>10000)return 1;
    if(y<0||y>10000)return 1;
    if(z<0||z>10000)return 1;
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for(i=0; i<n; i++)
        {
            scanf("%lf%lf%lf%lf%lf%lf",&t[i][0].x,&t[i][0].y,&t[i][0].z,
                  &t[i][1].x,&t[i][1].y,&t[i][1].z);
            //if(ff(t[i][0].x,t[i][0].y,t[i][0].z))vis[i][0]=1;
            //if(ff(t[i][1].x,t[i][1].y,t[i][1].z))vis[i][1]=1;
        }
        for(int i=0; i<n; i++)
        {
            for(int a=0; a<2; a++)
            {
                for(int j=i+1; j<n; j++)
                {
                    for(int b=0; b<2; b++)
                    {
                        d[i][a][j][b]=dis(i,a,j,b);
                    }
                }
            }
        }
        double l = 0,r = 10000*sqrt(3.0)/2+1;
        while(l+eps<r)
        {
            double mid = (l+r)/2;
            if(test(mid))l=mid;
            else r=mid-eps;
        }
        double l2=  l;
        l2*=1000;
        ll l3 = (ll)l2;

        double l4 = (double)l3/1000.0;
        //cout<<l3<<" "<<l4<<endl;
        printf("%.3f\n",l4);
    }
    return 0;
}
