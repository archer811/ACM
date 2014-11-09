#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int n,m;
const int maxn = 2000000;
int fa[maxn],now[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
char s[2];
void add(int x,int y)
{
    int a = find(now[x]),b = find(now[y]);
    if(a!=b)
    {
        fa[a]=b;
    }
}
int f[maxn];
int main()
{
    int i,j;
    int a,b;
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        for(i=0;i<=n+m;i++)
            fa[i]=now[i]=i,f[i]=0;
        int size=n;
        for(int g=0;g<m;g++)
        {
            scanf("%s",s);
            if(s[0]=='S')
            {
                scanf("%d",&a);
                now[a]=size++;
            }
            else
            {
                scanf("%d%d",&a,&b);
                add(a,b);
            }
//            for(i=0;i<size;i++)
//            {
//                find(i);
//                cout<<fa[i]<<" ";
//            }
//            cout<<endl;
        }
        for(i=0;i<n;i++)
        {
            find(now[i]);
            f[fa[now[i]]]++;
//            cout<<fa[now[i]]<<endl;
        }
        int sum=0;
        for(i=0;i<size;i++)
            if(f[i])sum++;
        printf("Case #%d: %d\n",++cas,sum);
    }
}
