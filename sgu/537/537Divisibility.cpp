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
char s[16];
const int maxn = 2222222;
bool a[maxn];
int n,len,k;
vector<int>g[12];
map<int,int>M;
int prime[maxn],p;
int v[12],ans[12];
#define ll __int64
ll index[16];
ll ant[1000005];
int vis[255];
int fk;
ll look[12];
ll ok;
int just;
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
//void dfs(int num)
//{
//    int i,j;
//    if(ok==1)return;
//    if(fk>95555) return ;
//    if(num==k)
//    {
//        ll tmp = 0 ;
//        for(i=1; i<k; i++)
//        {
//            tmp += look[i]*ans[i];
//        }
//        fk++;
//        if(ok==-1)ok=tmp;
//        else ok=gcd(ok,tmp);
//        return;
//    }
//    if(num==1)i=1;
//    else i=0;
//    for(; i<=9; i++)
//    {
//        if(v[i]==0)
//        {
//            v[i]=1;
//            //if(num==1)cout<<i<<endl;
//            ans[num]=i;
//            dfs(num+1);
//            v[i]=0;
//        }
//    }
//}
void dfs(int num,ll tmp)
{
    int i,j;
    if(ok==1)return;
    if(fk>95555) return ;
    if(num==len)
    {
        fk++;
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
            if(v[i]==0)
            {
                v[i]=1;
                vis[s[i]]=i;
                dfs(num+1,tmp*10+i);
                vis[s[i]]=-1;
                v[i]=0;
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
        if(!v[i])prime[p++]=i;
        for(j=i+i; j<maxn; j+=i)
            v[j]=1;
    }
    scanf("%d",&n);
//    index[0]=1;
    int cas=0;
//    for(i=1; i<=15; i++)
//        index[i]=index[i-1]*(ll)10;
    while(n--)
    {
        scanf("%s",s);
        len = strlen(s);
        for(i=0; i<11; i++)
            g[i].clear(),v[i]=0,look[i]=0;
        M.clear();
        memset(vis,-1,sizeof(vis));
        k = 1;
        for(i=0; i<len; i++)
        {
            int tmp = M[(int)s[i]];
            if(tmp==0)
            {
                M[(int)s[i]]=k;
                k++;
                tmp=k-1;
            }
            look[tmp]+=index[len-1-i];
            g[tmp].push_back(i);
        }
        fk=0;
        ok = -1;
        dfs(1,0);
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
