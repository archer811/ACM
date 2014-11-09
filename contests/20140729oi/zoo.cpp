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

#pragma comment(linker, "/STACK:102400000000,102400000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1000600,maxm=2100000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;
const int mod = 1000000007;
char s[maxn];
int next[maxn],num[maxn];
int head[maxn],tot;
struct Edge
{
    int to,next;
} edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int now_array[maxn];
int SB(int l, int r, int u)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(next[now_array[mid]]>u/2)
            r=mid-1;
        else
            l=mid+1;
    }
    l--;
    return l;
}
void solve()
{
    memset(num, -1, sizeof(num));
    stack<int> sk;
    int _index = 0;
    sk.push(0);
    while (!sk.empty())
    {
        int u = sk.top();
        if (num[u] == -1)
        {
            now_array[_index] = u;
            int l = SB(0, _index, u);
            if (u) num[u] = l - 1;
            else num[u] = 0;
            _index++;
        }
        if (head[u] != -1)
        {
            int ux = head[u];
            int v = edge[ux].to;
            head[u] = edge[ux].next;
            sk.push(v);
        }
        else
        {
            sk.pop();
            _index--;
        }
    }
}
int main()
{
    freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    int i,j,n;
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            scanf("%s",s);
            int len = strlen(s);
            next[0]=0;
            next[1]=0;
            for(i=1; i<len; i++)
            {
                j=next[i];
                while(j&&s[i]!=s[j])j=next[j];
                next[i+1]= s[i]==s[j]?j+1:0;
            }

            memset(head,-1,sizeof(head));
            tot=0;
            for(i=1; i<=len; i++)
                add(next[i],i);

            solve();

            ll sum=(ll)(num[1]+1)%mod;
            for(i=2; i<=len; i++)
            {
                sum = sum*(ll)(num[i]+1);
                sum %= mod;
            }
            sum %= mod;
            int sum2 = (int)sum;
            printf("%d\n",sum2);
        }
    }
    return 0;
}
