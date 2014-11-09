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
char s[100005];
ll a[11];
string b[100005];
const ll mod = 1000000007;
ll v[11],Pow[11];
int main()
{
    int i,j,t;
    while(scanf("%s%d",s,&t)!=EOF)
    {
        for(i=0;i<=9;i++)
            v[i]=i,Pow[i]=10;
        for(i=0;i<t;i++)
            cin>>b[i];
        for(i=0;i<t;i++)
        {
            ll g=0;
            ll k = 1;
            int len = b[i].length();
            //cout<<len<<endl;
            for(j=3;j<len;j++)
            {
                int d2 = b[i][j]-'0';
                k = (k*Pow[d2])%mod;
                g = (g*Pow[d2]+v[d2])%mod;

                //cout<<j<<"*"<<g<<" "<<k<<endl;
            }
            int d = b[i][0]-'0';
            v[d]=g;
            Pow[d]=k;
            //cout<<d<<"  "<<g<<"  "<<k<<endl;
        }
        int len  = strlen(s);
        ll ans = 0;
//        for(i=0;i<=9;i++)
//        {
//            cout<<i<<"*"<<v[i]<<"  "<<Pow[i]<<endl;
//        }
        for(i=0;i<len;i++)
        {
            int d = (s[i]-'0');
            ans = (ans*Pow[d] + v[d])%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
