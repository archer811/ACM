#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
const int N = 105;
int ans[N][N];
int dir[][2]= { {-1,0},{0,1},{1,0},{0,-1}  };
int a[][4]= {  {1,2,3,0},{2,1,0,3}  };
int color[106];
int vis[5];
int mp[N][N];
int n;
void dfs(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int x2 = x+dir[i][0];
        int y2 = y+dir[i][1];
        if(x2>=1&&x2<=n && y2>=1 &&y2<=n &&ans[x2][y2]!=ans[x][y])
        {
            if(color[ans[x2][y2]]!=-1)
                vis[color[ans[x2][y2]]]=1;
        }
        else if(x2>=1&&x2<=n && y2>=1 &&y2<=n &&ans[x2][y2]==ans[x][y])
        {
            if(mp[x2][y2]==0)
            {
                mp[x2][y2]=1;
                dfs(x2,y2);
            }
        }
    }
}
int f(int x,int y)
{
    int i,j;
    for(i=0; i<=3; i++)
        vis[i]=0;
    dfs(x,y);
    for(i=0; i<=3; i++)
        if(vis[i]==0)return i;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            puts("Y");
        }
        else if(n>=2&&n<=4)
        {
            puts("No solution!");
        }
        else  if(n==6)
        {
            printf("YYYYYY\n");
            printf("RRBBBB\n");
            printf("YRRRRB\n");
            printf("YYBBGB\n");
            printf("YYBBGG\n");
            printf("YBBGGG\n");
        }
        else
        {
            memset(ans,-1,sizeof(ans));
            int id=0;
            int sum=0;
            int x  = 1,y = 1;
            for(i=1; i<=n; i++)
            {
                int d ;
                if(i&1)d=0;
                else d=1;
                if(ans[x][y]==-1)
                {
                    //if(x==2&&y==5)cout<<"ok"<<endl;
                    if(sum+1>n)
                    {
                        sum=1;
                        id++;
                    }
                    else sum++;
                    ans[x][y]=id;
                }

                for(j=0; j<4; j++)
                {
                    int g = a[d][j];
                    int x2 = x+dir[g][0];
                    int y2 = y+dir[g][1];
                    while( x2 <= n && y2 <= n && x2 >= 1 && y2 >= 1 && ans[x2][y2] == -1)
                    {
                        if(sum+1>n)
                        {
                            sum=1;
                            id++;
                        }
                        else sum++;
                        ans[x2][y2]=id;
//                        if(x2==2&&y2==5)
//                            cout<<"oo"<<sum<<"  "<<id<<"  "<<i<<endl;
                        x2 += dir[g][0];
                        y2 += dir[g][1];
                    }
                    x2 -= dir[g][0];
                    y2 -= dir[g][1];
                    x = x2;
                    y = y2;
                }
                if(d==0)
                {
                    y++;
                }
                else
                {
                    x++;
                }
            }

//            for(i=1; i<=n; i++)
//            {
//                for(j=1; j<=n; j++)
//                    cout<<ans[i][j];
//                cout<<endl;
//            }

            memset(color,-1,sizeof(color));
            memset(mp,0,sizeof(mp));

            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(color[ans[i][j]]!=-1)continue;
                    mp[i][j]=1;
                    color[ans[i][j]] = f(i,j);
                }
            }

            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(color[ans[i][j]]==0)printf("%c",'Y');
                    else if(color[ans[i][j]]==1)printf("%c",'G');
                    else if(color[ans[i][j]]==2)printf("%c",'R');
                    else if(color[ans[i][j]]==3)printf("%c",'B');


//                    if(ans[i][j]%4==0)printf("%c",'Y');
//                    else if(ans[i][j]%4==1)printf("%c",'G');
//                    else if(ans[i][j]%4==2)printf("%c",'R');
//                    else if(ans[i][j]%4==3)printf("%c",'B');
                }


                puts("");
            }
        }
    }
    return 0;
}
