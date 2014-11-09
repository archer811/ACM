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
const int maxn = 100005;
ll a[maxn],sum[maxn];
int b[maxn];
ll xmul(int a,int b,int c)
{
    return (ll)((sum[b]-sum[a])*(c-b)-(b-a)*(sum[c]-sum[b]));
}
int func(int x,int y,int x2,int y2)
{
    int tmp1 = (sum[x]-sum[y])*(x2-y2);
    int tmp2 = (sum[x2]-sum[y2])*(x-y);
    cout<<x<<" "<<y<<" "<<x2<<" "<<y2<<" "<<(sum[x]-sum[y])<<" "
    <<(sum[x2]-sum[y2])<<" "<<tmp1<<"()"<<tmp2<<endl;
    return tmp1>=tmp2;
}
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int tail=0,head=0;
        double ans=0;
        for(i=k;i<=n;i++)
        {
            int x = i-k;
            //while(tail-2>=head&&func(x,b[tail-1],b[tail-1],b[tail-2]))
            while(tail-2>=head&&xmul(b[tail-2],b[tail-1],x)<=0)
                tail--;
            b[tail++]=x;
            while(head+1<tail&&func(i,b[head+1],i,b[head]))
                head++;
//            for(int g=head;g<tail;g++)
//            {
//                cout<<b[g]<<" ";
//            }
//            cout<<endl;
            cout<<i<<"**"<<b[head]<<endl;
            double tmp = (double)(sum[i]-sum[b[head]])*1.0/(i-b[head]);
            ans = max(ans,tmp);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

