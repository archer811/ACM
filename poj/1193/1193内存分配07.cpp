#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int inf  = 1<<28;
struct array
{
    int m,start_time,end_time,s;
    friend bool operator < (array x,array y)
    {
        return x.s<y.s;
    }
} tmp;
struct array2
{
    int m,p;
} ans[10005];
multiset<array>myset;
multiset<array>::iterator it;
multiset<array>::iterator it2;
queue<int>q;
int n,nextime;
int M,gg;
int havespace(int m)
{
//     if(m==12)cout<<")_++++++++++++"<<endl;
    if(!myset.empty())
    {
        it = myset.begin();
//        if(m==12)cout<<"!!!!!!!!!!!!!!!"<<it->s<<endl;
        if(it->s-0>=m)
        {
            M=0;
            return 1;
        }
        it2 = it;
        it++;
        while(it!=myset.end())
        {

            if(it2->s+it2->m-1+m<it->s)
            {
                M = it2->s+it2->m;
                return 1;
            }
            it2 = it;
            it++;
        }

        if(n-(it2->s+it2->m)>=m)
        {
            M = it2->s+it2->m;
            return 1;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
void pour()
{
    it = myset.begin();
    int Max = inf;
    while(it!=myset.end())
    {
//        cout<<it->end_time<<endl;
        it2 = it;it++;
        if(it2->end_time==nextime)
            myset.erase(it2);
        else
        {
            if(it2->end_time<Max)
                Max = it2->end_time;
        }
    }
//    cout<<Max<<"!!"<<endl;
    while(!q.empty())
    {
        int u = q.front();
        if(havespace(ans[u].m))
        {
            q.pop();
//            cout<<u<<"()()()()"<<nextime<<" "<<nextime+ans[u].p<<endl;
            tmp.s=M;
            tmp.start_time=nextime;
            tmp.end_time = nextime+ans[u].p;
            tmp.m=ans[u].m;
            myset.insert(tmp);
            Max = min(Max,tmp.end_time);
        }
        else break;
    }
    nextime = Max;
//    cout<<Max<<"----------------"<<endl;
}
void insert(int index,int t,int p,int m)
{
    while(nextime<t)pour();
    if(!havespace(m))
    {
//        cout<<index<<"&&&&&&&&&&&&&&&&&&&"<<endl;
        q.push(index);
        gg++;
    }
    else
    {
        //cout<<"GG"<<endl;
        tmp.m=m;
        tmp.start_time=t;
        tmp.end_time = t+p-1;
        tmp.s = M;
        myset.insert(tmp);

        nextime = min(nextime,t+p-1);
//        cout<<index<< " ++ "<<nextime<<endl;
    }
}
int solve()
{
    while(!q.empty())
    {
        pour();
    }
    it = myset.begin();
    int ans = nextime;
    while(it!=myset.end())
    {
        if(it->end_time>ans)
            ans = it->end_time;
        it++;
    }
    return ans;
}
int main()
{
    int i,j,k,t,m,p;
    scanf("%d",&n);
    k = 1;
    myset.clear();
    gg=0;
    nextime = inf;
    while(scanf("%d%d%d",&t,&m,&p)!=EOF)
    {
        if(t+m+p==0)break;
        ans[k].m=m;
        ans[k].p=p;
        insert(k++,t,p,m);
    }
    printf("%d\n%d\n",solve()+1,gg);
}
