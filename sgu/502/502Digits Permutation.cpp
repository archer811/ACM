#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[20];
int ans[20];
int vis[10];
int len;
int mark[20][20][10];
bool flag;
int getans[20];
void dfs(int remain,int step)
{
    int i,j;
    if(flag)return;
   // cout<<remain<<" "<<step<<endl;
    if(step==1)
    {
       if(remain==0)
       {
           for(i=len;i>=1;i--)
              printf("%d",getans[i]);
           printf("\n");
           flag = true;
           return;
       }
       return;
    }
    for(i=0;i<=9;i++)
    {
        if(flag)return;
        int t= (remain+i*ans[step-1])%17;
        if(vis[i])
        {
            //cout<<step<<"***"<<i<<" "<<t<<" "<<ans[step-1]<<endl;
            if(mark[t][step-1][i])continue;
            mark[t][step-1][i]=1;
            //cout<<i<<" ()() "<<t<<endl;
            vis[i]--;
            getans[step-1]=i;
            dfs(t,step-1);
            mark[t][step-1][i]=0;
            if(flag)return;
            vis[i]++;
        }
    }
}
int main()
{
    int i,j,k;
    ans[1]=1;
    for(i=2;i<=18;i++)
    {
        ans[i] = ans[i-1]*10%17;
    }
    while(scanf("%s",s)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        len = strlen(s);
        for(i=0;i<10;i++)
            vis[i]=0;
        int sum=0;
        for(i=0;i<len;i++)
        {
            sum = sum + (s[i]-'0')*ans[len-i];
            //cout<<sum<<"+"<<s[i]-'0'<<" "<<ans[len-i]<<endl;
            sum %= 17;
            vis[s[i]-'0']++;
        }
        if(sum==0)
        {
            if(s[0]!='0')
            {
                printf("%s\n",s);continue;
            }
        }
        flag =false;
        for(i=1;i<10;i++)
        {
            if(vis[i])
            {
                if(flag)break;
                vis[i]--;
                getans[len]=i;
                //cout<<len<<"/////"<<i<<endl;
                mark[i*ans[len]%17][len][i]=1;
                //cout<<i<<" "<<i*ans[len]%17<<endl;
                dfs(i*ans[len]%17,len);
                vis[i]++;
            }
        }
        if(flag==false)puts("-1");
    }
}
