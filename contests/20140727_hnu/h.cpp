#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;
struct array
{
    int ti,kind,v;
}g[20005];
int cmp(array x,array y)
{
    if(x.ti==y.ti)return x.kind<y.kind;
    return x.ti<y.ti;
}
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int num=0;
        for(i=0;i<n;i++)
        {
            int x;
            int a,b;
            scanf("%d",&x);
            scanf("%d:%d",&a,&b);
            a = a*60+b;
            g[num].ti=a;
            g[num].v=x;
            g[num++].kind=1;
            scanf("%d:%d",&a,&b);
            a = a*60+b;
            g[num].ti=a;
            g[num].v=x;
            g[num++].kind=-1;
            //cout<<g[i].s<<" "<<g[i].t<<endl;
        }
        sort(g,g+num,cmp);
        int ans=0;
        int now=0;
        for(i=0;i<num;i++)
        {
            if(g[i].kind==1)now+=g[i].v;
            else now-=g[i].v;
            //cout<<g[i].ti<<" "<<g[i].kind<<" "<<g[i].v<<" "<<now<<endl;
            ans = max(ans,now);
        }
        printf("%d\n",ans);
    }
    return 0;
}
