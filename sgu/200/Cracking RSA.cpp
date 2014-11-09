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
const int maxn = 501;
const int N = 1000;
int prime[N],b[N];
int a[maxn][maxn];
int rank(int m,int n)
{
    int i=0,j=0,k,r,u;
    while(i<m&&j<n)
    {
        r=i;
        for(k=i;k<m;k++)
        {
            if(a[k][j]){r=k;break;}
        }
        if(a[r][j])
        {
            if(r!=i)
                for(k=0;k<=n;k++)swap(a[r][k],a[i][k]);
            for(u=i+1;u<m;u++)
                if(a[u][j])
                for(k=i;k<=n;k++)
                a[u][k]^=a[i][k];
            i++;
        }
        j++;
    }
    return i;
}
int num;
void init()
{
    int i,j;
    for(i=2;i<N;i++)
    {
        if(b[i]==0)
        {
            prime[num++]=i;
            for(j=i+i;j<N;j+=i)
                b[j]=1;
        }
    }
}
int main()
{
    int i,j,t,m;
    num=0;
    init();
    //cout<<num<<endl;
    while(scanf("%d%d",&t,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            for(j=0;j<t;j++)
            {
                if(x<prime[j])break;
                while(x%prime[j]==0)
                {
                    a[i][j]^=1;
                    x/=prime[j];
                }
                //cout<<a[i][j]<<endl;
            }
        }
        int rk = rank(m,t);
        cout<<(1LL<<(m-rk))-1<<endl;
    }
    return 0;
}
