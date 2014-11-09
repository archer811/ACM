#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
int n;
char A[202],B[202],S[22];
int ch[2010][2];
int a[202],c[202];
int sz,fail[2010],word[2010];
const ll mod = 1000000009;
ll dp[212][3000][2];
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    word[0]=0;
}
void insert(char *s)
{
    int len = strlen(s),i,j;
    int p=0;
    for(i=0; i<len; i++)
    {
        j = s[i]-'0';
        if(ch[p][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            word[sz]=0;
            ch[p][j]=sz++;
        }
        p = ch[p][j];
    }
    word[p]=1;
}
int mark[3005][22];
int q[2010];
ll dfs(int pos,int status,int limit,int have,int sum)
{
    if(pos==-1)
    {
        //cout<<sum<<endl;
        return 1;
    }
    if(!limit&&dp[pos][sum][have]!=-1)
        return dp[pos][sum][have];
    int end = limit?a[pos]:9;
    ll ss=0;
    for(int i=0; i<=end; i++)
    {
        if(have==0&&i==0)
            ss += dfs(pos-1,0,limit&&(i==end),0,sum);
        else if(have==0&&i!=0)
        {
            if(mark[sum][i]==-1)continue;
            ss += dfs(pos-1,i,limit&&(i==end),1,mark[sum][i]);
        }
        else
        {
            if(mark[sum][i]!=-1)
            {
                ss += dfs(pos-1,i,limit&&(i==end),have,mark[sum][i]);
            }
        }
        ss %= mod;
    }
    if(!limit)return dp[pos][sum][have]=ss;
    else
    return ss;
}
ll f()
{
    int i,j=0;
    ll sum=0;
    int len = strlen(B);
    for(i=len-1; i>=0; i--)
    {
        a[j++]=B[i]-'0';
    }
    sum += dfs(j-1,0,1,0,0);
    len = strlen(A);
    for(i=0; i<len; i++)
        c[i]=A[i]-'0';
    if(c[len-1]-1<0)
    {
        for(i=len-2; i>=0; i--)
        {
            if(c[i]-1>=0)break;
        }
        c[i]-=1;
        //cout<<c[len-1]<<"*"<<endl;
        for(j=i+1; j<len-1; j++)
            c[j]+=9;
        c[len-1]+=10;
        c[len-1]-=1;
    }
    else c[len-1]-=1;
    for(i=0; i<len; i++)
        if(c[i])break;
    int k=0;
    for(j=len-1; j>=i; j--)
        a[k++]=c[j];
//    for(i=0;i<k;i++)
//        cout<<a[i];
//    cout<<endl;
    sum -= dfs(k-1,0,1,0,0);
    return sum;
}
void AC()
{
    int i,j;
    int *s=q,*e=q;
    for(i=0; i<2; i++)
        if(ch[0][i])
        {
            *e++=ch[0][i];
            fail[ch[0][i]]=0;
        }
    while(s!=e)
    {
        int u = *s++;
        for(i=0; i<2; i++)
        {
            if(ch[u][i])
            {
                fail[ch[u][i]]=ch[fail[u]][i];
                word[ch[u][i]]|=word[ch[fail[u]][i]];
                *e++=ch[u][i];
            }
            else ch[u][i]=ch[fail[u]][i];
        }
    }
}

int g[][4]= {0,0,0,0,
             0,0,0,1,
             0,0,1,0,
             0,0,1,1,
             0,1,0,0,
             0,1,0,1,
             0,1,1,0,
             0,1,1,1,
             1,0,0,0,
             1,0,0,1
            };
int judge(int x,int y)
{
    int i,j;
    if(word[x])return -1;
    int p=x;
    for(i=0;i<=3;i++)
    {
        p  = ch[p][g[y][i]];
        //if(Now==1&&Sum==1)
        //   cout<<p<<"()"<<ch[p][b[i]]<<" "<<i<<" "<<word[p]<<endl;
        for(int k=p; k>0; k=fail[k])
        {
            if(word[k])return -1;
        }
    }
    return p;
}
void init2()
{
    int i,j;
    memset(mark,-1,sizeof(mark));
    for(i=0; i<sz; i++)
    {
       // if(word[i])continue;
        for(j=0;j<=9;j++)
        {
            mark[i][j]=judge(i,j);
            //cout<<i<<" "<<j<<" "<<mark[i][j]<<endl;
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s",S);
            insert(S);
        }
        AC();
        //cout<<sz<<"@@@@"<<endl;
        init2();
        scanf("%s%s",A,B);
        ll tmp = f()%mod+mod;
        printf("%lld\n",tmp%mod);
    }
}
