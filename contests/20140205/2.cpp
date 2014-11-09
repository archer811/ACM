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
ll s[24];
int sum[24],a[24],b[24],jin[24];
ll s1,s2,N;
const ll X = 4294967291;
int judgeerror()
{
    if(s1-s2!=N)return 1;
}
int main()
{
    int i,j;
    s[0]=1;
    for(i=1; i<=21; i++)
    {
        s[i]=s[i-1]*(ll)3;
    }
    ll n;
    while(cin>>n)
    {
        N = n;
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(jin,0,sizeof(jin));
        for(i=21; i>=0; i--)
        {
            if(n&&n>=s[i])
            {
                a[i]=n/s[i];
                n -= a[i]*s[i];
            }
        }
        for(i=0; i<=21; i++)
        {
            if(a[i]==0)
            {
                if(jin[i]==0)
                    b[i]=sum[i]=0;
                else
                {
                    sum[i]=1;
                    b[i]=0;
                }
            }
            else if(a[i]==1)
            {
                if(jin[i]==0)
                {
                    sum[i]=1;
                    b[i]=0;
                }
                else
                {
                    sum[i]=0;
                    b[i]=1;
                    jin[i+1]=1;
                }
            }
            else if(a[i]==2)
            {
                if(jin[i]==0)
                {
                    b[i]=1;
                    sum[i]=0;
                    jin[i+1]=1;
                }
                else
                {
                    b[i]=0;
                    sum[i]=0;
                    jin[i+1]=1;
                }
            }
        }
        s1=0,s2=0;
        for(i=0; i<=21; i++)
        {
            s1 += s[i]*sum[i];
        }
        for(i=0; i<=21; i++)
            s2 += s[i]*b[i];
        if(s2==0)
        {
            for(i=21; i>=0; i--)
            {
                if(a[i])
                {
                    i++;
                    break;
                }
            }
            s1 += s[i];
            s2+=s[i];
        }

        if(judgeerror())
        {
            cout<<"0"<<endl;return 0;
        }

        //find(N);
        cout<<s1<<" "<<s2<<endl;
    }
}
