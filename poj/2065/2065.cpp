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
int p,n;
char s[10000];
int len;
const int maxn = 105;
int a[105][105];
void init()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        if(s[i]=='*')
            a[i][n]=0;
        else
            a[i][n]=s[i]-'a'+1;
    }
    for(i=0; i<n; i++)
    {
        int k=1;
        for(j=0; j<n; j++)
        {
            a[i][j]=k;
            k=(k*(i+1))%p;
        }
    }
}
int x[maxn];
int _abs(int x)
{
    if(x<0)return -x;
    return x;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void gauss()
{
    int r, c, mr;
    int mx;
    int g, ta, tb;
    int m = n;
    for (r = c = 0; r < n && c < m; ++r, ++c)
    {
        mr = -1, mx = 0;
        for (int i = r; i < n; ++i)
        {
            if ( _abs(a[i][c]) > mx )
            {
                mx = _abs(a[i][c]);
                mr = i;
            }
        }
        if (!~mr)
        {
            --r;
            continue;
        }
        else if (mr != r)
        {
            for (int i = c; i <= m; ++i)
            {
                swap(a[mr][i], a[r][i]);
            }
        }
        for (int i = r + 1; i < n; ++i)
        {
            if (!a[i][c]) continue;
            g = gcd(a[r][c], a[i][c]);
            ta = a[r][c] / g;
            tb = a[i][c] / g;
            for (int j = c; j <= m; ++j)
            {
                a[i][j] = a[r][j] * tb - a[i][j] * ta;
                a[i][j] %= p;
            }
        }
    }
//must have a solution
    int t;
    for (int i = m - 1; i >= 0; --i)
    {
        t = a[i][m];
        for (int j = i + 1; j < m; ++j)
        {
            t -= a[i][j] * x[j];
            t %= p;
        }
        //x[i] = MLES(a[i][i], t, p);
        for (int j = 0; j < p; ++j)
        {
            if ((a[i][i] * j - t) % p == 0)
            {
                x[i] = j;
                break;
            }
        }
    }
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&p,s);
        n = strlen(s);
        init();
        gauss();
        for(i=0;i<n;i++)
        {
            if(i==0)printf("%d",x[i]);
            else printf(" %d",x[i]);
        }
        puts("");
    }
    return 0;
}
