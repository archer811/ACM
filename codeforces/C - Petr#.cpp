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
char s[2005];
char a[2005],b[2005];
#define ll long long
const ll magic = 31;
const int N = 2005;
ll base[N];


ll h[N];
inline void init_hash(int l,char *s)
{
    h[0] = 0;
    for(int i=1; i<=l; i++)
    {
        h[i] = h[i-1]*magic + s[i-1];
        //cout<<i<<"()"<<h[i]<<endl;
    }
}
inline ll string_hash(int l,int r)
{
    return h[r]-h[l]*base[r-l];
}
inline ll ask(int l,char *s)
{
    ll tmp =0;
    for(int i=1; i<=l; i++)
        tmp = tmp*magic+s[i-1];
    return tmp;
}
int L[N],R[N];
struct array
{
    int l,r;
    ll v;
} o[N*N],now;
int cmp(array a,array b)
{
    return a.v<b.v;
}
int main()
{
    int i,j;
    base[0]=1;
    for(i=1; i<N; i++)
        base[i] = base[i-1]*magic;
    while(scanf("%s%s%s",s,a,b)!=EOF)
    {
        int len=strlen(s);
        for(i=0;i<=len;i++)
            L[i]=R[i]=0;
        int len1 = strlen(a);
        int len2 = strlen(b);
        init_hash(len,s);
        ll x = ask(len1,a);
        ll y = ask(len2,b);
        int k=0;
        int g = max(len1,len2);
        if(g>len)
        {
            printf("0\n");
            continue;
        }
        int g1 = min(len1,len2);
        for(i=0; i<len; i++)
        {
            for(j=i+g1-1; j<len; j++)
            {
                now.l=i;
                now.r=j;
                now.v=string_hash(i,j+1);
                o[k++]=now;
                if(i<=len-len1)
                {
                    ll tmp = now.v;
                    if(tmp==x)
                    {
                        L[i]=1;
                    }
                }
                if(j>=len2-1)
                {
                    ll tmp = now.v;
                    if(tmp==y)
                    {
                        R[j]=1;
                    }
                }
            }
        }
        sort(o,o+k,cmp);
        int sum=0;

        for(i=0; i<k; i++)
        {
            if(i!=0&&o[i].v==o[i-1].v)continue;
            if(o[i].r-o[i].l+1>=g && L[o[i].l] && R[o[i].r])
            {
//                cout<<i<<"  "<<o[i].l<<"  "<<o[i].r <<"  "<<L[o[i].l]<<
//                  "  "<<R[o[i].r]<<endl;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
