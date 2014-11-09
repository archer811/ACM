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
int main()
{
    int i,j;
    int n,s;
    while(cin>>n>>s)
    {
        int ans=-1;
        for(i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(s>=a+1&&b!=0)
            {
                //cout<<s<<"  *  "<<a+1<<"  "<<100-b<<endl;
                ans = max(ans,100-b);
            }
            else if(s>=a&&b==0)
            {
                ans = max(ans,0);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
