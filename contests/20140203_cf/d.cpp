#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int n,s[101];
int main()
{
    int i,j;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>s[i];
        int a = s[0];
        for(i=1;i<n;i++)
            a = gcd(a,s[i]);
        cout<<a*n<<endl;
    }
}
