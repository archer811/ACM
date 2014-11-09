#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char s[55];
string o;
int len;
int isdiferent(int a,int b)
{
    if(a!=b)return 1;
    for(int i=0,j = a;i<a;i++,j++)
    {
        if(o[i]!=o[j])return 1;
    }
    return 0;
}
int is(int xl,int yl,int x2,int y2)
{
    if(yl-xl!=y2-x2)return 1;
    for(int i=xl,j=x2;i<=yl;i++,j++)
    {
        if(o[i]!=o[j])return 1;
    }
    return 0;
}
int f(int a,int b,int c)
{
    if(isdiferent(a,b))
    {
        if(is(0,a-1,2*(a+b),2*(a+b)+c-1) &&
           is(a,a+b-1,2*(a+b),2*(a+b)+c-1))return 1;
        return 0;
    }
    else return 0;
}
int judge(int a,int b)
{
    if(a*3+b*2==len)
    {
        if(isdiferent(a,b) && is(0,a-1,a+b,2*a+b-1)==0
           && is(0,a-1,2*(a+b),len-1)==0
           && is(a,a+b-1,2*a+b,2*a+2*b-1) ==0 )return 1;
    }
    //cout<<"00"<<endl;
    int c = len-a*3-b*3;
    if(c>=1)
    {
        //cout<<a<<" "<<b<<"  "<<c<<endl;
        if(f(a,b,c) && is(0,a-1,a+b,2*a+b-1)==0
           && is(0,a-1,2*a+2*b+c,3*a+2*b+c-1)==0
           && is(a,a+b-1,2*a+b,2*a+2*b-1)==0
           && is(a,a+b-1,3*a+2*b+c,len-1)==0 )
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len = strlen(s);
        o = "";
        for(i=0;i<len;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
            {
                o += s[i];
            }
        }
        len = o.length();
        int flag=0;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len;j++)
            {
                if(judge(i,j))
                {
                    flag=1;break;
                }
            }
            if(flag)break;
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}
