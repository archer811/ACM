#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int fa[5002*5002];
int mark[5002*5002];
bool mark2[5002*5002];
int N,M,ans;
char s[2];
int f(int a,int b)
{
    return a*N+b;
}
int gety(int m)
{
    return m%N;
}
int getx(int m)
{
    int y = m%N;
    return (m-y)/N;
}
int go[][2]= {-1,0,1,0,0,1,0,-1};
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void add(int u,int v)
{
    int t1 = find(u),t2 = find(v);
    if(t1==t2)return;
    int x = getx(v);


    if(mark[t1]==1)
    {
        if(x==N-1||mark2[t1])
        {
            mark2[t1]=mark2[t2]=true;
        }

        if(x==0||mark[t2]==2)
            mark[t1]=mark[t2]=2;
        else mark[t2]=1;
    }
    else if(mark[t1]==2)
    {
        if(x==N-1||mark2[t1])mark2[t1]=mark2[t2]=true;
        mark[t1]=mark[t2]=2;
    }
    //if(u==6&&v==5)cout<<t1<<" "<<mark[t1]<<" () "<<mark[t2]<<
    //    " "<<mark2[t1]<<" "<<mark2[t2]<<endl;
    int now;
    if(t1<t2)
    {
        fa[t2]=t1;
        now = t1;
    }
    else
    {
        fa[t1]=t2;
        now = t2;
    }

    if(mark2[now]&&mark[now]==2)ans=1;
   // if(v==15)cout<<now<<" "<<
}
int main()
{
    int i,j;
   // cout<<f(3,3);
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        int a,b;
        for(i=0; i<N*N; i++)
            fa[i]=i,mark[i]=0,mark2[i]=false;
        ans=0;
        while(M--)
        {
            scanf("%s",s);

            if(s[0]=='O')
            {
                scanf("%d%d",&a,&b);
                a--;
                b--;
                int gg=f(a,b);
                if(a==0)mark[gg]=2;
                else mark[gg]=1;
                if(a==N-1)mark2[gg]=true;


                for(i=0; i<4; i++)
                {
                    int _a = a+go[i][0];
                    int _b = b+go[i][1];
                    if(_a>=0&&_b>=0&&_a<N&&_b<N)
                    {
                        int tmp = f(_a,_b);
                        int tt = find(tmp);
                        if(mark[tt])
                        {
                            //if(a==2&&b==2)
                            // cout<<"@"<<a<<" "<<b<<" "<<f(a,b)<<" "<<tmp<<endl;
                            add(tmp,f(a,b));
                            //break;
                        }
                    }
                }
                if(a==N-1)
                {
                    int tmp = f(a,b);
                    int tt = find(tmp);
                    mark2[tt]=1;
                    if(mark[tt]==2)ans=1;
                    //cout<<"#"<<tt<<" "<<mark[tt]<<" "<<ans<<endl;
                }
            }
            else if(s[0]=='F')
            {
                scanf("%d%d",&a,&b);
                a--;
                b--;
                int tmp = f(a,b);
                int tt = find(tmp);
                //cout<<N<<" "<<tmp<<" "<<tt<<"*****"<<endl;
                if(mark[tt]==2)puts("1");
                else puts("0");
            }
            else
            {
                if(ans)puts("1");
                else puts("0");
            }
        }
    }

}
