#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct array
{
    int num,a,b;
    friend bool operator < (array x,array y)
    {
        return x.num>y.num;
    }
}tmp;
const int N = 20005;
int a[N],b[N];
priority_queue<array>q;
int tt[N];
int main()
{
    int i,j,k,t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&b[j]);
            sort(b,b+m);
            while(!q.empty())q.pop();
            for(j=0;j<m;j++)
            {
                tmp.num=b[0]+a[j];
                tmp.a=j;tmp.b=0;
                q.push(tmp);
            }
            for(j=0;j<m;j++)
            {
                tmp = q.top();q.pop();
                //cout<<tmp.num<<" "<<tmp.a<<" "<<tmp.b<<endl;
                array next;
                tt[j]=tmp.num;
                next.num = a[tmp.a]+b[tmp.b+1];
                next.a = tmp.a;
                next.b = tmp.b+1;
                q.push(next);
            }
            for(j=0;j<m;j++)
                a[j]=tt[j];
        }
        for(i=0;i<m;i++)
        {
            if(i==0)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        puts("");
    }
}
