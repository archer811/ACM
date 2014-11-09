#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[100005],f[100005];
int find(int a)
{
    if(f[a]==a)return a;
    return f[a]=find(f[a]);
}
void add(int s,int t)
{
    int u = find(s),v = find(t);
    f[v]=u;
    a[u]+=a[v];
}
struct array
{
    int num,index;
}ans[100005];
int cmp(array x,array y)
{
    return x.num>y.num;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        for(i=0;i<A;i++)
            a[i]=1,f[i]=i;
        for(i=0;i<B;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            add(s,t);
        }
        k=0;
        for(i=0;i<A;i++)
        {
            if(find(i)==i)
            {
                ans[k].index=i;
                ans[k++].num=a[i];
            }
        }
        int ant=0;
        sort(ans,ans+k,cmp);
        for(i=0;i<k&&i<C;i++)
            ant += ans[i].num;
        printf("%d\n",ant);
    }
}
