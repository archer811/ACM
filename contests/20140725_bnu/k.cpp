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
int f[1000];
int main()
{
    int i,j;
    int n,m;
    while(cin>>n>>m)
    {
        int M = 1<<n;
        int s=0;
        for(i=0; i<M; i++)
        {
            int sum=0;
            for(j=0; j<n; j++)
            {
                if(i&(1<<j))f[j]=1;
                else f[j]=0;
            }
//            cout<<i<<endl;
//            for(j=0;j<n;j++)
//                cout<<f[j];
//            cout<<endl;
            for(j=1;j<n;j++)
            {
                if(f[j])f[j]=f[j-1]+1;
                else f[j]=0;
            }
            int f2=0;
            for(j=0;j<n;j++)
                if(f[j]>=m)f2=1;
            s+=f2;
            //cout<<i<<" "<<sum<<endl;
        }
        cout<<s<<endl;
    }

    return 0;
}
