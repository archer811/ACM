#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
#define ll long long
ll a[30];
int cnt;
ll ans;ll n;
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void DFS(int index,ll lim,int num)
{
    lim = lim/gcd(a[index],lim)*a[index];
    if(num&1)
        ans += (n-1)/lim;
    else
        ans -= (n-1)/lim;
    for(int i=index+1;i<cnt;i++)
        DFS(i,lim,num+1);
}
int main()
{
    int i,j;

    int m;
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        int x;
        while(m--)
        {
            scanf("%d",&x);
            if(x!=0)    //除0
                a[cnt++]=x;
        }
        ans=0;
        for(int i=0; i<cnt; i++)
            DFS(i,a[i],1);
        cout<<ans<<endl;
    }
    return 0;
}
