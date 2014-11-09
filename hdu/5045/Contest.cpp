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
const int MAXN = 11;
const double inf = 0x7FFFFFFF;

int nx,ny;
int link[MAXN];
double lx[MAXN],ly[MAXN];
double slack[MAXN];    //lx,ly为顶标，nx,ny分别为x点集y点集的个数
int visx[MAXN],visy[MAXN];
double w[MAXN][MAXN];

const double eps = 1e-6;

int DFS(int x)
{
    visx[x] = 1;
    for (int y = 1; y <= ny; y ++)
    {
        if (visy[y])
            continue;
        double t = lx[x] + ly[y] - w[x][y];
        if (fabs(t)<eps)       //
        {
            visy[y] = 1;
            if (link[y] == -1||DFS(link[y]))
            {
                link[y] = x;
                return 1;
            }
        }
        else if (slack[y] > t)  //不在相等子图中slack 取最小的
            slack[y] = t;
    }
    return 0;
}
double km()
{
    int i,j;
    memset (link,-1,sizeof(link));
    memset (ly,0,sizeof(ly));
    for (i = 1; i <= nx; i ++)          //lx初始化为与它关联边中最大的
        for (j = 1,lx[i] = -inf; j <= ny; j ++)
            if (w[i][j] > lx[i])
                lx[i] = w[i][j];

    for (int x = 1; x <= nx; x ++)
    {
        for (i = 1; i <= ny; i ++)
            slack[i] = inf;
        while (1)
        {
            memset (visx,0,sizeof(visx));
            memset (visy,0,sizeof(visy));
            if (DFS(x))     //若成功（找到了增广轨），则该点增广完成，进入下一个点的增广
                break;  //若失败（没有找到增广轨），则需要改变一些点的标号，使得图中可行边的数量增加。
            //方法为：将所有在增广轨中（就是在增广过程中遍历到）的X方点的标号全部减去一个常数d，
            //所有在增广轨中的Y方点的标号全部加上一个常数d
            double d = inf;
            for (i = 1; i <= ny; i ++)
                if (!visy[i]&&d > slack[i])
                    d = slack[i];
            for (i = 1; i <= nx; i ++)
                if (visx[i])
                    lx[i] -= d;
            for (i = 1; i <= ny; i ++) //修改顶标后，要把所有不在交错树中的Y顶点的slack值都减去d
                if (visy[i])
                    ly[i] += d;
                else
                    slack[i] -= d;
        }
    }
    double res = 0;
    for (i = 1; i <= ny; i ++)
        if (link[i] > -1)
            res += w[link[i]][i];
    return res;
}
double d[11][1005];
double lg[11][1025];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n, m;
        scanf("%d%d",&n,&m);
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
                scanf("%lf",&d[i][j]);
        }
        double ans=0;
        for(i=1; i<=m; i+=n)
        {
            j = i+n-1;
            nx = ny = n;
            for(int k=1; k<=n; k++)
            {
                for(int s=1; s<=n; s++)
                    w[k][s]=d[k][i+s-1];
            }
//            for(int k=1; k<=n; k++)
//            {
//                for(int s=1; s<=n; s++)
//                    cout<<w[k][s]<<" ";
//                    cout<<endl;
//            }
//            cout<<km()<<endl;
            ans += km();
        }
        printf("Case #%d: %.5f\n",++cas,ans);
    }
    return 0;
}
