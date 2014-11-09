#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef __int64 ULL;
ULL f[20][172];
ULL ten[20];
void init()
{
    f[0][0]=1;
    for (int i=1; i<20; ++i)
        for (int j=0; j<=i*9; ++j)
            for (int k=0; k<=9; ++k) if (j>=k) f[i][j]+=f[i-1][j-k];
    ten[0]=1;
    for (int i=1; i<20; ++i) ten[i]=ten[i-1]*10;
}
ULL count(ULL n,int sum)
{
    if(n<0)return 0;
    //cout<<n<<"**"<<endl;
    ULL ans=0;
    for (int i=19; i>=1; --i)
    {
        sum-=n/ten[i];
        if (sum<0) break;
        n%=ten[i];
        for (int j=0; j<n/ten[i-1]; ++j) if (sum-j>=0) ans+=f[i-1][sum-j];
    }
    if (sum==n) ++ans;
    return ans;
}
int main()
{
    int i,j,k,T;
    ULL A,B;
    init();
   // cout<<count(91,10)<<endl;
    scanf("%d",&T);

    int cas =0;
    while(T--)
    {
        scanf("%I64d%I64d",&A,&B);
        ULL s1 =0,s2 = 0;
        //cout<<A-1<<endl;
        for(i=10;i<=160;i+=10)
        {
            s1 += count(A-1,i);
            //if(A==0)s1=0;
            s2 += count(B,i);
            //cout<<s1<<" "<<s2<<endl;
            //if(B==0)s2=
        }
        if(A==0)s1=0;
        else s1++;
        s2++;
        printf("Case #%d: ",++cas);
        printf("%I64d\n",s2-s1);
    }
}
