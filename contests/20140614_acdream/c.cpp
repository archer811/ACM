#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1105][1105],s2[1105][1105];
int a[1105][1105][4];
int go[][2]= {-1,0,1,0,0,1,0,-1};
struct array
{
    int x,y,f,M;
} now,next;
queue<array>q;
int main()
{
    int i,j,n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='T')
                {
                    x=i;
                    y=j;
                }
                s2[i][j]=s[i][j];
            }
        }
        int ant=0;
        for(int g=0; g<4; g++)
        {
            memset(a,0,sizeof(a));
            while(!q.empty())q.pop();
            a[x][y][g]=1;
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                    s[i][j]=s2[i][j];
            }
            now.x=x;
            now.y=y;
            now.f=g;
            now.M=0;
            q.push(now);
            while(!q.empty())
            {
                now = q.front();
                q.pop();
                if(now.M>ant)ant=now.M;
                int x2=now.x+go[now.f][0];
                int y2=now.y+go[now.f][1];
                if(x2>=0&&y2>=0&&x2<n&&y2<m&&s2[x2][y2]!='*')
                {
                    if(s[x2][y2]=='.'||s[x2][y2]=='T')
                    {
                        if(a[x2][y2][now.f]==0)
                        {
                            a[x2][y2][now.f]=1;
                            next.x=x2;
                            next.y=y2;
                            next.f=now.f;
                            next.M=now.M;
                            q.push(next);
                        }
                    }
                    else if(s[x2][y2]=='E')
                    {
                        if(a[x2][y2][now.f]==0)
                        {
                            s[x2][y2]='.';
                            a[x2][y2][now.f]=1;
                            next.x=x2;
                            next.y=y2;
                            next.f=now.f;

                            next.M=now.M+1;
                            q.push(next);
                        }
                    }
                    else if(s[x2][y2]=='/')
                    {
                        //int www=1;
                        int nextf=0;
                        if(now.f==0)nextf=2;
                        else if(now.f==3)nextf=1;
                        else if(now.f==2)nextf=0;
                        else if(now.f==1)nextf=3;
                        if(a[x2][y2][nextf]==0)
                        {
                            a[x2][y2][nextf]=1;
                            next.x=x2;
                            next.y=y2;
                            next.f=nextf;
                            next.M=now.M;
                            q.push(next);
                        }
                    }
                    else if(s[x2][y2]=='\\')
                    {
                        int nextf=0,gggg=-1;
                        if(now.f==0)nextf=3;
                        else if(now.f==2)nextf=1;
                        else if(now.f==3)nextf=0;
                        else if(now.f==1)nextf=2;
                        if(a[x2][y2][nextf]==0)
                        {
                            a[x2][y2][nextf]=1;
                            next.x=x2;
                            next.y=y2;
                            next.f=nextf;
                            next.M=now.M;
                            q.push(next);
                        }
                    }
                }
            }
        }
        cout<<ant<<endl;
    }

    return 0;
}
