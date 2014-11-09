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
string line,str;
vector<string>a[1105];
int start[1090];
int main()
{
    int i,j,k,t;
    scanf("%d%*c",&t);
    while(t--)
    {
        int g=0;
        for(i=0;i<1105;i++)
            a[i].clear();
        memset(start,0,sizeof(start));
        while(getline(cin,line))
        {
            int len = line.length();
            if(line[0] == '@' && len == 1) break;
            istringstream in(line);
            while(in>>str)
            {
                a[g].push_back(str);
            }
            for(i=0;i<a[g].size();i++)
            {
                int tmp = a[g][i].length();
                start[i]=max(start[i],tmp);
            }
            g++;
        }
        for(i=0;i<g;i++)
        {
            for(j=0;j<a[i].size();j++)
            {
                if(j==(a[i].size()-1))
                {
                    cout<<a[i][j];break;
                }
                else
                {cout<<a[i][j];
                    for(k=0;k<start[j]-a[i][j].length();k++)
                        cout<<" ";
                    putchar(' ');

                }
            }
            cout<<endl;
        }
    }
}
