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
int n,k;
int a[1005],b[1005];
int main()
{
    int i,j;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
        int ans=1005,f=-1;
        for(i=1;i<=1000;i++)
        {
            b[1]=i;
            for(j=2;j<=n;j++)
                b[j]=b[j-1]+k;
            int sum=0;
            for(j=1;j<=n;j++)
                if(b[j]!=a[j])sum++;
            if(sum<ans)
            {
                ans=sum;f=i;
            }
        }
        b[1]=f;
        for(j=2;j<=n;j++)
            b[j]=b[j-1]+k;
        cout<<ans<<endl;
        for(i=1;i<=n;i++)
        {
            if(b[i]>a[i])
            {
                cout<<"+ "<<i<<" "<<b[i]-a[i]<<endl;
            }
            else if(b[i]<a[i])
            {
                cout<<"- "<<i<<" "<<a[i]-b[i]<<endl;
            }
        }
    }
}
