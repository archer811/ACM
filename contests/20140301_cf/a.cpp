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
int main()
{
    int i,j;
    int n,p,k;
    while(cin>>n>>p>>k)
    {
        //int f=0;
        if(p-k>1)
            cout<<"<<";
        for(i=max(1,p-k);i<p;i++)
            cout<<" "<<i;
        cout<<" ("<<p<<")";
        for(i=p+1;i<=p+k&&i<=n;i++)
            cout<<" "<<i;
        if(p+k<n)
            cout<<" >>";cout<<endl;
    }
}
