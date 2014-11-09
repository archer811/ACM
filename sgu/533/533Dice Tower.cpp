#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
int main()
{
    while(cin>>n)
    {
        int m = n/14;
        int l = n-m*14;
        if(m==1&&l!=7)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(l>=2&&l<=12&&m>0)
            cout<<m<<endl;
        else cout<<"-1"<<endl;
    }
}
