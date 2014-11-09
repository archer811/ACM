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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int a[1005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int mark;
        if(n&1)
        {
            mark=1;
            for(i=1;i<=n;i++)
            {
                if(i&1)
                {

                }
                else
                {
                    if(a[i]>=2)mark^=1;
                }
                //cout<<mark<<"*"<<n<<endl;
                if(i<n)
                mark^=1;
                //cout<<i<<" "<<mark<<endl;
            }
            //cout<<mark<<endl;
        }
        else
        {
            //cout<<"no"<<endl;
            mark=1;
            for(i=1;i<=n;i++)
            {
                if(i&1)
                {
                    if(a[i]>=2)mark^=1;
                }
                else
                {

                }
                if(i<n)
                mark^=1;
                //cout<<i<<"*"<<mark<<endl;
            }
        }
        //cout<<mark<<endl;
        if(mark==0)puts("No");
        else puts("Yes");
    }
    return 0;
}
