#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 300005;
int x[maxn],w[maxn];
int n,d;
int Max[maxn];
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&x[i],&w[i]);
        Max[n]=n;
        for(i=n-1;i>=1;i--)
        {
            if(w[i]>w[Max[i+1]])
                Max[i]=i;
            else Max[i]=Max[i+1];
        }
        int a=-1,b=-1,ans=-1;
        j=1;
        for(i=1;i<=n;i++)
        {
            while(x[j]-x[i]<d&&j<=n)
                j++;

            //cout<<i<<" () "<<j<<endl;
            if(j<=n&&x[j]-x[i]>=d)
            {
                if(w[i]+w[Max[j]]>ans)
                {
                    ans=w[i]+w[Max[j]];
                    a=i;b=Max[j];
                }
            }
            else break;
        }
        printf("%d %d\n",a,b);
    }
}
