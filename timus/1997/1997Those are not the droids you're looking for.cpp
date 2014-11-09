#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define N 1002
int useif[N];   //记录y中节点是否使用
int link[N];   //记录当前与y节点相连的x的节点
int mat[N][N]; //记录连接x和y的边，如果i和j之间有边则为1，否则为0
int gn,gm;    //二分图中x和y中点的数目
int can(int t)
{
    int i;
    for(i=0;i<gm;i++)
    {
       if(useif[i]==0 && mat[t][i])
       {
           useif[i]=1;
           if(link[i]==-1 || can(link[i]))
           {
              link[i]=t;
              return 1;
           }
       }
    }
    return 0;
}
int MaxMatch()
{
    int i,num;
    num=0;
    memset(link,0xff,sizeof(link));
    for(i=0;i<gn;i++)
    {
       memset(useif,0,sizeof(useif));
       if(can(i)) num++;
    }
    return num;
}
vector<int>in;
vector<int>out;
int main()
{
    int i,j;
    int a,b,n;
    int k;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        scanf("%d",&n);
        in.clear();out.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&k,&j);
            if(j==0)
                in.push_back(k);
            else out.push_back(k);
        }
        if(in.size()!=out.size())
        {
            cout<<"Liar"<<endl;
            continue;
        }
        gn = in.size();
        gm = out.size();
        memset(mat,0,sizeof(mat));
        for(i=0;i<in.size();i++)
        {
            for(j=0;j<out.size();j++)
            {
                int t1 = in[i];
                int t2 = out[j];
                //cout<<t1<<"*"<<t2<<endl;
                if(t1<=t2&&t2-t1>=a)
                    mat[i][j]=1;
                if(t1<=t2&&t2-t1<=b)
                    mat[i][j]=1;
            }
        }
        int tmp = MaxMatch();
        if(tmp!=in.size())
        {
            cout<<"Liar"<<endl;
        }
        else
        {
            cout<<"No reason"<<endl;
            for(i=0;i<out.size();i++)
            {
                cout<<in[link[i]]<<" "<<out[i]<<endl;
            }
        }
    }
}
