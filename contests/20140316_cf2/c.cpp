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
int a[100][100];
int main()
{
    int i,j;
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        memset(a,0,sizeof(a));
        cin>>n>>p;
        if(n%2)
        {
            for(i=1; i<=2; i++)
            {
                j=1;
                int pre=j;
                for(int k=1; k<=n; k++)
                {
                    j += i;
                    j%=n;
                    if(j==0)j=n;
                    a[pre][j]=a[j][pre]=1;
                    cout<<pre<<"*"<<j<<endl;
                    pre=j;
                }
            }
            int sum=0;
            while(sum<p)
            {
                j = 1;
                int pre=j;
                for(int k=1; k<=n; k++)
                {
                    j += i;
                    j%=n;
                    if(j==0)j=n;
                    a[pre][j]=a[j][pre]=1;
                    pre=j;
                    sum++;
                    if(sum==p)break;
                }
                if(sum==p)break;
            }
        }
        else
        {

            for(i=1;i<n;i++)
                a[i][i+1]=a[i+1][i]=1;
            a[n][1]=a[1][n]=1;

            for(i=1;i<=n-3;i+=2)
                a[i][i+2]=a[i+2][i]=1;
            a[n-1][1]=a[1][n-1]=1;

            for(i=2;i<=n-2;i+=2)
                a[i][i+2]=a[i+2][i]=1;
            a[n][2]=a[2][n]=1;
            int sum=0;
//for(i=1; i<=n; i++)
//        {
//            for(j=i+1; j<=n; j++)
//                if(a[i][j])
//                    cout<<i<<" "<<j<<endl;
//        }

//        cout<<endl;
            while(sum<p)
            {
                if(sum==p)break;
                for(int k=3;k<=n;k++)
                {
                    if(sum==p)break;
                    for(i=1;i<=n;i++)
                    {
                        if(sum==p)break;
                        j = i+k;
                        j %= n;
                        if(j==0)j=n;
                        while(j!=i)
                        {
                            if(a[j][i])break;
                            a[j][i]=a[i][j]=1;
                            sum++;
                            if(sum==p)break;
                        }
                        if(sum==p)break;
                    }
                    if(sum==p)break;
                }
                if(sum==p)break;
            }

        }

        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
                if(a[i][j])
                    cout<<i<<" "<<j<<endl;
        }
    }
}