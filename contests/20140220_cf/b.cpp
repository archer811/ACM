#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[1000005],b[1000005],ans[1000005];
int p,x;
int judge()
{
    int i,j;
    for(i=1; i<=p; i++)
    {
        j = p+1-i;
        //cout<<a[j]<<"  "<<ans[i]<<endl;
        if(a[j]<ans[i])return 1;
        else if(a[j]>ans[i])return 0;
    }
    return 1;
}
int main()
{
    int i,j,k;

    while(cin>>p>>x)
    {
        j = 1;
        k = p;
        int f=0;
        for(i=1; i<=9; i++)
        {
            for(int t=0; t<=p; t++)
                a[t]=b[t]=0;
            a[1]=i;
            int ok=0;
            for(int t=1; t<=p; t++)
            {
                b[t]+=a[t]*x%10;
                int tmp = b[t];
                b[t]%=10;
                b[t+1]=a[t]*x/10+tmp/10;
//                if(i==4)
//                    cout<<b[t]<<" "<<b[t+1]<<endl;
                a[t+1]=b[t];
                if(b[t]>=10||a[t]>=10)ok=1;
            }
            if(ok)continue;
            if(b[p]==i&&a[p]!=0&&b[p+1]==0)
            {
//cout<<i<<endl;
//                for(int t=1; t<=p; t++)
//                    cout<<a[t]<<" ";
//                cout<<endl;
//                for(int t=1; t<=p; t++)
//                    cout<<ans[t]<<"*";
//                cout<<endl;
                if(f==0)
                {
                    f=1;

                    for(int t=p; t>=1; t--)
                        ans[p+1-t]=a[t];
//
                }

                else if(judge())
                {
                    for(int t=p; t>=1; t--)
                        ans[p+1-t]=a[t];
                }
            }
        }
        if(f==0)
            puts("Impossible");
        else
        {
            //cout<<p<<endl;
            for(int t=1; t<=p; t++)
                cout<<ans[t];
            cout<<endl;
        }
    }
}
