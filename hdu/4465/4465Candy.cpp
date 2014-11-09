#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
double P[200005],Q[200005];
int main()
{
    int n,i,j;
    double p,q;
    int cas=0;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {

        memset(P,0,sizeof(P));
        memset(Q,0,sizeof(Q));
        P[0]=Q[0]=1;
        for(i=1;i<=10;i++)
        {
            P[i]=P[i-1]*p;Q[i]=Q[i-1]*(1.0-p);
            cout<<P[i]<< " "<<Q[i]<<endl;
        }
        double d = 1,ans=0;
        for(i=0;i<10;i++)
        {
            if(i!=0)
            d = d*(n+i)*1.0/(i);
            cout<<i<<" "<<d<<" "<<P[n+1]<<" "<<Q[i]<<endl;
            ans += (n-i)*1.0*d*(P[n+1]*Q[i]+Q[n+1]*P[i]);
        }
        printf("Case %d: ",++cas);
        printf("%.6f\n",ans);
    }
}
