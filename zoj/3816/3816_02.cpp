#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
int digit[22];
int x;
int a[22];
void f(ll n)
{
    x=0;
    while(n)
    {
        digit[x++] = n%10;
        n/=10;
    }
}
ll ans;
int b[22];
int vis[22][22];
int judge()
{
    int k=0,i,j;
    for(i=x-1; i>=0; i--)
    {
        if(i==x-1 || (i<x-1 && a[i]!=a[i+1]))
            b[k++]=a[i];
    }
    i=0;
    j=k-1;
    for(i=0; i<k; i++,j--)
    {
        if(b[i]!=b[j])return 0;
    }
    return 1;
}
void dfs(int s,int t,int ff)
{
    if(s==x&&t==-1)
    {
        ll sum=0;
        for(int i=x-1; i>=0; i--)
            sum = sum*10+a[i];
        if(judge())
        {
            if(ans==-1 || sum>ans)
                ans=sum;
        }

        return;
    }
    if(s-1 >= 0 && digit[s]==digit[s-1])
    {
        if(vis[s+1][t]==0)
        {
            vis[s+1][t]=1;
            dfs(s+1,t,ff);
        }

    }
    if(s>=x || t<= -1)return;
//    if(s==2&&t==0&&ff==0)
//    cout<<s<<" "<<t<<"  "<<ff<<"  "<<a[s]<<" "<<digit[t]<<endl;
    if(ff == 0 && a[s] == digit[t])
    {
        a[t] = digit[t];
        if(vis[s][t-1]==0)
        {
            vis[s][t-1]=1;
            dfs(s,t-1,ff);
        }
        if(vis[s+1][t-1]==0)
        {
            vis[s+1][t-1]=1;
            dfs(s+1,t-1,ff);
        }
    }
    else if(ff == 0 && a[s] < digit[t])
    {
        a[t] = a[s];

        for(int j = t-1; j>=-1; j--)
        {
            if(vis[s][j]==0)
            {
                vis[s][j]=1;
                dfs(s,j,1);
            }
            if(vis[s+1][j]==0)
            {
                vis[s+1][j]=1;
                dfs(s+1,j,1);
            }

            if(j>=0)
                a[j]=9;
        }
    }
    else if(ff == 1 )
    {
        a[t]=a[s];
        if(vis[s][t-1]==0)
        {
            vis[s][t-1]=1;
            dfs(s,t-1,1);
        }
        if(vis[s+1][t-1]==0)
        {
            vis[s+1][t-1]=1;
            dfs(s+1,t-1,1);
        }
    }
}
int main()
{
    int i,j,t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(vis,0,sizeof(vis));
        if(n==1)
        {
            puts("0");
            continue;
        }
        f(n);
        int flag=0;
        if(digit[0]==1&&digit[x-1]==1)
        {
            for(i=1; i<x-1; i++)
            {
                if(digit[i]!=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(i=0; i<x-1; i++)
                    printf("9");
                puts("");
                continue;
            }
        }

        n --;
        f(n);


        if(x==1)
        {
            printf("%lld\n",n);
            continue;
        }

        ans = -1;

        for(i=x-1; i>=0; i--)
        {
            for(j=x-1; j>=i; j--)
                a[j]=digit[j];
            if(digit[i]-1 >= 0)
            {
                a[i]=digit[i]-1;
                for(j=i-1; j>-1; j--)
                {
                    if(vis[i][j]==0)
                    {
                        vis[i][j]=1;
                        dfs(i,j,1);
                    }
                    if(vis[i+1][j]==0)
                    {
                        vis[i+1][j]=1;
                        dfs(i+1,j,1);
                    }

                    if(j>=0)
                        a[j]=9;
                }
            }
            a[i]=digit[i];
//cout<<i<<" "<<a[i]<<"*****"<<endl;
            if(vis[i][i-1]==0)
            {
                //vis[i][i-1]=1;
                dfs(i,i-1,0);
            }
            if(vis[i+1][i-1]==0)
            {
                //vis[i+1][i-1]=1;
                dfs(i+1,i-1,0);
            }

        }

        printf("%lld\n",ans);



    }
    return 0;
}
/*
1111111
11221
12
123
1224
1122

*/
