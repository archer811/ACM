#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 200105;
char s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
void getsa(int m)
{
    int i,j,k;
    int *x = t,*y = t2;
    for(i=0; i<m; i++)
        c[i]=0;
    for(i=0; i<n; i++)
        c[x[i]=s[i]]++;
    for(i=1; i<m; i++)
        c[i]+=c[i-1];
    for(i=n-1; i>=0; i--)
        sa[--c[x[i]]]=i;
    for(i=0;i<n;i++)
        cout<<i<<" "<<sa[i]<<endl;
    for(k=1; k<=n; k*=2)
    {
        int p = 0;
        for(i=n-k; i<n; i++)
            y[p++]=i;
        for(i=0; i<n; i++)
            if(sa[i]>=k)
                y[p++]=sa[i]-k;
        for(i=0; i<m; i++)
            c[i]=0;
        for(i=0; i<n; i++)
            c[x[y[i]]]++;
        for(i=1; i<m; i++)
            c[i]+=c[i-1];
        for(i=n-1; i>=0; i--)
        {
            sa[--c[x[y[i]]]]=y[i];
        }
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(i=1; i<n; i++)
        {
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        }
        m = p;
    }
}
int _rank[maxn],height[maxn];
void getheight()
{
    int i,j;
    for(i=0; i<n; i++)
        _rank[sa[i]]=i;
    int k =0;
    for(i=0; i<n; i++)
    {
        if(k)k--;
        j = sa[_rank[i]-1];
        while(s[j+k]==s[i+k])k++;
        height[_rank[i]]=k;
    }
}
int d[maxn][25];
void rmqinit()
{
    for(int i=1; i<=n; i++)
        d[i][0]=height[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i = 1; i+j-1<=n; i++)
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r)
{
    int k =0;
    while((1<<(k+1))<=r-l+1)k++;
    return min(d[l][k],d[r-(1<<k)+1][k]);
}
int askrmq(int l,int r)
{
    int a = _rank[l],b = _rank[r];
    if(a>b)swap(a,b);
    return rmq(a+1,b);
}
int main()
{
    int i,j;
    int cas=0;
    while(scanf("%s",s)!=EOF)
    {
        n = strlen(s);
        int m = 0;
        for(i=0; i<n; i++)
        {
            if(s[i]>m)m=s[i];
        }
        getsa(m+1);
        getheight();

    }
}
