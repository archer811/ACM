#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
char s[101][101];
int vis[101][101];
int judge(int a,int b)
{
    if(s[a][b]!='#')return 0;
    if(a<=0)return 0;
    if(a<=0||b<=0||a>=n-1||b>=n-1)return 0;
    if(s[a-1][b]!='#')return 0;
    if(s[a][b-1]!='#')return 0;
    if(s[a+1][b]!='#')return 0;
    if(s[a][b+1]!='#')return 0;
}
void fun(int a,int b)
{
    vis[a][b]++;
    vis[a-1][b]++;
    vis[a][b-1]++;
    vis[a+1][b]++;
    vis[a][b+1]++;
}
int flag=0;
void f(int a,int b)
{
    if(a+2>=n){flag = 1;return;}
    if(b-1<0){flag = 1;return;}
    if(b+1>=n){flag = 1;return;}
    //cout<<a<<" "<<b<<endl;
    if(s[a+1][b]!='#')flag = 1;
    s[a+1][b]='.';
    if(s[a+1][b-1]!='#')flag = 1;
    s[a+1][b-1]='.';
    if(s[a+1][b+1]!='#')flag = 1;
    s[a+1][b+1]='.';
    if(s[a+2][b]!='#')flag = 1;
    s[a+2][b]='.';
}
int main()
{
    int i,j;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>s[i];
        memset(vis,0,sizeof(vis));
        flag=0;
        for(i=0;i<n&&flag==0;i++)
        {
            for(j=1;j<n&&flag==0;j++)
            {
                if(s[i][j]=='#'&&s[i][j-1]=='#')
                {
                    flag=1;break;
                }
            }

            //cout<<i<<"*"<<flag<<endl;
            for(j=1;j<n;j++)
            {
                if(s[i][j]=='#')
                {
                    s[i][j]='.';
                    f(i,j);
                }
            }
//            for(int k=0;k<n;k++)
//            {
//                cout<<s[k]<<endl;
//            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j]=='#')flag=1;
            }
        }
        if(flag)puts("NO");
        else puts("YES");
    }
}
