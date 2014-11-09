#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[500000];
int main()
{
    int i,j,k,n;
    while(cin>>n>>k)
    {
        if(k==0)
        {
            for(i=n*2;i>=1;i--)
                cout<<i<<" ";
            cout<<endl;
            continue;
        }
        cout<<1<<" "<<1+k<<" ";
        j = n*2;
        a[1]=1;a[1+k]=1;
        while(j>=1)
        {

            if(a[j]){j--;continue;}
            cout<<j<<" ";
            a[j]=1;
            j--;
        }
        cout<<endl;
    }
}
