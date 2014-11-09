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
int w,h,n;
int sx,sy,ex,ey;
int g[505][505][2];
char s[1005],s2[1005];
const int inf = 0x3fffffff;
int ans[505][505];
struct array
{
    int x,y;
    int step;
    array(int x=0,int y=0,int step=0):x(x),y(y),step(step){}
    bool friend operator < (array a,array b)
    {
        return a.step>b.step;
    }
} now,next;
int vv;
void bfs()
{
    //queue<array>q;
    priority_queue<array> q;
    now.x=sx;
    now.y=sy;
    now.step=0;
    q.push(now);
    while(!q.empty())
    {
        //now = q.front();
        now = q.top() ;
        int u = now.x;
        int v = now.y;
        cout<<u<<" "<<v<<endl;
        if (u==ex && v==ey) {vv=now.step;return; }
        //cout<<u<<" "<<v<<" "<<ans[u][v]<<endl;
        q.pop();
        if(u+1<=w)//R
        {
            int tmp1 = ans[u][v]+g[u][v][0];
            if(ans[u+1][v]>tmp1)
            {
                next.step=ans[u+1][v]=tmp1;
                next.x=u+1;
                next.y=v;
                //cout<<u<<"**"<<v+1<<" "<<tmp1<<endl;
                q.push(next);
            }
        }

        if(v+1<=h)//D
        {
            int tmp2 = ans[u][v]+g[u][v][1];
            if(ans[u][v+1]>tmp2)
            {
                next.step=ans[u][v+1]=tmp2;
                next.x=u;
                next.y=v+1;
                q.push(next);
            }
        }

        if(u-1>=0)//L
        {
            int tmp = ans[u][v]+g[u-1][v][0];
            //cout<<ans[u][v]<<"*"<<g[u-1][v][0]<<endl;
            if(ans[u-1][v]>tmp)
            {
                next.step=ans[u-1][v]=tmp;
                next.x=u-1;
                next.y=v;
                q.push(next);
            }
        }

        if(v-1>=0)//U
        {
            int tmp = ans[u][v]+g[u][v-1][1];
            if(ans[u][v-1]>tmp)
            {
                next.step=ans[u][v-1]=tmp;
                next.x=u;
                next.y=v-1;
                q.push(next);
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d%d",&w,&h,&n)!=EOF)
    {
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

        memset(g,0,sizeof(g));
        int x,y;
        int len2=0;
        for(i=1; i<=n; i++)
        {
            int T;
            scanf("%d%d",&x,&y);
            scanf("%d",&T);
            scanf("%s",s);
            int len = strlen(s);
            int L=0,R=0,D=0,U=0;
            //len2=0;
            int x2=x,y2=y;
            for(j=0;j<len;j++)
            {
                if(s[j]=='L')
                {
                    L++;R=0;D=0;U=0;
                }
                else if(s[j]=='D')
                {
                    L=0;R=0;D++;U=0;
                }
                else if(s[j]=='R')
                {
                    L=0;R++;D=0;U=0;
                }
                else if(s[j]=='U')
                {
                    L=0;R=0;D=0;U++;
                }
                if(L>=w||R>=w||U>=h||D>=h)continue;
                s2[len2++]=s[i];
            }
            len=len2;
            for(j=0;j<len;j++)
                s[j]=s2[j];
            int tt=1;
            for(j=1; j<=T; j++)
            {
                for(int k=0; k<len; k++)
                {
                    if(s[k]=='L')
                    {
                        g[x][y][1]+=tt;
                        if(x-1>=0)x--;
                    }
                    else if(s[k]=='R')
                    {
                        //if(x+1<w)
                        g[x+1][y][1]+=tt;
                        //cout<<j<<" "<<x<<"()"<<y+1<<" "<<g[x][y+1][1]<<endl;
                        if(x+1<w)x++;
                    }
                    else if(s[k]=='U')
                    {
                        g[x][y][0]+=tt;
                        if(y-1>=0)y--;
                    }
                    else
                    {
                        //if(y+1<h)
                        g[x][y+1][0]+=tt;
                        if(y+1<h)y++;
                    }
                }
                if(x==x2&&y==y2)
                {
                    tt = T-j;
                    j=T;
                }
            }
        }
int G = max(h,w);
        for(i=0; i<=G; i++)
        {
            for(j=0; j<=G; j++)
                ans[i][j]=inf;
        }

        ans[sx][sy]=0;
        //cout<<"***"<<endl;
        bfs();
        printf("%d\n",vv);
        //printf("%d\n",ans[ex][ey]);
    }
    return 0;
}
