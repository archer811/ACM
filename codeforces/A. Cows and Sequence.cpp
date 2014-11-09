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
const int maxn = 200005;
ll d[maxn];
ll w[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(d,0,sizeof(d));
        memset(w,0,sizeof(w));
        int t;
        ll a,x;
        ll sum=0;
        ll num=1;
        w[1]=0;
        while(n--)
        {
            scanf("%d",&t);
            if(t==1)
            {
                scanf("%I64d%I64d",&a,&x);
                sum += (ll)a*(ll)x;
                d[a]+=x;
            }
            else if(t==2)
            {
                scanf("%I64d",&x);
                sum += x;
                w[++num]=x;
            }
            else
            {
                d[num-1]+=d[num];
                sum -= d[num]+w[num];
                d[num]=0;
                w[num]=0;
                num--;
            }
            printf("%.6f\n",sum*1.0/num);
        }
    }
    return 0;
}

