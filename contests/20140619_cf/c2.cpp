#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
#include<ctime>
using namespace std;
struct array
{
    int x,y;
}s[105];
char g[10];
int f(char t)
{
    if(t=='R')return 0;
    else if(t=='G')return 1;
    else if(t=='B')return 2;
    else if(t=='Y')return 3;
    else if(t=='W')return 4;
    else if(t=='1')return 5;
    else if(t=='2')return 6;
    else if(t=='3')return 7;
    else if(t=='4')return 8;
    else if(t=='5')return 9;
}
int cmp(array a,array b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int v[105];
map<int,int>M;
int num[1025];
int mp[15][15];
int main()
{
    int i,j,n;
    for(i=1;i<1024;i++)
    {
        if(i&1)num[i]=num[i/2]+1;
        else num[i]=num[i/2];
        //if(i<=10)cout<<i<<" "<<num[i]<<endl;
    }
    while(scanf("%d",&n)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        for(i=0;i<n;i++)
        {
            scanf("%s",g);
            s[i].x=f(g[0]);
            s[i].y=f(g[1]);
            mp[s[i].x][s[i].y]++;
            //cout<<s[i].x<<" "<<s[i].y<<endl;
        }
        for(i=0;i<5;i++)
        {
            int ss=0;
            for(j=5;j<10;j++)
            {
                if(mp[i][j])ss++;
            }
            if(ss==0)continue;
            if(ss==1)
            {
                for(j=5;j<10;j++)
                    if(mp[i][j])mp[i][j]=1;
            }
        }
        for(j=5;j<10;j++)
        {
            int ss=0;
            for(i=0;i<5;i++)
                if(mp[i][j])ss++;
            if(ss==0)continue;
            if(ss==1)
            {
                for(i=0;i<5;i++)
                    if(mp[i][j])mp[i][j]=1;
            }
        }
        n=0;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                for(int k=0;k<min(1,mp[i][j]);k++)
                {
                    s[n].x=i;s[n++].y=j;
                }
            }
        }
        sort(s,s+n,cmp);
        int flag=0;
        for(i=1;i<n;i++)
        {
            if(s[i].x!=s[i-1].x||s[i].y!=s[i-1].y)flag=1;
        }
        if(flag==0)
        {
            puts("0");continue;
        }
        int ans=10;
        for(i=0;i<1024;i++)
        {
            for(j=0;j<n;j++)
                v[j]=0;
            for(j=0;j<n;j++)
            {
                for(int k=0;k<10;k++)
                {
                    if((i&(1<<k))==0)continue;
                    if(s[j].x==k||s[j].y==k)
                        v[j]|=(1<<k);
                }
            }
            M.clear();
            for(j=0;j<n;j++)
            {
                if(M[v[j]]!=0)break;
                M[v[j]]++;
            }
            if(j==n)
            {
                if(ans>num[i])ans=num[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
