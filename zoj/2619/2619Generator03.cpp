#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll long long
int N;
const int maxn = 300;
int chd[maxn][27],fail[maxn],sz;
int f[maxn];
#define ll long long
ll mat[maxn][maxn];
int vis[maxn];
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
    memset(f,0,sizeof(f));
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
}
void Ins(char *s)
{
    int p = 0;
    for(;*s;s++)
    {
        if(!chd[p][(*s)-'A'])
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            chd[p][(*s)-'A']=sz++;
        }
        p = chd[p][(*s)-'A'];
    }
    f[p]=1;
}
int Que[maxn];
void AC()
{
    int *s = Que,*e = Que;
    for(int i=0;i<27;i++)
        if(chd[0][i])
        {
            fail[chd[0][i]]=0;
            *e++=chd[0][i];
        }
    while(s!=e)
    {
        int p = *s++;
        for(int i=0;i<27;i++)
        {
            if(chd[p][i])
            {
                int k = chd[p][i];
                fail[k]=chd[fail[p]][i];
                f[k]|=f[fail[k]];
                *e++=k;
            }
            else chd[p][i]=chd[fail[p]][i];
        }
    }
}
char s[14];
void dfs(int u)
{
    if(vis[u])return;
    vis[u]=1;
    mat[u][u]=N;
    if(f[u])
        mat[u][sz]=0;
    else mat[u][sz]=N;
    for(int i=0;i<N;i++)
    {
        int v = chd[u][i];
        if(f[u]==0)
            mat[u][v]-=1;
        dfs(v);
    }
}
ll x[maxn];
bool free_x[maxn];
int free_num;
inline ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
inline ll lcm(ll a,ll b)
{
    return (ll)a*(ll)b/gcd((ll)a,(ll)b);
}
ll ABS(ll a)
{
    if(a>0)return a;
    else return -a;
}
bool gaussInt()
{
    int temp;
    ll mmi;
    int r = sz,c = sz+1;
    //cout<<r<<"----------------"<<c<<endl;
    for(int i = 0; i < r; ++i)
    {
        mmi = ABS(mat[i][i]);
        temp = i;
        for(int j = i+1; j < r; ++j)
            if(ABS(mat[j][i]) < mmi && mat[j][i])
            {
                mmi = ABS(mat[j][i]);
                temp = j;
            }
        if(temp != i)
            for(int j = 0; j < c; ++j)
                swap(mat[i][j], mat[temp][j]);
        for(int j = i+1; j < r; ++j)
            if(mat[j][i])
            {
                ll lc = lcm(mat[j][i], mat[i][i]);
                ll l1, l2;
                l1 = lc/mat[j][i];
                l2 = lc/mat[i][i];
                for(int k = i; k < c; ++k)
                    mat[j][k] = mat[j][k]*l1-mat[i][k]*l2;
            }
    }
    for(int i = r-1; i >= 0; --i)
    {
        for(int j = i+1; j < c-1; ++j)
            mat[i][c-1] -= mat[j][c-1]*mat[i][j];
        mat[i][c-1] /= mat[i][i];
    }
    return true;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%s",&N,s);
        init();
        Ins(s);
        AC();
        dfs(0);
//        for(i=0;i<sz;i++)
//        {
//            for(j=0;j<=sz;j++)
//                cout<<mat[i][j]<<" ";
//            cout<<endl;
//        }
        gaussInt();
        if(cas)puts("");
        printf("Case %d:\n%lld\n",++cas,mat[0][sz]);
    }
}
