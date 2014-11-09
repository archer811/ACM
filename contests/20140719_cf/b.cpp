#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
const int maxn = 1000006;
int a[maxn];
#define ll __int64
const ll mod=  1000000007;
ll d[2][maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(d,0,sizeof(d));

        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==1)
        {
            if(a[1]==0)cout<<1<<endl;
            else cout<<0<<endl;
            continue;
        }
        int now=1;
        d[0][a[1]]=1;d[1][a[1]]=1;
        for(i=2;i<=n;i++)
        {
            //cout<<i<<endl;
            for(j=0;j<=1000001;j++)
            {
                //if(d[1-now][j])cout<<j<<" "<<(j&a[i])<<" "<<
                  //  d[now][j&a[i]]<<" "
                   // <<d[1-now][j]<<endl;
                (d[now][j&a[i]]+=d[1-now][j])%=mod;
            }
            d[now][a[i]]+=1;
            for(j=0;j<=1000001;j++)
            {
                d[1-now][j]=d[now][j]%mod;
//                if(j<=10)
//                    cout<<j<<"*"<<d[1-now][j]<<endl;
            }
            now^=1;
        }
        cout<<d[now][0]%mod<<endl;
    }
    return 0;
}
