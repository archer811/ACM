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
#define ll long long
ll c[22][22];
int main()
{
    int i,j,t,k;
    for(i=0;i<22;i++)
    {
        c[i][i]=c[i][0]=1;
    }
    for(i=1;i<22;i++)
    {
        for(j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    cout<<c[21][13]<<endl;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        int n,m;
        scanf("%d%d",&n,&m);
        ll sum=1;
        for(i=n;i>n-m;i--)
            sum = sum*(ll)i;
        int flag=1;
        for(i=1;i<=m;i++)
        {
            ll tmp = c[m][i];
            for(j=n-i;j>n-m;j--)
            {
                tmp = tmp*(ll)j;
            }
            if(flag)
            sum -= tmp;
            else sum += tmp;
            flag^=1;
        }
        for(i=n-m;i>=1;i--)
            sum = sum*(ll)i;
        printf("%d %lld\n",k,sum);
    }
    return 0;
}
