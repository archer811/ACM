#include<functional>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
int T;
string str, tmp;
vector<string> g[1010];
int len[1010];
int main()
{
    int i,j,k;
    scanf("%d%*c", &T);
    while(T--)
    {
        for(i=0;i<1010;i++) g[i].clear();
        int cnt = 0, maxsize = 0;
        memset(len,0,sizeof(len));
        while(getline(cin,str))
        {
            int lll = str.length();
            if(str[0] == '@' && lll == 1) break;
            istringstream in(str);
            int sz = 0;
            while(in >> tmp)
            {
                g[cnt].push_back(tmp);
            }
            for(i=0;i<g[cnt].size();i++)
            {
                int tmp = g[cnt][i].length();
                len[i]=max(len[i],tmp);
            }
            if(g[cnt].size() > maxsize) maxsize = g[cnt].size();
            cnt++;
        }

        for(i=0;i<cnt;i++)
        {
            for(j=0;j<g[i].size();j++)
            {
                if(g[i].size()==j+1)
                {
                    cout<<g[i][j];
                    break;
                }
                else
                {
                    cout<<g[i][j];
                    int tmp = len[j] - g[i][j].size();
                    while(tmp--) putchar(' ');
                }
                putchar(' ');
            }
            puts("");
        }
    }
    return 0;
}
