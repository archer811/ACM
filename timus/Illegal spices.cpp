#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,k;
int p;
#define ll __int64
int a[100006];
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&k,&p)!=EOF)
    {
        for(i=1;i<=n;i++)
            a[i]=1;
        int x,y;
        x=1;y=0;
        for(i=n-k+1;i<=n;i++)
        {
            //cout<<i<<" "<<x<<" "<<y<<endl;
            if(y*100>=p*(i-1))
            {
                a[i]=x;
            }
            else
            {
                x++;y=i-1;
                a[i]=x;
            }
        }
        ll sum=0;
        for(i=1;i<=n;i++)
            sum += (ll)a[i];
        cout<<sum<<endl;
        for(i=1;i<=n;i++)
        {
            printf("%d",a[i]);
            if(i<n)printf(" ");
            else printf("\n");
        }
    }
}
