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
int A[60],B[60],K[60];
int a,b,k;
#define ll long long
void Get()
{
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(K,0,sizeof(K));
    int j=0;
    while(a)
    {
        A[j++]=a%2;a/=2;
    }
    j=0;
    while(b)
    {
        B[j++]=b%2;b/=2;
    }
    j=0;
    while(k)
    {
        K[j++]=k%2;k/=2;
    }
}
ll dp[33][2][2][2][2][2][2];
ll dfs(int pos,int st1,int lim1,int st2,int lim2,int st3,int lim3,int x,int y,int z)
{
    //cout<<pos<<" "<<st1<<" "<<st2<<" "<<st3<<endl;
    if(pos==-1)
    {
       // cout<<"()"<<" "<<y<<" "<<z<<" "<<x<<endl;
        return 1;
    }

    if(dp[pos][st1][lim1][st2][lim2][st3][lim3]!=-1)
        return dp[pos][st1][lim1][st2][lim2][st3][lim3];
    int end1=lim1?K[pos]:1;
    int end2=lim2?A[pos]:1;
    int end3=lim3?B[pos]:1;
    //cout<<pos<<"!"<<end1<<" "<<end2<<" "<<end3<<endl;
    //if(pos==1)cout<<"@@@@"<<K[pos]<<" "<<end1<<endl;
    ll sum=0;
    for(int i=0;i<=end1;i++)
    {
        if(i==0)
        {
            if(end2>=0&&end3>=0)
            {
                sum += dfs(pos-1,i,lim1&&(i==end1),0,lim2&&(0==end2),0,lim3&&(0==end3),x*2+i,y*2,z*2);
            }
            if(end2>=1&&end3>=0)
            {
                sum += dfs(pos-1,i,lim1&&(i==end1),1,lim2&&(1==end2),0,lim3&&(0==end3),x*2+i,y*2+1,z*2);
            }
            if(end2>=0&&end3>=1)
            {
                sum += dfs(pos-1,i,lim1&&(i==end1),0,lim2&&(0==end2),1,lim3&&(1==end3),x*2+i,y*2,z*2+1);
            }
        }
        else
        {
            if(end2>=1&&end3>=1)
            {
                sum += dfs(pos-1,i,lim1&&(i==end1),1,lim2&&(1==end2),1,lim3&&(1==end3),x*2+1,y*2+1,z*2+1);
            }
        }
    }
    return dp[pos][st1][lim1][st2][lim2][st3][lim3]=sum;
    return sum;
}
int main()
{
    int i,j,t;
         freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&k);
        a--;b--;k--;
        Get();
        memset(dp,-1,sizeof(dp));
        ll ans = dfs(32,0,1,0,1,0,1,0,0,0);
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
