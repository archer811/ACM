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
int n;
#define ll __int64
const int maxn = 1005;
int input[maxn][maxn];
string ans;
const ll mod = 2;
ll a[maxn][maxn],b[maxn][maxn],x[maxn];
int num[(1<<20)+1];
ll getans()
{
    int i,j;
    ll tmp=0;
    for(int k=1; k<=n; k++)
    {
        for(i=0; i<n/20; i++)
        {
            int g = a[k][i]^b[k][i];

            tmp = tmp+num[g];
            tmp %= mod;
        }
        int g = a[k][n/20]^b[k][n/20];
        //cout<<g<<"  "<<num[g]<<endl;
        tmp = tmp + num[a[k][n/20]^b[k][n/20]];
        tmp %=mod;
    }
    return tmp;
}
void change1(int d)
{
    int i,j;
    for(i=0; i<n/20; i++)
    {
        a[d][i]^=x[i];
    }
    a[d][n/20]^=x[n/20];
    cout<<a[d][n/20]<<"*"<<endl;
}
void change2(int d)
{
    int i,j;
    for(i=0; i<n/20; i++)
    {
        b[d][i]^=x[i];
    }
    b[d][n/20]^=x[n/20];
}
int main()
{
    int i,j;
    ll M=0;
    for(i=0; i<20; i++)
        M=M*(ll)2+1;
    for(i=1;i<(1<<20);i++)
    {
        if(i&1)
            num[i]=num[i/2]+1;
        else
            num[i]=num[i/2];
    }
//    for(i=0;i<=10;i++)
//        cout<<i<<" "<<num[i]<<endl;
    while(scanf("%d",&n)!=EOF)
    {
        ans="";
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%d",&input[i][j]);
        }
        //cout<<M<<endl;
        for(i=0; i<n/20; i++)
            x[i]=M;
        ll N =0;
        j = n/20;
        j = j*20;
        for(i=j; i<n; i++)
            N = N*(ll)2+1;
        x[n/20]=N;
        //cout<<N<<endl;

        for(i=1; i<=n; i++)
        {
            int tmp=1;
            for(j=0; j<n/20; j++)
            {
                N = 0;
                for(int t=0; t<20; t++)
                {
                    N = N*(ll)2+input[i][tmp];
                    tmp++;
                }
                a[i][j]=N;
            }
            N=0;
            int k = n/20;
            k = k*20;
            for(j=k; j<n; j++)
                N = N*(ll)2+input[i][j+1];
            a[i][n/20]=N;
        }



        for(i=1; i<=n; i++)
        {
            int tmp=1;
            for(j=0; j<n/20; j++)
            {
                N = 0;
                for(int t=0; t<20; t++)
                {
                    N = N*(ll)2+input[tmp][i];
                    tmp++;
                }
                b[i][j]=N;
            }
            N=0;
            for(j=tmp; j<=n; j++)
                N = N*(ll)2+input[j][i];
            b[i][n/20]=N;
        }



        for(i=1;i<=n;i++)
        {
            cout<<a[i][0]<<" "<<a[i][1]<<endl;
        }

        int m;
        scanf("%d",&m);
        int d1,d2;
        while(m--)
        {
            scanf("%d",&d1);
            if(d1==3)
            {
                ans += (char)(getans()+'0');
                cout<<"()"<<(getans())<<endl;
            }
            else
            {
                scanf("%d",&d2);
                if(d1==1)
                    change1(d2);
                else
                    change2(d2);
            }
        }
        cout<<ans<<endl;
    }
}
