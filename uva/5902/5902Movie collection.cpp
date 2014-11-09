#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 310000;
int c[maxn+5];
int lowbit(int x)
{
    return x&(-x);
}
int Max;
void add(int x,int val)
{
    while(x<=maxn)
    {
         c[x]+=val;x+=lowbit(x);
    }

}
int sum(int x)
{
    int sum=0;
    while(x>0)
        sum += c[x],x-=lowbit(x);
    return sum;
}
int a[maxn];
int main()
{
    int i,j,k,T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(c,0,sizeof(c));
        Max = n*2+100;
        for(i=1;i<=n;i++)
        {
            add(i,1);
            a[i]=n+1-i;
        }
        int mm = n;
        int flag=0;
        while(m--)
        {
            scanf("%d",&j);
            //cout<<a[j]<<" "<<sum(a[j])<<endl;
            if(flag)
               printf(" %d",mm-sum(a[j]));
            else flag=1,printf("%d",mm-sum(a[j]));
            n++;
            add(a[j],-1);
            a[j]=n;
            add(n,1);
        }
        puts("");
    }
}
