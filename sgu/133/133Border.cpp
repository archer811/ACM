#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 56100;
int c[maxn];
int lowbit(int x)//位运算求lowbit(x)
{
    return x&(x^(x-1));
}
void add(int x,int val)
{
    while(x <maxn)
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
struct array
{
    int a,b,index;
} s[maxn];
int m[maxn];
int cmp(array x,array y)
{
    return x.a<y.a;
}
struct B
{
    int b,index;
}bb[maxn];
int cmp2(B a,B g)
{
    return a.b<g.b;
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
        m[i]=i;
        bb[i].b=s[i].b;
        bb[i].index=s[i].index=i;
    }
    sort(s,s+n,cmp);
    sort(bb,bb+n,cmp2);
    for(i=0;i<n;i++)
    {
        m[bb[i].index]=i+1;
    }
    memset(c,0,sizeof(c));
    int ans =0;
    for(i=0; i<n; i++)
    {
        add(m[s[i].index],1);
        int sum = getsum(m[s[i].index]);
        //cout<<i<<" "<<m[s[i].index]<<" "<<sum<<endl;
        if(i-sum+1>0)
            ans += 1;
    }
    printf("%d\n",ans);
}
