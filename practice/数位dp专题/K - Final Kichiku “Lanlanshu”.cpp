#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[101],A[101],B[101];
int a[101],b[101],la,lb,g[101];
#define ll __int64
const ll mod = (ll)100000000;
int Len;
ll dp[101][11][101][11];
int Num[101];
ll dfs(int pos,int status,int now,int num,int limit,int have,int xx,int pre)
{
    if(pos==-1)
    {
        return now >= Len;
    }
    if(!limit&&dp[pos][status][now][have]!=-1)
    {
        return dp[pos][status][now][have];
    }
    int end = limit?a[pos]:9;
    ll sum=0;
    for(int i=0; i<=end; i++)
    {
        if(have==0&&i!=0)
        {
            sum +=  dfs(pos-1,i,0,0,limit&&(i==end),1,xx*10+i,status);
        }
        else if(have==0&&i==0)
            sum += dfs(pos-1,0,0,0,limit&&(i==end),0,xx*10+i,status);
        else
        {
            int tmp;
            if(i>status)tmp = 1;
            else if(i<status)tmp=-1;
            else tmp=0;

            if(tmp==g[now])
            {
                if(now<Len)
                    sum += dfs(pos-1,i,now,num+1,limit&&(i==end),1,xx*10+i,status);

                if(now<Len&&num+1>=Num[now])
                    sum += dfs(pos-1,i,now+1,0,limit&&(i==end),1,xx*10+i,status);
                sum %= mod;
            }
        }
        sum %= mod;
    }
    sum %= mod;
    if(!limit)
    {
        cout<<pos<<" "<<status<<" "<<now<<" "<<have<<" "<<sum<<endl;
        return dp[pos][status][now][pre]=sum;
    }

    return sum;
}
ll f()
{
    la=0;
    lb=0;
    int len = strlen(s);
    int i,j;
    for(i=0; i<len; i++)
    {
        if(s[i]=='/')g[i]=1;
        else if(s[i]=='-')g[i]=0;
        else g[i]=-1;
    }
    j=0;
    Num[0]=1;
    for(i=1; i<len; i++)
    {
        if(g[i]==g[j])
        {
            Num[j]++;
            continue;
        }
        Num[++j]=1;
        g[j]=g[i];
    }
    Len = j+1;
//    for(i=0;i<Len;i++)
//    {
//        cout<<i<<"*"<<g[i]<<" "<<Num[i]<<endl;
//    }
    memset(dp,-1,sizeof(dp));
    len = strlen(B);
    int t;
    for(t=0; t<len; t++)
        if(B[t]!='0')break;
    for(i = len-1; i>=t; i--)
        a[la++]=B[i]-'0';
    ll tmp =  dfs(la-1,0,0,0,1,0,0,0);
    cout<<tmp<<endl;
    len = strlen(A);
    for(i=0; i<len; i++)
        b[i]=A[i]-'0';
    i = len-1;
    // cout<<b[i]<<" *** "<<endl;
    if(b[i]-1<0)
    {
        int k;
        int fl = 0;
        for(k=i-1; k>=0; k--)
        {
            if(b[k]-1>=0)
            {
                fl = 1;
                break;
            }
        }
        if(fl==0)return tmp;
        //cout<<i-1<<" "<<k<<endl;
        b[k]-=1;
        for(j=k+1; j<=i; j++)
            b[j]+=9;
    }
    else b[i]-=1;

    bool flag=false;
    int k;
    for(k=0; k<len; k++)
    {
        if(b[k])break;
    }
    for(i = len-1; i>=k; i--)
    {
        a[lb++]=b[i];
    }
//    for(i=0; i<lb; i++)
//        cout<<a[i];
//    cout<<endl;
    ll tmp2 = dfs(lb-1,0,0,0,1,0,0,0);
    cout<<tmp<<" "<<tmp2<< "  "<<tmp-tmp2<<" "<<(tmp-tmp2)%mod<<endl;
    return tmp-tmp2;
}
void output(ll tmp)
{
    int ft[10]= {0},i,j=0;
    while(tmp)
    {
        ft[j++]=tmp%10;
        tmp/=10;
    }
    for(i=7; i>=0; i--)
        printf("%d",ft[i]);
    puts("");
}
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    while(scanf("%s%s%s",s,A,B)!=EOF)
    {
        //f();
        ll tmp = (f()%mod+mod)%mod;
        output(tmp);
        //cout<<tmp<<endl;
    }
}
