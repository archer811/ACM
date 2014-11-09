#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 210000;
int c[maxn];
int lowbit(int x)
{
    return ~x & x + 1;
}
int n;
void add(int x,int val)
{
    while(x<=n)
        c[x]+=val,x += lowbit(x);
}
int sum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
char s[10];
int a[maxn];
int main()
{
    int i,j,k;
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            a[i]=j;
            add(i,j);
        }
        if(cas)puts("");
        printf("Case %d:\n",++cas);
        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='E')break;
            if(s[0]=='S')
            {
                scanf("%d%d",&j,&k);
                add(j,k-a[j]);
                a[j]=k;
            }
            else
            {
                scanf("%d%d",&j,&k);
                printf("%d\n",sum(k)-sum(j-1));
            }
        }
    }
}
