#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

char s[20];
char t[20]="100000000000000000";
int dp[131073];
long long flag[131073][17];
bool sol=false;
int len;
int dfs(int x)
{
	if (dp[x]!=-1) return dp[x];
	dp[x]=0;
	for (int i=0;i<len;i++)
	{
		if (x&(1<<i))
		{
			if (dp[x^(1<<i)]==-1000) continue;
			int tmp=dfs(x^(1<<i));
			for (int j=0;j<17;j++)
			{
				if (tmp&(1<<j))
				{
					int now=(j*10+(s[i]-'0'))%17;
					dp[x]|=(1<<now);
					flag[x][now]=flag[x^(1<<i)][j]*10ll+(s[i]-'0');
				}
			}
		}
	}
	return dp[x];
}
int main()
{
	long long n;
	while (scanf("%s",s)>0)
	{
		memset(dp,-1,sizeof(dp));
		sol=false;
		if (strcmp(s,t)==0)
		{
			puts("-1");
			continue;
		}
		len=strlen(s);
		for (int i=0;i<len;i++)
		{
			if (s[i]=='0')
			{
				dp[1<<i]=-1000;
				continue;
			}
			dp[1<<i]=(1<<(s[i]-'0'));
			flag[1<<i][s[i]-'0']=s[i]-'0';
		}
		if (dfs((1<<len)-1)&1)
		{
			sol=true;
			printf("%I64d\n",flag[(1<<len)-1][0]);
			continue;
		}
		if (!sol) cout<<"-1"<<endl;
	}
}
