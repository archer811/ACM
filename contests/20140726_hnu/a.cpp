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
vector<int>v[1005];
string s[1005];
int in[1005];
void dfs(int u,int num)
{
    int i,j;
    for(j=0; j<num; j++)
        printf(".");
    cout<<s[u]<<endl;
    for(i=0; i<v[u].size(); i++)
    {

        dfs(v[u][i],num+1);
    }
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
            v[i].clear(),in[i]=0;
        for(i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);
            if(k!=0)
                v[k].push_back(i),in[i]++;
            cin>>s[i];
        }
        for(i=1; i<=n; i++)
        {
            if(in[i]==0)
            {
                //cout<<i<<"*"<<endl;
                dfs(i,0);
            }
        }
    }
    return 0;
}
