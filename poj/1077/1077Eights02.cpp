
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
const int MAXN=362881;//9!=362880
struct Node
{
    int s[9];
    int pre;//记录前一个结点
    int dir;//记录前一个结点到该结点的方向
}q[MAXN],next;
bool hash[MAXN];
int path[MAXN];

int fac[]={1,1,2,6,24,120,720,5040,40320,362880};//康拖展开判重
//         0!1!2!3! 4! 5!  6!  7!   8!    9!
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
void output(int len)
{
    for(int i=len-1;i>=0;i--)
    {
        if(path[i]==0) printf("u");
        else if(path[i]==1) printf("d");
        else if(path[i]==2) printf("l");
        else if(path[i]==3) printf("r");
    }
    printf("\n");
}
void bfs()
{
    q[0].pre=-1;
    q[0].dir=-1;
    int k=1;
    memset(hash,false,sizeof(hash));
    hash[cantor(q[0].s)]=true;
    if(cantor(q[0].s)==0){output(0);return;}
    for(int i=0;i<k;i++)
    {
        int tmp;
        for(tmp=0;tmp<9;tmp++)
          if(q[i].s[tmp]==9)
            break;
        int x=tmp/3;
        int y=tmp%3;
        for(int j=0;j<4;j++)
        {
            int tx=x+move[j][0];
            int ty=y+move[j][1];
            if(tx<0||tx>2||ty<0||ty>2)continue;
            next=q[i];
            next.pre=i;
            next.dir=j;
            next.s[tmp]=next.s[tx*3+ty];
            next.s[tx*3+ty]=9;
            int now=cantor(next.s);
            if(now==0)//到达目标
            {
                int len=0;
                int t=i+1;
                q[t]=next;
                while(q[t].pre!=-1)
                {
                    path[len++]=q[t].dir;
                    t=q[t].pre;
                }
                output(len);
                return;
            }
            if(!hash[now])
            {
                q[k++]=next;
                hash[now]=true;
            }

        }
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    char str[10];
    while(scanf("%s",&str)!=EOF)
    {
        if(str[0]=='x') q[0].s[0]=9;
        else q[0].s[0]=str[0]-'0';
        for(int i=1;i<9;i++)
        {
            scanf("%s",&str);
            if(str[0]=='x') q[0].s[i]=9;
            else q[0].s[i]=str[0]-'0';
        }
//        for(int i=0;i<9;i++)
//            cout<<que[0].s[i];
//        cout<<endl;
        bfs();
    }
    return 0;
}
