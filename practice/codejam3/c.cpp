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
char s[103][105];
char t[105];
int num[105];
int m[105][105];
int vis[105];
int main()
{
    int i,j;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int cas=0,t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",t);
            int len = strlen(t);
            num[i]=0;
            s[i][num[i]++]=t[0];
            for(j=1;j<len;j++)
            {
                if(t[j]==t[j-1])continue;
                s[i][num[i]++]=t[j];
            }
        }
        memset(m,0,sizeof(m));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][num[i]-1]==s[j][0])m[i][j]=1;
            }
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            int g=0;
            for(j=0;j<n;j++)
                if(m[i][j])g++;
            if(g>=2){flag=1;break;}
        }
        if(flag==0)
        {
            for(i=0;i<n;i++)
            {

            }
        }
    }
    return 0;
}
