
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
using namespace std;
int n,m,c,d;
char s[105][22];
#define ll long long
ll dp[3025][22];
const ll mod = 1000000007;
void dfs(int pos,int fro,int now,int num)
{
    if(num>d)return;
    if(pos==m)
    {
        (dp[now][num] += 1)%=mod;
        return ;
    }
    if(((1<<pos)&fro)==0)
    {
        if(((1<<pos)&now)==0)
        {
            dfs(pos+1,fro,now|(1<<pos),num);
        }
    }
    else
    {
        if(((1<<pos)&now)==0)
        {
            if(pos>=1&&(((1<<(pos-1))&now)==0))
            {
                dfs(pos+1,fro,now|(1<<pos)|(1<<(pos-1)),num);
            }
            dfs(pos+1,fro,now|(1<<pos),num+1);
            dfs(pos+1,fro,now,num);
        }
    }
}
struct array
{
    int y,num;
    ll ant;
} o;
vector<array>t[3025];
ll f[2][3025][22];
int main()
{
    int i,j,k;
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d%d",&n,&m,&c,&d)!=EOF)
    {
        int mm = (1<<m)-1;
        for(i=0; i<(1<<m); i++)
        {
            for(j=0; j<(1<<m); j++)
                for(k=0; k<=d; k++)
                    dp[j][k]=0;
            t[i].clear();
            dfs(0,i,0,0);
            for(j=0; j<(1<<m); j++)
                for(k=0; k<=d; k++)
                {
                    if(dp[j][k])
                    {
                        o.y=j;
                        o.num=k;
                        o.ant=dp[j][k];
                        t[i].push_back(o);
                    }
                }
        }
        for(i=1; i<=n; i++)
            scanf("%s",s[i]);
        memset(f,0,sizeof(f));
        f[0][mm][0]=1;
        int now=1;
        for(i=1; i<=n; i++)
        {
            int sum=0;
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='0')sum+=(1<<j);
            }
            for(j=0; j<=mm; j++)
            {
                for(int g=0; g<=d; g++)
                {
                    // cout<<1-now<<" "<<j<<" "<<g<<" "<<f[1-now][j][g]<<endl;
                    if(f[1-now][j][g]==0)continue;

                    for(k=0; k<t[j].size(); k++)
                    {
                        int y = t[j][k].y;
                        int Num = t[j][k].num;
                        ll ant = t[j][k].ant;
                        if(y&sum)continue;
                        y|=sum;
                        //if(Num+g>d)continue;
                        (f[now][y][Num+g] += f[1-now][j][g]*ant)%=mod;
//                            cout<<now<<" "<<j<<" "<<g<<" "<<y<<" "
//                            << Num+g<<" "<<f[now][y][Num+g]<<
//                            " "<<ant<<endl;
                    }
                }
            }
            for(j=0; j<=mm; j++)
                for(k=0; k<=d; k++)
                    f[1-now][j][k]=0;
            //cout<<1-now<<" "<<f[0][3][0]<<"()"<<endl;
            now = 1-now;
        }
        ll sum=0;
        now = 1-now;
        for(i=c; i<=d; i++)
        {
            //cout<<i<<"@@"<<f[now][0][i]<<endl;
            if(f[now][mm][i]!=0)
                sum = (sum+f[now][mm][i])%mod;
        }
        //printf("%lld\n",sum);
        cout<<sum<<endl;
    }

}

