#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[3003];
int main()
{
    int i,j,k;
    int n;
    while(cin>>n>>k)
    {
        for(i=1;i<=k;i++)
            cin>>a[i];
        sort(a+1,a+1+k);
        bool flag=false;
        if(a[1]==1||a[1]==n)flag=true;
        if(a[2]==1||a[2]==n)flag=true;
        for(i=3;i<=k;i++)
        {
            if(a[i]==1||a[i]==n)flag=true;
            if(a[i-1]==a[i]-1&&a[i-2]==a[i]-2)
            {
                flag=true;break;
            }
        }
        if(flag)puts("NO");
        else puts("YES");
    }
}
