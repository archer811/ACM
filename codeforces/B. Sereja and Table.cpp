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
int k;
char s[105][105],s2[105][105];
int dfs(char *t,int v,int num,int n1,int m1,int gg)
{
    int i,j;
    if(v==n1)
    {
        //cout<<num<<"====="<<endl;
        return num;
    }

    int x=0,y=0;
    for(i=0;i<m1;i++)
    {
        if(gg==0&&t[i]!=s[v][i])x++;
        if(gg&&t[i]!=s2[v][i])x++;
        if(gg==0&&t[i]==s[v][i])y++;
        if(gg&&t[i]==s2[v][i])y++;
    }
    int ans=-1,tmp;
    char t2[105];
    if(num+x<=k)
    {
        for(i=0;i<m1;i++)
            t2[i]=t[i];
        t2[i]='\0';
        //cout<<t2<<endl;
        tmp = dfs(t2,v+1,num+x,n1,m1,gg);
        if(tmp<=k&&(ans==-1||tmp<ans))
            ans=tmp;
    }
    if(num+y<=k)
    {
        for(i=0;i<m1;i++)
            t2[i]=(char)('0'+(1-t[i]+'0'));
        t2[i]='\0';
        tmp = dfs(t2,v+1,num+y,n1,m1,gg);
        if(tmp<=k&&(ans==-1||tmp<ans))
            ans=tmp;
    }
    return ans;
}
int n,m;
int change(char *s,char *t)
{
    int su=0;
    for(int i=0;i<m;i++)
        if(s[i]!=t[i])su++;
    return su;
}
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int d;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&d);
                s[i][j]=(char)('0'+d);
            }
            s[i][j]='\0';
            //cout<<s[i]<<endl;
        }
        int ans=-1;
        for(i=0;i<n;i++)
        {
            int tmp = change(s[i],s[0]);
            if(tmp>k)continue;
            if(i>0&&tmp==0)continue;
            //cout<<i<<"@"<<tmp<<endl;
            int g2 = dfs(s[i],1,0,n,m,0);
            if(g2==-1)continue;
            tmp += g2;
            //cout<<i<<"****"<<tmp<<endl;
            if(ans==-1||tmp<ans)
                ans=tmp;
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                s2[i][j]=s[j][i];
        }

        for(i=0;i<m;i++)
        {
            cout<<s2[i]<<endl;
            int tmp = change(s2[i],s2[0]);
            if(tmp>k)continue;
            if(i>0&&tmp==0)continue;
            cout<<i<<"@"<<tmp<<endl;
            int g2 = dfs(s2[i],1,0,m,n,1);
            if(g2==-1)continue;
            tmp += g2;
            cout<<i<<"****"<<tmp<<endl;
            if(ans==-1||tmp<ans)
                ans=tmp;
        }

        printf("%d\n",ans);
    }
    return 0;
}
