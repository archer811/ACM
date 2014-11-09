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
const int maxn = 80000+10;
int a[maxn],b[maxn],ans[maxn];
#define ll long long
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(ans,-1,sizeof(ans));
        int k=0;
        a[n+1]= 1000000001;
        for(i=n+1;i>=1;i--)
        {

            while(k>0&&a[b[k-1]]<a[i])
                k--;
            b[k++]=i;
            if(k>=2)
                ans[i]=b[k-2];
        }
        ll sum=0;
        for(i=1;i<=n;i++)
         {
             if(ans[i]!=-1)
                sum += (ll)(ans[i]-i-1);
             //cout<<i<<" "<<ans[i]<<" "<<sum<<endl;
         }
        printf("%lld\n",sum);
    }
    return 0;
}
