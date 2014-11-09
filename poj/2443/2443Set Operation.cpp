#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int n;
short visi[1002][10002];
struct mm
{
    int aa;
    int bb;
    int fla;
};
mm node[200002];
vector<int> mq[10002];
vector<int>::iterator it;

int main()
{
    int i,j,t,x,q,flag;
    int a,b;
    int tt;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            for(j=1;j<=10000;j++)
                visi[i][j]=0;
        for(i=1;i<=10000;i++)
           mq[i].clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            for(j=0;j<t;j++)
            {
                scanf("%d",&x);
                visi[i][x]=1;
                mq[x].push_back(i);
            }
        }

        scanf("%d",&q);
        int len=0;
        for(i=0;i<q;i++)
        {
            flag=0;
            scanf("%d%d",&a,&b);
            tt=0;
//            for(j=0;j<len;j++)  //如果已经访问过，就不往下找了，直接输出
//            {
//                if((a==node[j].aa&&b==node[j].bb)||(b==node[j].aa&&a==node[j].bb))
//                {
//                    tt=1;
//                    flag=node[j].fla;
//                    break;
//                }
//            }
//            if(tt)
//            {
//                if(flag) printf("Yes\n");
//                else printf("No\n");
//            }
//            else   //没访问过,暴力枚举a存在的所有的行，看b是否存在
            {
                 for(it=mq[a].begin();it!=mq[a].end();it++)
                 {
                     int tmp=*it;
                     if(visi[tmp][b])
                     {
                         flag=1;
                         break;
                     }
                 }
                 if(!flag)
                 {
                     node[len].aa=a,node[len].bb=b,node[len].fla=0;
                     printf("No\n");
                 }
                 else
                 {
                     node[len].aa=a,node[len].bb=b,node[len].fla=1;
                     printf("Yes\n");
                 }
            }
        }
    }
    return 0;
}


