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
#define ll __int64
ll A,B,n,m;
struct matrix
{
    ll c[2][2];
};
matrix mul(matrix a,matrix b)
{
    matrix d;
    d.c[0][0]=d.c[1][1]=0;
    d.c[0][1]=d.c[1][0]=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                d.c[i][j]+=a.c[i][k]*b.c[k][j];
            }
            d.c[i][j]%=m;
        }
    }
    return d;
}
matrix pow(ll tn)
{
    matrix b,a;
    b.c[0][0]=b.c[1][1]=1;
    b.c[0][1]=b.c[1][0]=0;
    a.c[0][0]=2*A%m;
    a.c[0][1]=1;
    a.c[1][0]=((B-A*A)%m+m)%m;
    a.c[1][1]=0;
    while(tn)
    {
        if(tn%2)
            b = mul(b,a);
        a = mul(a,a);
        tn/=2;
    }
    return b;
}
int main()
{
    int i,j;
    matrix thi;
    while(scanf("%I64d%I64d%I64d%I64d",&A,&B,&n,&m)!=EOF)
    {
        thi.c[0][0]=2*A%m;
        thi.c[0][1]=2;
        thi.c[1][0]=0;
        thi.c[1][1]=0;
        matrix ans = pow(n-1);
        //cout<<ans.c[0][0]<<" "<<ans.c[0][1]<<" "<<ans.c[1][0]<<" "<<
        //ans.c[1][1]<<" "<<endl;
        ans = mul(thi,ans);
        printf("%I64d\n",ans.c[0][0]%m);
    }
}
