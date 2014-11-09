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
const int maxn = 1000000+10;
template <class T>
inline bool rd(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template <class T>
inline void pt(T x)
{
    if (x <0)
    {
        putchar('-');
        x = -x;
    }
    if(x>9) pt(x/10);
    putchar(x%10+'0');
}
int a[maxn],b[maxn],Max[maxn],Min[maxn],b2[maxn];
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1; i<=n; i++)
            rd(a[i]);
        int l=0,r=0;
        int l2=0,r2=0;
        for(i=1; i<=n; i++)
        {
            while(r>l&&a[b[r-1]]<a[i])
                r--;
            b[r++]=i;
            while(l<r-1&&b[l]<i-k+1)
            {
                l++;
            }
            Max[i]=a[b[l]];

            while(r2>l2&&a[b2[r2-1]]>a[i])
                r2--;
            b2[r2++]=i;
            while(l2<r2-1&&b2[l2]<i-k+1)
                l2++;
            Min[i]=a[b2[l2]];
        }
        for(i=k; i<=n; i++)
        {
            if(i==k)printf("%d",Min[i]);
            else printf(" %d",Min[i]);
        }
        puts("");
        for(i=k; i<=n; i++)
        {
            if(i==k)printf("%d",Max[i]);
            else printf(" %d",Max[i]);
        }
        puts("");
    }
    return 0;
}
