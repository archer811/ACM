#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int v[10];
struct array
{
    int x;
    bool friend operator < (array a,array b)
    {
        return v[a.x]>v[b.x];
    }
}now;
priority_queue<array>q;
int main()
{
    int i,j;
    v[0]=0;v[1]=1;v[2]=3;
    now.x=0;q.push(now);
    now.x=1;q.push(now);
    now.x=2;q.push(now);
    v[2]=0;
    while(!q.empty())
    {
        now = q.top();q.pop();
        cout<<now.x<<" "<<v[now.x]<<endl;
    }
}
