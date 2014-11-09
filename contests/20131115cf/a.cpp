#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int go[][2]={-2,-2,-2,2,2,-2,2,2};
char s[10][10];
int vis1[10][10],vis2[10][10];
void dfs(int a,int b,int nn)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        int x = a+go[i][0];
        int y = b+go[i][1];
        if(x<1||y<1||x>8||y>8)continue;
        if(vis1[x][y]!=-1)continue;
        //cout<<x<<" "<<y<<endl;
        vis1[x][y]=nn;
        dfs(x,y,1-nn);
    }
}
void Dfs(int a,int b,int nn)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        int x = a+go[i][0];
        int y = b+go[i][1];
        if(x<1||y<1||x>8||y>8)continue;
        if(vis2[x][y]!=-1)continue;
        vis2[x][y]=nn;
        Dfs(x,y,1-nn);
    }
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=1;i<=8;i++)
            scanf("%s",s[i]+1);
        memset(vis1,-1,sizeof(vis1));
        memset(vis2,-1,sizeof(vis2));
        bool flag=false;
        for(i=1;i<=8&&flag==false;i++)
        {
            for(j=1;j<=8&&flag==false;j++)
            {
                if(s[i][j]=='K')
                {
                     vis1[i][j]=1;
                     dfs(i,j,0);
                     flag=true;break;
                }

            }
        }
        flag=false;int num=0;
        for(i=1;i<=8&&flag==false;i++)
        {
            for(j=1;j<=8&&flag==false;j++)
            {
                if(s[i][j]=='K')
                {
                    num++;
                    if(num==2)
                    {
                        vis2[i][j]=1;
                     Dfs(i,j,0);
                     flag=true;break;
                    }

                }
            }
        }
        flag=false;
//        for(i=1;i<=8;i++)
//        {
//            for(j=1;j<=8;j++)
//            {
//                cout<<vis1[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)
            {
                if(vis1[i][j]!=-1&&vis2[i][j]!=-1&&s[i][j]!='#')
                {
                    if(vis1[i][j]%2==vis2[i][j]%2)
                    {flag=true;break;}
                }
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
}
