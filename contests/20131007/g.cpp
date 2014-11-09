#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
#define ll unsigned long long
int t;
unsigned long long k;
unsigned long long f[210];
char str[220][120];
int s[220];
int cmp(int a,int b)
{
    return strcmp(str[a],str[b])<0;
}
int mark[220];
char v[220][120];
int main()
{
    freopen("out.txt","w",stdout);
    int i,j,n;
    cin>>t;
    f[0]=f[1]=1;
    for(i=2;i<=20;i++)
        f[i]=f[i-1]*(unsigned long long)i;
    while(t--)
    {
        cin>>n>>k;
        memset(str,0,sizeof(str));
        memset(mark,0,sizeof(mark));
        for(i=0;i<n;i++)
            cin>>str[i],s[i]=i,mark[i]=0;
        sort(s,s+n,cmp);

        int g=1;
        for(i=0;i<n;i++)
        {
            if(i==0||strcmp(str[s[i]],str[s[i-1]])!=0)
            {
                strcpy(v[g],str[s[i]]);
                mark[g++]=1;
            }
            else mark[g-1]++;
        }
        for(i=1;i<=n;i++)
        {
            ll sum=0;
            for(j=1;j<g;j++)
            {
                if(mark[j]==0)continue;
                int tmp = 0;
                for(int t=1;t<g;t++)
                    tmp += mark[t];
                tmp -= 1;
                ll hehe = f[tmp];
                for(int t=1;t<g;t++)
                {
                    if(mark[t]==0)continue;
                    if(t==j)hehe/=f[mark[t]-1];
                    else hehe/=f[mark[t]];
                }
                sum += hehe;
                if(sum>=k)
                {
                    k -= (sum-hehe);
                    cout<<v[j];
                    mark[j]--;
                    break;
                }
            }
        }
        puts("");
    }
}
