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
const int maxn = 1000005;
struct array
{
    int a,b,k;
} s[maxn*2];
int vis[maxn];
int cmp(array x,array y)
{
    if(x.a==y.a)return x.b>y.b;
    return x.a<y.a;
}
int a[maxn],b[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&s[i*2].a,&s[i*2].b);
            s[i*2+1].a=s[i*2].b;
            s[i*2+1].b=s[i*2].a;
            s[i*2].k=s[i*2+1].k=i;
        }
        sort(s,s+2*n,cmp);
        int num=0;
        for(i=0; i<2*n; i++)
        {
            if(vis[s[i].k])continue;
            //cout<<s[i].a<<" "<<s[i].b<<endl;
            if(num==0||(s[i].a>=a[num-1]&&s[i].b<=b[num-1]))
            {
                a[num]=s[i].a;
                b[num++]=s[i].b;
                vis[s[i].k]=1;
            }


        }
        if(num<n)puts("NO");
        else
        {
            puts("YES");
            for(i=0; i<n; i++)
                printf("%d %d\n",a[i],b[i]);
        }
    }
    return 0;
}
