#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//#define ull unsigned __int64
//#define ll __int64
//#define ull unsigned long long
//#define ll long long
#define son1 New(p.xl,xm,p.yl,ym),(rt<<2)-2
#define son2 New(p.xl,xm,min(ym+1,p.yr),p.yr),(rt<<2)-1
#define son3 New(min(xm+1,p.xr),p.xr,p.yl,ym),rt<<2
#define son4 New(min(xm+1,p.xr),p.xr,min(ym+1,p.yr),p.yr),rt<<2|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle (l+r)>>1
#define MOD 1000000007
#define esp (1e-8)
const int INF=0x3F3F3F3F;
const double DINF=10000.00;
//const double pi=acos(-1.0);
const int N=50010;
int n,m;
int sum[N],val[N],hash[N],ret[N];
vector<int>son[N];

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

int lowbit(int x)
{
    return x&(-x);
}

void Add(int x,int c)
{
    while(x<=m) sum[x]+=c,x+=lowbit(x);
}

int Sum(int x)
{
    int r=0;
    while(x>0) r+=sum[x],x-=lowbit(x);
    return r;
}

void Query(int rt)
{
    int i,pos=bs(val[rt],m,hash)+1;
    cout <<rt << " "<<pos<<endl;
    int tmp=Sum(m)-Sum(pos),len=son[rt].size();
    for(i=0; i<len; i++) Query(son[rt][i]);
    ret[rt]=Sum(m)-Sum(pos)-tmp;
    Add(pos,1);
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int i,j,k;
    //int T,cas;scanf("%d",&T);for(cas=1;cas<=T;cas++)
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++) son[i].clear();
        for(i=1; i<n; i++)
        {
            scanf("%d",&k);
            son[k].push_back(i);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&val[i]);
            hash[i]=val[i];
        }
        sort(hash,hash+n);
        for(i=m=1; i<n; i++) if(hash[i]!=hash[i-1]) hash[m++]=hash[i];
        memset(sum,0,sizeof(sum));
        Query(0);
        for(i=0; i<n-1; i++) printf("%d ",ret[i]);
        printf("%d\n",ret[i]);
    }
    return 0;
}
