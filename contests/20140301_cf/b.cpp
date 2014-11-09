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
int a[100];
#define ll __int64
ll b[55];
int main()
{
    int i,j,n;
    char s[100];
    b[0]=1;
    for(i=1;i<=50;i++)
    {
        b[i]=b[i-1]*(ll)2;
        //cout<<b[i]<<endl;
    }
    while(cin>>n)
    {
        cin>>s;
        //cout<<strlen(s)<<endl;
        for(i=0;i<n;i++)
        {
            if(s[i]=='R')a[i]=1;
            else a[i]=0;
        }
        ll sum=0;
        int g=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                //cout<<i<<" "<<b[i]<<endl;
                sum += b[i];
            }

        }
        cout<<sum<<endl;
    }
}
