#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 300005;
int l[maxn],r[maxn],f[maxn];
int c[maxn];
int lowbit(int x)//位运算求lowbit(x)
{
    return x&(x^(x-1));
}
void add(int x,int val)//修改位置x的值，val为变化值，可为+-；
{
    while(x <= maxn)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
int getsum(int x)//求sum(x)
{
    int result = 0;
    while(x > 0)
    {
        result += c[x];
        x -= lowbit(x);

    }
    return result;
}
int main()
{
    int i,j,k;
    int n,m;
    int a,b,_c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<=n+1; i++)
            f[i]=0;
        //memset
        memset(c,0,sizeof(c));
        r[0]=1;
        l[n+1]=n;
        for(i=1; i<=n; i++)
            l[i]=i-1,r[i]=i+1,add(i,1);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&_c);
            int ll = a-1,rr = b+1;
            int tmp = getsum(a-1)+1;
            while(ll<rr)
            {
                int mid = (ll+rr)/2;
                if(getsum(mid)>=tmp)rr=mid;
                else ll = mid+1;
            }
            i = ll;
            //if(i==0)i=r[0];
            //cout<<i<<" "<<getsum(1)<<" "<<tmp<<endl;
            while(i<=b)
            {
                if(i!=_c)
                {
                    j = i;
                    if(f[j]==0)
                        f[j]=_c,add(j,-1);
                    i = r[i];
                    //if(j==1)cout<<l[j]<<endl;
                    r[l[j]]=i;
                    l[i]=l[j];
                }
                else i = r[i];
            }
            //cout<<r[0]<<"*"<<endl;
            if(i==b)
            {
                if(i!=_c)
                {
                    j = i;
                    if(f[j]==0)
                        f[j]=_c,add(j,-1);
                    i = r[i];
                    r[l[j]]=i;
                    l[i]=l[j];
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            if(i==1)printf("%d",f[i]);
            else printf(" %d",f[i]);
        }
        puts("");
    }
}
