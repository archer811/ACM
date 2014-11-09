#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll a[12];
const int N = 14;
struct matrix
{
    ll a[N][N];
    void init()
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                a[i][j]=0;
            }
        }
    }
    void output()
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout<<a[i][j]<<"\t\t";
            cout<<endl;
        }
        cout<<endl;
    }
};
const ll mod = 10000007;
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            c.a[i][j]=0;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            for(int k=0; k<N; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
            }
            c.a[i][j] %= mod;
        }
    }
    return c;
}
matrix _pow(matrix a,ll n)
{
    matrix b;
    b.init();
    int i,j;
    for(i=0; i<N; i++)
        b.a[i][i]=1;
    while(n)
    {
        if(n%2)b=mul(b,a);
        a=mul(a,a);
        n>>=1;
    }
    return b;
}
int ant[10][10];
int main()
{
    int i,j,n,m;
    freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        matrix ans;
        ans.init();
        ll now = 233;
        for(i=1; i<=n; i++)
        {
            ans.a[i-1][i]=a[i];
        }
        for(i=0; i<=n+1; i++)
        {
            ans.a[i][0]=now;
            now = now*10+3;
            if(i>=1)
                for(j=1; j<=i; j++)
                {
                    ans.a[i][j]=ans.a[i-1][j]+ans.a[i-1][j-1];
                }
            ans.a[i][n+1]=1;
        }
        matrix b;
        b.init();
        b.a[0][0]=10;
        b.a[n+1][0]=3;
        for(j=1; j<=n; j++)
        {
            b.a[j-1][j]=b.a[j][j]=1;
        }
        b.a[n+1][n+1]=1;
        b = _pow(b,(m-n));
        cout<<"*"<<endl;
         b.output();
         cout<<"()"<<endl;
        matrix oo = mul(ans,b);
        oo.output();
        printf("%lld\n",oo.a[n+1][n]);
    }
    return 0;
}
