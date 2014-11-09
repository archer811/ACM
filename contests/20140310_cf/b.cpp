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
int a[1000006];
int main()
{
    int i,j;
    int n,m;
    while(cin>>n>>m)
    {
        if(m<(n-1)||m>2*(n+1))
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(m==n-1)
        {
            for(i=0;i<n-1;i++)
                cout<<"01";
            cout<<"0"<<endl;
        }
        else if(m==n)
        {
            for(i=0;i<n;i++)
                cout<<"01";
            cout<<endl;
        }
        else
        {
            memset(a,0,sizeof(a));
            for(i=0;i<=n;i++)
                a[i]+=m/(n+1);
            int t = m/(n+1);
            m = m - t*(n+1);
            for(i=0;i<=n;i++)
            {
                if(m)
                {
                    a[i]++;m--;
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<a[i];j++)
                    cout<<"1";
                cout<<"0";
            }
            for(j=0;j<a[n];j++)
                cout<<"1";
            cout<<endl;
        }
    }
}
