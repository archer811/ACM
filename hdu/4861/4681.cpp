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
int fun(int a,int n,int p)
{
    int b =1;
    while(n)
    {
        if(n&1)b=b*a%p;
        a=a*a%p;
        n=n/2;
    }
    return b;
}
string f(int k,int p)
{
    int s1=0,s2=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=p-1;j++)
        {
            if(i&1)s1+=fun(j,i,p);
            else s2+=fun(j,i,p);
            s1%=p;s2%=p;
        }
    }
    cout<<k<<" "<<p<<" "<<s1<<"*"<<s2<<endl;
    if(s1>s2)return "YES";
    else return "NO";
}
int main()
{
    int i,j;
    int k,p;
    freopen("out.txt","w",stdout);
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            //if(i>j)
            cout<<i<<" "<<j<<" "<<f(i,j)<<endl;
        }
    }
    return 0;
}
