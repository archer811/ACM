#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[204];
int main()
{
    int i,j,k,n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int m=0;
        for(i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                m++;i++;
            }
        }
        cout<<m/2<<endl;
    }
}
