#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cmath>
#include<queue>rl
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char str[2000], tmp[2000];
vector<string>g[1105];
int len[1090];
int main()
{
    int i,j,k,t;
    scanf("%d%*c",&t);
    while(t--)
    {
        int cnt=0;
        for(i=0;i<1105;i++)
            g[i].clear();
        memset(len,0,sizeof(len));
        int num=0;
        while(gets(str))
        {
            int lll = strlen(str);
            if(lll==1&&str[0]=='@')break;
            istringstream in(str);
            int sz=0;
            while(in>>tmp)
            {
                g[cnt].push_back(tmp);
                len[sz] = max(len[sz], (int)strlen(tmp));
                sz++;
            }
            if(g[cnt].size()>num)num=g[cnt].size();
            cnt++;
        }
        for(i=0;i<cnt;i++)
        {
            int nc = g[i].size();
            for(j=0;j<nc;j++)
            {
                //if(nc<j+1)break;
               if(nc==j+1)
                {
                    cout<<g[i][j];
                    break;
                }
                else
                {
                    cout<<g[i][j];
                    int tmp = len[j] - g[i][j].size();
                    while(tmp--) putchar(' ');
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
}
