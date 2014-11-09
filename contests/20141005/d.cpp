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
#define ll __int64
#pragma comment(linker, "/STACK:1024000000,1024000000")
ll a[6][205];
const int MAXM = 100007;
const int MAXN = 100007;
struct Hash
{
    int mod, head[MAXM]; // MAXM 表示最大的 MOD，多重 hash 时使用
    int next[MAXN], used;
    ll  val[MAXN];
    int m;
    void Init()
    {
        memset(head, -1, sizeof(head));
        used = 0;
        mod = 100007;
    }
    void add(ll v)
    {
        if(find(v)!=-1)return;
m = v%mod;
        m = (m+mod)%mod;
        int &c = used;
        next[c] = head[m], val[c] = v,  head[m] = c++;
    }
    int find(ll v)
    {
        m = v%mod;
        m = (m+mod)%mod;
        for (int i = head[m]; i!=-1; i = next[i])
            if (val[i] == v) return i;
        return -1;
    }
} hash;
ll Scan()
{
    int  ch, flag = 0;
    ll res=0;

    if((ch = getchar()) == '-')             //判断正负
        flag = 1;

    else if(ch >= '0' && ch <= '9')           //得到完整的数
        res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9' )
        res = res * 10 + ch - '0';

    return flag ? -res : res;
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        hash.Init();
        for(i=1; i<=5; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%I64d",&a[i][j]);
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                ll tmp = -a[1][i]-a[2][j];
                //b[g++]=tmp;
                hash.add(tmp);
            }
        }
        int flag=0;
        for(i=1; i<=n&&flag==0; i++)
        {
            for(j=1; j<=n&&flag==0; j++)
            {
                for(int k=1; k<=n&&flag==0; k++)
                {
                    ll tmp = (a[3][i]+a[4][j]+a[5][k]);
                    //cout<<tmp<<"*"<<find(tmp)<<endl;
                    //if(find(tmp))
                    if(hash.find(tmp)!=-1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}
