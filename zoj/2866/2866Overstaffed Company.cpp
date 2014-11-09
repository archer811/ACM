#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#define middle (l+r)>>1
using namespace std;
const int maxn = 51015;
int c[51016],val[maxn];
int bs(int key,int size,int A[])
{
    int l=0,r=size-1,mid;
    while(l<=r)
    {
        mid=middle;
        if(key>A[mid]) l=mid+1;
        else if(key<A[mid]) r=mid-1;
        else return mid;
    }
    return -1;
}
int tot,m;
int lowbit(int x)
{
    return x&(-x);
}

void Add(int x,int aa)
{
    while(x<=m) c[x]+=aa,x+=lowbit(x);
}
int Sum(int x)
{
    int r=0;
    while(x>0) r+=c[x],x-=lowbit(x);
    return r;
}

vector<int>g[maxn];
int n;

int a[maxn],b[maxn];
int t=0;
struct array
{
    int val,num;
}hash[maxn];
void dfs(int u)
{

    int i,pos=a[u],j;

    int pre = Sum(m)-Sum(pos-1);
   // cout<< u << " ()()( "<<t << " "<<getsum(a[u]-1)<<endl;
    for(i=0;i<g[u].size();i++)
    {
        int v  = g[u][i];
        dfs(v);
    }
    int now = Sum(m)-Sum(pos-1);
    Add(pos,1);

    b[u]=now-pre;
}
int cmp(array x,array y)
{
    return x.val<y.val;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            g[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d",&j);
            g[j].push_back(i);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&hash[i].val);
            hash[i].num=i;
        }
        m=1;
        sort(hash,hash+n,cmp);
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                a[hash[i].num]=m++;continue;
            }
            if(hash[i].val==hash[i-1].val)
                a[hash[i].num]=m;
            else a[hash[i].num]=m++;
        }
            //if(hash[i]!=hash[i-1])hash[m++]=hash[i];
        //for(i=0;i<n;i++)
        //    cout<<a[i]<<endl;
        memset(c,0,sizeof(c));
        dfs(0);
        for(i=0;i<n;i++)
        {
            if(i==0)printf("%d",b[i]);
            else printf(" %d",b[i]);
        }
        puts("");
    }
}
