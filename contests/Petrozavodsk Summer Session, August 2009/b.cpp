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
const int maxn = 100005;
struct array
{
    int a,b,k;
}s[maxn];
int cmp(array x,array y)
{
    if(x.a==y.a)return x.b>y.b;
    return x.a<y.a;
}
int vis[maxn*2];
int l[maxn],r[maxn];
int a[maxn],b[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        int num=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i].a,&s[i].b);
            if(s[i].a>s[i].b)
                swap(s[i].a,s[i].b);
            s[i].k=i;
        }
        memset(vis,0,sizeof(vis));
        sort(s+1,s+n+1,cmp);
        int flag=0;
        int f=1,end=n;
        for(i=1;i<=n;i++)
        {
            //cout<<i<<" "<<s[i].a<<" "<<s[i].b<<endl;
            if(i==1)
            {
                l[f]=s[i].a;
                r[f++]=s[i].b;
            }
            else
            {
                if(!(l[f-1]<=s[i].a&&r[f-1]>=s[i].b))
                {
                    if(n==end)
                    {
                        l[end]=s[i].a;
                        r[end--]=s[i].b;
                    }
                    else
                    {
                        if(l[end+1]>=s[i].a&&r[end+1]<=s[i].b)
                        {
                            l[end]=s[i].a;
                            r[end--]=s[i].b;
                        }
                        else
                        {
                            if(vis[s[i].k]){flag=1;break;}
                            swap(s[i].a,s[i].b);

                            vis[s[i].k]=1;
                            i--;
                        }
                    }
                }
                else
                {
                    l[f]=s[i].a;
                    r[f++]=s[i].b;
                }
            }
        }
        for(i=2;i<=n;i++)
        {
            if(!(l[i]>=l[i-1]&&r[i]<=r[i-1]))flag=1;
        }
        if(flag)puts("NO");
        else
        {
            puts("YES");
            for(i=1;i<=n;i++)
                printf("%d %d\n",l[i],r[i]);
        }
    }
    return 0;
}
