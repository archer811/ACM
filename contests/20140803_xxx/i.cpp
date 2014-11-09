#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#define ll long long
using namespace std;
const ll mod= 10007;
struct matrix
{
    ll m[2][2];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            c.m[i][j]=0;
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
                cout<<c.m[i][j]<<"*"<<i<<" "<<j<<" "<<k<<endl;
                //c.m[i][j]%=mod;
            }
            c.m[i][j]%=mod;
        }

        cout<<i<<"      "<<j<<"     "<<c.m[i][j]<<"()"<<endl;

    }
    return c;
}
matrix p(matrix a,int n)
{
    matrix b;
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            if(i==j)b.m[i][j]=1;
            else b.m[i][j]=0;
        }
    }
    while(n)
    {
        if(n&1)
            b=mul(b,a);
        a=mul(a,a);
        n/=2;
    }
    return b;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            puts("1");continue;
        }
        else if(n==2)
        {
            puts("2");continue;
        }
        matrix a;
        a.m[0][0]=1;
        a.m[0][1]=1;
        a.m[1][0]=0;
        a.m[1][1]=0;

        matrix b;
        b.m[0][0]=4;
        b.m[0][1]=0;
        b.m[1][0]=1;
        b.m[1][1]=1;
ll ans;
        if(n&1)
        {
            b = p(b,n/2);
            a = mul(a,b);
//        }
            ans = a.m[0][0];
        }
        else
        {
            n--;
            b = p(b,n/2);
            a = mul(a,b);
            ans = a.m[0][0];
            ans = ans*2%mod;
        }



        printf("%lld\n",ans);
    }
    return 0;
}
