#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int mod = 1e9+7;
#define ll long long
const int maxn = 2005;
char s[maxn];
int d[maxn][maxn],b[maxn][maxn];
int n,k;
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        scanf("%s",s);
        int tmp = n*(n+1)/2;
        if(k>tmp)
        {
            puts("0");continue;
        }
        memset(d,-1,sizeof(d));
        d[n][1]=26-(s[n-1]-'a'+1);
        d[n][0]=26-d[n][1]-1;
        cout<<d[n][1]<<" "<<d[n][0]<<endl;
        b[n][0]=1;
        for(i=n-1;i>=1;i--)
        {
            int big = 26-(s[i-1]-'a'+1);
            int num = n+1-i;
            for(j=0;j<=tmp-num;j++)
            {
                if(d[i+1][j]!=-1)
                {
                    if(d[i][j+num]==-1)d[i][j+num]=(ll)d[i+1][j]*(ll)big%mod;
                    else d[i][j+num]+=(ll)d[i+1][j]*(ll)big%mod;
                    cout<<i<<"f"<<j+num<<" "<<d[i+1][j]<<"*"<<big<<endl;
                }
            }
            for(j=0;j<=tmp;j++)
                b[i][j]=d[i+1][j],d[i][j]=d[i+1][j];

        }
        cout<<d[1][k]<<" "<<b[1][k]<<endl;
    }
}
