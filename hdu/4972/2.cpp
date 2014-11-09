#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define FFF 100005
int a[FFF];
int main()
{
    int keng,Cas=1;
    scanf("%d",&keng);
    while(keng--)
    {
        int n;
        a[0]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long ans=1;
        bool flag=true;
        for(int i=1;i<=n&&flag;i++)
        {
            if(a[i]-a[i-1]>3||a[i-1]-a[i]>3||(a[i]==a[i-1]&&a[i]!=1))
                flag=false;
            if(a[i]==2&&a[i-1]==1)
            {
                ans++;
            }
            else if(a[i]==1&&a[i-1]==2)
            {
                ans++;
            }
        }
        printf("Case #%d: ",Cas++);
        if(!flag)
            cout<<0<<endl;
        else if(a[n]!=0)
            cout<<ans*2<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
