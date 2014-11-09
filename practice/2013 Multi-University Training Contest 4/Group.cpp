#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int n,m;
const int maxn = 100005;
int a[maxn],b[maxn];
struct query
{
    int x,y,index;
} s[maxn];
int M;
int ans[maxn];
int cmp(query a,query b)
{
    if(a.x/M!=b.x/M)return a.x/M<b.x/M;
    return a.y<b.y;
}
int sum;
void add(int x)
{
    x = a[x];
    if(x==1)
    {
        if(b[x+1]);
        else
            sum++;
    }
    else if(x==n)
    {
        if(b[x-1]);
        else
            sum++;
    }
    else
    {
        if(b[x-1]&&b[x+1])
        {
            sum--;
        }
        else if(b[x-1]==0&&b[x+1]);
        else if(b[x-1]&&b[x+1]==0);
        else sum++;
    }
    b[x]=1;
}
void _delete(int x)
{
    x=a[x];
    //cout<<x<<endl;
    if(x==1)
    {
        if(b[x+1]);
        else
            sum--;
    }
    else if(x==n)
    {
        if(b[x-1]);
        else
            sum--;
    }
    else
    {
        if(b[x-1]&&b[x+1])
        {
            //cout<<"G"<<x<<endl;
            sum++;
        }
        else if(b[x-1]==0&&b[x+1]);
        else if(b[x-1]&&b[x+1]==0);
        else sum--;
    }

    b[x]=0;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        M = sqrt(n*1.0);
        memset(b,0,sizeof(b));
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            s[i].index=i;
        }
        sort(s,s+m,cmp);
        for(i=s[0].x; i<=s[0].y; i++)
        {
            b[a[i]]=1;
        }
        sum=0;
        int f=0;
        for(i=1; i<=n; i++)
        {
            if(f==0&&b[i])
            {
                sum++;
                f=1;
            }
            else if(f==1&&b[i])continue;
            else if(f==0&&b[i]==0)continue;
            else if(f==1&&b[i]==0)f=0;
        }
        //cout<<sum<<"(("<<s[0].index<<" "<<s[0].x<<" "<<s[0].y<<endl;
        ans[s[0].index]=sum;
        int prex=s[0].x,prey=s[0].y;
        for(i=1; i<m; i++)
        {
            //cout<<s[i].x<<" "<<s[i].y<<endl;
            while(s[i].y>prey)
            {
                //cout<<"add"<<prey+1<<endl;
                add(prey+1);
                prey++;
            }
            while(s[i].y<prey)
            {

                _delete(prey);
                //cout<<"delete"<<prey<<" "<<sum<<endl;
                prey--;
            }
            while(s[i].x>prex)
            {

                _delete(prex);
                //cout<<"delete"<<prex<<" "<<sum<<endl;
                prex++;
            }
            while(s[i].x<prex)
            {

                add(prex-1);
                //cout<<"add"<<prex-1<<" "<<sum<<endl;
                prex--;
            }
            ans[s[i].index]=sum;
        }
        for(i=0; i<m; i++)
            printf("%d\n",ans[i]);
    }
}
