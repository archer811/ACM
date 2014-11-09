#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 362881;
struct array
{
    int pre;
    int dir;
    int s[9];
} q[maxn],next;
char s[10];
bool hash[maxn];
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int cantor(int *s)
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
          if(s[j]<s[i])
            num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum;
}
int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//u,d,l,r
int ans[maxn];
void out(int j)
{
    for(int i=j-1;i>=0;i--)
    {
         if(ans[i]==0) printf("u");
        else if(ans[i]==1) printf("d");
        else if(ans[i]==2) printf("l");
        else if(ans[i]==3) printf("r");
    }
    puts("");
}
void bfs()
{
    memset(hash,false,sizeof(hash));
    int now = cantor(q[0].s);
    if(now==0)
    {
        out(0);
        return;
    }
    hash[now]=true;
    int k=1;
    q[0].dir=q[0].pre=-1;
    for(int i=0;i<k;i++)
    {
        int tmp;
        for(tmp=0;tmp<9;tmp++)
          if(q[i].s[tmp]==9)
            break;
        int x = tmp/3;
        int y = tmp%3;
        for(int j=0;j<4;j++)
        {
            int tx = x+move[j][0];
            int ty = y+move[j][1];
            if(tx<0||ty<0||tx>2||ty>2)continue;
            next = q[i];
            next.dir=j;
            next.pre=i;
            next.s[tmp]=next.s[tx*3+ty];
            next.s[tx*3+ty]=9;
            now = cantor(next.s);
            if(now==0)
            {
                int len=0;
                int t=i+1;
                q[t]=next;
                while(q[t].pre!=-1)
                {
                    ans[len++]=q[t].dir;
                    t=q[t].pre;
                }
                out(len);
                return;
            }
            if(!hash[now])
            {
                hash[now]=true;
                q[k++]=next;
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='x')q[0].s[0]=9;
        else q[0].s[0]=s[0]-'0';
        for(i=1; i<9; i++)
        {
            scanf("%s",s);
            if(s[0]=='x')q[0].s[i]=9;
            else q[0].s[i]=s[0]-'0';
        }
        bfs();
    }
}
