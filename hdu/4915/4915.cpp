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
#define ll long long
char s[1000006];
int len,flag;
void dfs(int u,int sum)
{
    if(flag>=2)return;
    //cout<<u<<"*"<<sum<<endl;
    if(u==len)
    {
        if(sum==0)
        flag++;
        return;
    }
    if(s[u]=='(')
    {
        dfs(u+1,sum+1);
    }
    else if(s[u]==')')
    {
        if(sum-1>=0)
        dfs(u+1,sum-1);
    }
    else
    {
        dfs(u+1,sum+1);
        if(sum-1>=0)
        {
            dfs(u+1,sum-1);
        }
    }
}
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",s)!=EOF)
    {
        len = strlen(s);
        if(len==0)
        {
            puts("Unique");
            continue;
        }
        if(len%2)
        {
            puts("None");
            continue;
        }
        flag=0;
        if(s[0]=='?'||s[0]=='(')
        {
            dfs(1,1);
        }

        if(flag==0)
            puts("None");
        else if(flag==1)
        {
            puts("Unique");
        }
        else if(flag>=2)
        {
            puts("Many");
        }
    }
    return 0;
}
