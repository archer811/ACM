#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 110;
const int maxm = 10;
double mat[maxn][maxn];
const double eps = 1e-11;
inline int sgn(double x){return x<-eps?-1:x<eps?0:1;}
double x[maxn];
int n;
int vis[maxn];
double arr[maxn][maxn];
int chd[maxn][maxm],fail[maxn],sz,f[maxn];
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
    memset(f,0,sizeof(f));
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
    memset(x,0,sizeof(x));
}
void Ins(char *s)
{
    int p=0;
    for(;*s;s++)
    {
        if(!chd[p][(*s)-'A'])
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            chd[p][(*s)-'A']=sz++;
        }
        p=chd[p][(*s)-'A'];
    }
    f[p]=1;
}
int Que[maxn];
void AC()
{
    int *s=Que,*e=Que;
    for(int i=0;i<8;i++)
        if(chd[0][i])
        {
            fail[chd[0][i]]=0;
            *e++=chd[0][i];
        }
    while(s!=e)
    {
        int p = *s++;
        for(int i=0;i<8;i++)
        {
            if(chd[p][i])
            {
                int k = chd[p][i];
                fail[k]=chd[fail[p]][i];
                *e++=k;
                f[k]|=f[fail[k]];
            }
            else chd[p][i]=chd[fail[p]][i];
        }
    }
}
char s[10];
void dfs(int u)
{
    if(vis[u])return;
    vis[u]=1;
    mat[u][u]=n;
   // cout<<n<<"fsdaf"<<sz-1<<endl;
    if(f[u])
        mat[u][sz]=0;
    else mat[u][sz]=n;
    for(int i=0;i<n;i++)
    {
        int v = chd[u][i];
        if(f[u]==0)
            mat[u][v]-=1;
        dfs(v);
    }
}
void gauss_eliminate()
{
    int temp;
    long double mmx;
    int r = sz-1,c = sz;
    for(int i = 0; i < r; ++i)
    {
        temp = i;
        mmx = fabs(arr[i][i]);
        for(int j = i+1; j < r; ++j)
            if(fabs(arr[j][i]) > mmx)
            {
                mmx = fabs(arr[j][i]);
                temp = j;
            }
        if(temp != i) for(int j = 0; j < c; ++j) swap(arr[temp][j],arr[i][j]);
        for(int j = c-1; j >= i; --j)
            for(int k = i+1; k < r; ++k)
                arr[k][j] -= arr[k][i]/arr[i][i]*arr[i][j];

    }
    for(int i = r-1; i >= 0; --i)
    {
        for(int j = i+1; j < c-1; ++j)
            arr[i][c-1] -= arr[j][c-1]*arr[i][j];
        arr[i][c-1] /= arr[i][i];
    }
}
void gauss()
{
    int r,c,mr;
    double mx,t;
    int n = sz-1,m = sz;
    for(r=c=0;r<n&&c<m;++r,++c)
    {
        mr = -1,mx = eps;
        for(int i=r;i<n;++i)
        {
            if(fabs(mat[i][c]>mx))
            {
                mx = fabs(mat[i][c]);
                mr = i;
            }
        }
        //cout<<mr<<"fdsfdf"<<endl;
        if(!~mr)
        {
            --r;continue;
        }
        else
        {
            for(int i=c;i<=m;++i)
            {
                swap(mat[r][i],mat[mr][i]);
            }
        }
        for(int i=r+1;i<n;++i)
        {
            if(sgn(mat[i][c])==0)continue;
            t=mat[i][c]/mat[r][c];
            for(int j=c;j<=m;++j)
            {
                mat[i][j]-=mat[r][j]*t;
            }
        }
    }
    for(int i=r-1;i>=0;--i)
    {
        t=mat[i][m];
        for(int j=i+1;j<m;++j)
        {
            t-=x[j]*mat[i][j];
        }
        x[i]=t/mat[i][i];
    }
}
int main()
{
    int i,j,T,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        while(m--)
        {
            scanf("%s",s);
            Ins(s);
        }
        AC();
        dfs(0);
        for(i=0;i<sz;i++)
        {
            for(j=0;j<=sz;j++)
                arr[i][j]= mat[i][j];
        }
        gauss();
        //gauss_eliminate();
        printf("%.2f\n",x[0]);//arr[0][0]
    }
}
