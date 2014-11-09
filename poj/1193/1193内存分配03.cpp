#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int inf  = 0x3fffffff;
int MM;
struct array
{
    int m,start_time,end_time,s;
    friend bool operator < (array x,array y)
    {
        return x.end_time<y.end_time;
    }
} tmp;
struct array2
{
    int m,p;
} ans[10005];
multiset<array>myset;
multiset<array>::iterator it;
int mark[10220];
queue<int>q;
int n;
int pre[10220];
void insert(int index,int t,int m,int p,int mm)
{
    while(!q.empty())
    {
        int tt=inf;
        if(!myset.empty())
        {
            it = myset.begin();

            int nextime  = it->end_time;
            if(nextime>=t)break;
//            cout<<it->start_time<<" "<<it->end_time<<"*"<<endl;
            for(int i=(it->s); i<(it->s)+(it->m); i++)
                mark[i]=-1,pre[i]=nextime;
            myset.erase(it);

            int u = q.front();

            int num=0;
            int M=-1;
            int gg = ans[u].m;
            bool flag = false;
            int tt = -inf;
            for(int i=0; i<n; i++)
            {
                if(mark[i]==-1)
                {
                    num=0;
                    M=i;
                    tt=-inf;
                    while(i<n&&mark[i]==-1&&num<gg)
                    {
                        num++;
                        if(pre[i]>tt)tt=pre[i];
                        i++;
                    }
                    if(num>=gg)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)
            {
                q.pop();
//                if(tt!=nextime)
//                    cout<<nextime<< " ++++ "<<tt<<endl;
                tmp.m = ans[u].m;
                tmp.start_time = nextime+1;
                tmp.end_time = nextime+ans[u].p;
                tmp.s = M;
                for(int i=M; i<M+ans[u].m; i++)
                    mark[i]=u,pre[i]=tmp.end_time;
//                    cout<<tmp.end_time<<"  ******** "<<endl;
//                for(int i=0;i<n;i++)
//                    cout<<mark[i]<< " ";
//                cout<<endl;
                myset.insert(tmp);

            }
        }
        else break;
    }
    if(mm)
    {
        int tt=-inf;
        for(int i=0; i<n; i++)
        {
            if(pre[i]>tt)tt=pre[i];
        }
        if(mm)printf("%d\n%d\n",tt+1,MM);
    }
    int num=0;
    int M=0;
    int gg = m;
    bool flag = false;
    for(int i=0; i<=n-m; i++)
    {
        if(mark[i]==-1)
        {
            num=0;
            M=i;
            while(i<n&&mark[i]==-1&&num<=gg)
            {
                num++;
                i++;
            }
            if(num>=gg)
            {
                flag=true;
                break;
            }
        }
    }
    if(flag)
    {
        tmp.m = m;
        tmp.start_time = t;
        tmp.end_time = t+p-1;
        tmp.s = M;
        for(int i=M; i<M+m; i++)
            mark[i]=index,pre[i]=tmp.end_time;
        myset.insert(tmp);
    }
    else q.push(index),MM++;
//    for(int i=0;i<n;i++)
//        cout<<mark[i]<< " ";
//    cout<<endl;
    ans[index].m=m;
    ans[index].p=p;
}
int main()
{
    int i,j,k,t,m,p;
    scanf("%d",&n);
    k = 1;
    myset.clear();
    memset(mark,-1,sizeof(mark));
    MM  = 0;
    for(i=0; i<n; i++)
        pre[i]=-inf;
    while(scanf("%d%d%d",&t,&m,&p)!=EOF)
    {
        if(t+m+p==0)break;
        insert(k++,t,m,p,0);
    }
    insert(k++,inf,0,0,1);
}
