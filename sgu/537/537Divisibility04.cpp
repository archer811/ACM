#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
char s[20];
const int maxn = 2222222;
bool a[maxn];
int n,len,k;
int prime[maxn],p;
int use[12];
#define ll __int64
ll ant[100005];
int vis[255];
int fk;
ll ok;
int just;
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void dfs(int num,ll tmp)
{
    int i,j;
    if(ok==1)return;
    if(fk>95555) return ;
    if(num==len)
    {
        fk++;
        //cout<<tmp<<endl;
        if(ok==-1)ok=tmp;
        else ok=gcd(ok,tmp);
        return;
    }
    if(~vis[s[num]])
        dfs(num+1,tmp*(ll)10+vis[s[num]]);
    else
    {
        if(num==0)i=1;
        else i=0;
        for(; i<=9; i++)
        {
            if(use[i]==0)
            {
                use[i]=1;
                vis[s[num]]=i;
                dfs(num+1,tmp*10+i);
                vis[s[num]]=-1;
                use[i]=0;
            }
        }
    }

}
int cnt[100005];
ll lock[100005];
int fft;
void gogo(int num,ll t)
{
    //cout<<num<<" "<<t<<endl;
    if(num==fft)
    {
        ant[just++]=t;
        return;
    }
    ll tt = lock[num];
    gogo(num+1,t);
    for(int i=0; i<cnt[num]; i++)
    {
        gogo(num+1,t*tt);
        tt = tt*lock[num];
    }
}
int main()
{
    int i,j;
    p =0;
    for(i=2; i<maxn; i++)
    {
        if(!a[i])prime[p++]=i;
        for(j=i+i; j<maxn; j+=i)
            a[j]=1;
    }
    scanf("%d",&n);
    int cas=0;
    while(n--)
    {
        scanf("%s",s);
        len = strlen(s);
        for(i=0; i<11; i++)
            use[i]=0;
        memset(vis,-1,sizeof(vis));
        fk=0;
        ok = -1;
        dfs(0,0);
        //cout<<ok<<endl;
        printf("Case %d:",++cas);
        if(ok==1)
        {
            puts(" 1");
            continue;
        }
        fft=0;
        for(i=0; i<p; i++)
        {
            if(ok%prime[i]==0)
            {
                cnt[fft]=0;
                lock[fft]=prime[i];
                while(ok%prime[i]==0)
                {
                    cnt[fft]++;
                    ok/=prime[i];
                }
                fft++;
            }
        }
        if(ok!=1)
        {
            cnt[fft]=1;
            lock[fft++]=ok;
        }
        just =0;
        gogo(0,1);
        sort(ant,ant+just);
        for(i=0; i<just; i++)
        {
            printf(" %I64d",ant[i]);
        }
        puts("");
    }
}
