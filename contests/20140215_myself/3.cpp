#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
char s[3005],t[3005];
int a[1005],b[1005],an[1005],bn[1005];
int anum,bnum;
ll ans[1005][1005];
const ll mod = 10000007;
int is(char x)
{
    if(x>='A'&&x<='Z')return 1;
    return 0;
}
ll mul(ll a,ll m)
{
    ll b=  1;
    while(m)
    {
        if(m%2)b=b*a%mod;
        a = a*a%mod;
        m/=2;
    }
    return b;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%s%s",s,t);
        int len = strlen(s);
        anum =0;bnum=0;
        memset(ans,0,sizeof(ans));
        for(i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                a[anum]=s[i]-'A';
                an[anum]=0;
                int f=0;
                for(j=i+1;j<len&&is(s[j])==0;j++)
                {
                    f=1;
                    an[anum]=an[anum]*10+s[j]-'0';
                }
                if(f==0)an[anum]=-1;
                anum++;
            }
        }

//        for(i=0;i<anum;i++)
//            cout<<i<<" "<<a[i]<<" "<<an[i]<<endl;

        len = strlen(t);
        for(i=0;i<len;i++)
        {
            if(t[i]>='A'&&t[i]<='Z')
            {
                b[bnum]=t[i]-'A';
               // cout<<t[i]<<" "<<b[bnum]<<endl;
                bn[bnum]=0;
                int f=0;
                for(j=i+1;j<len&&is(t[j])==0;j++)
                {
                    f=1;
                    bn[bnum]=bn[bnum]*10+t[j]-'0';
                }
                if(f==0)bn[bnum]=-1;
                bnum++;
            }
        }

        for(i=1;i<=anum;i++)
        {
            for(j=1;j<=bnum;j++)
            {
                if(a[i-1]==b[j-1]&&an[i-1]==bn[j-1])
                {

                    ans[i][j]=(ans[i-1][j-1]*2+1)%mod;
                }
                else ans[i][j]=(ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1])%mod;
                //cout<<i<<" "<<j<<" "<<ans[i][j]<<" "<<ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]<<endl;
            }
        }

        ll t1 = mul((ll)2,(ll)anum);
        ll t2 = mul((ll)2,(ll)bnum);

        ll tmp =t1+t2-2;
        ans[anum][bnum] = ans[anum][bnum]*2%mod;
        tmp -= ans[anum][bnum];
        tmp %= mod;
        tmp += mod;
        tmp %= mod;
        printf("Case %d: %lld\n",++cas,tmp);
    }
}
