#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
ll a;
char s[40004];
ll num[400400];
int main()
{
    ll i,j,k;
    while(cin>>a)
    {
        cin>>s;
        memset(num,0,sizeof(num));
        int len  = strlen(s);
        ll all=0;
        for(i=0;i<len;i++)
        {
            int sum=0;
            for(j=i;j>=0;j--)
            {
                sum += s[j]-'0';
                num[sum]++;
                all++;
            }
        }
        if(a==0)
        {
            cout<<num[0]*all*2-num[0]*num[0]<<endl;
            continue;
        }
        //cout<<a<<endl;
        ll sum=0,temp=0;
        for(i=1;i<=sqrt(a);i++)
        {
            //cout<<i<<endl;
            if(a%i==0&&i<=40040&&a/i<=40040)
            {
                if(i==a/i)temp=num[i]*num[a/i];
                sum += num[i]*num[a/i];
               // cout<<i<<" "<<a/i<<" "<<num[i]*num[a/i]<<endl;
            }
        }
        cout<<sum*2-temp<<endl;
    }
}
