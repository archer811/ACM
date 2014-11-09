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
        int sum=0;
        p += 2*n;
        while(sum<p)
        {
            if(sum==p)break;
            for(int k=1; k<=n; k++)
            {
                if(sum==p)break;
                for(i=1; i<=n; i++)
                {
                    if(sum==p)break;
                    j = i+k;
                    j %= n;
                    if(j==0)j=n;
                    while(j!=i)
                    {
                        if(a[j][i])break;
                        a[j][i]=a[i][j]=1;
                        //cout<<i<<"*"<<j<<endl;
                        sum++;
                        if(sum==p)break;
                    }
                    if(sum==p)break;
                }
                if(sum==p)break;
            }
            if(sum==p)break;
        }
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
                if(a[i][j])
                    cout<<i<<" "<<j<<endl;
        }
    }
}
