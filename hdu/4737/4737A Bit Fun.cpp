#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
int sum[33],f[33][100005];
ll F[33];
int main()
{
    int i,j,k,T,n;
    F[0]=1;
    ll m;
    for(i=1;i<=31;i++)
        F[i]=F[i-1]*(ll)2;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%I64d",&n,&m);
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        ll ans =0;
        int g = 1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            j=0;
            while(k)
            {
                int tmp = j;
                f[tmp][i]=k%2;
                j++;
                k/=2;
            }
            for(j=0;j<=30;j++)
                f[j][i]+=f[j][i-1];
//            for(j=0;j<=3;j++)
//                cout<<f[j][i]<<endl;
//            cout<<endl;
            ll temp = 0;
            while(g<=i)
            {
                temp =0;
                for(j=0;j<=30;j++)
                {
                    if(f[j][i]-f[j][g-1])temp += F[j];
                   // if(i==3&&g==1&&j<=3)cout<<f[j][i]<<"&&"<<f[j][g-1]<<endl;
                }
                //if(i==3&&g==1)cout<<temp<<"ffffffffffff"<<endl;
                if(temp>=m)g++;
                else break;
            }
           // cout<<i<<" "<<g<<" "<<i-g+1<<endl;
            ans += (ll)(i-g+1);
        }
        printf("Case #%d: ",++cas);
        cout<<ans<<endl;
    }
}
