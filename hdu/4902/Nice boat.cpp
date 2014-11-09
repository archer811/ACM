#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 400;
int s[110000];
int lazy[maxn];
int flag=0,flag2;
void u1(int a,int b,int x)
{
    if(a>b)return;
    for(int i=a; i<=b; i++)
    {
        s[i]=x;
    }
}
void f1(int a,int b,int x)
{
    int u=a/400;
    int v=b/400;
    int a2=a%400;
    int b2=b%400;
    if(u==v)
    {
        if(lazy[u]!=x)
        {
            if(a2==0&&b2==399)
                lazy[u]=x;
            else
            {
                if(lazy[u]!=-1)
                    u1(u*400,a-1,lazy[u]),u1(b+1,u*400+399,lazy[u]);
                u1(a,b,x);
                lazy[u]=-1;
            }
        }
    }
    else
    {
        if(lazy[u]!=x)
        {

            if(a2==0)lazy[u]=x;
            else
            {
                if(lazy[u]!=-1)
                    u1(u*400,a-1,lazy[u]);
                u1(a,u*400+399,x);
                lazy[u]=-1;
            }

        }

        if(lazy[v]!=x)
        {

            if(b2==399)lazy[v]=x;
            else
            {
                if(lazy[v]!=-1)
                    u1(b+1,v*400+399,lazy[v]);
                u1(v*400,b,x);
                lazy[v]=-1;
            }

        }


        for(int i=u+1; i<v; i++)
        {
            if(lazy[i]!=x)
            {
                lazy[i]=x;
            }
        }
    }
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
    //return __gcd(a,b);
}

void u2(int a,int b,int x)
{
    if(a>b)return;
    for(int i=a; i<=b; i++)
    {
        if(s[i]>x)s[i]=gcd(s[i],x);
        if(s[i]!=s[a])flag=1;
    }
    flag2=s[a];
}
void f2(int a,int b,int x)
{
    int u=a/400;
    int v=b/400;
    int a2=a%400;
    int b2=b%400;
    if(u==v)
    {
        if(lazy[u]!=-1)
        {
            if(lazy[u]>x)
            {
                u1(u*400,a-1,lazy[u]);
                u1(b+1,u*400+399,lazy[u]);
                int tmp=gcd(x,lazy[u]);
                u1(a,b,tmp);
                lazy[u]=-1;
            }
        }
        else
        {
            u2(a,b,x);
            lazy[u]=-1;
        }
    }
    else
    {
        if(lazy[u]!=-1)
        {
            if(lazy[u]>x)
            {
                u1(u*400,a-1,lazy[u]);
                int tmp = gcd(x,lazy[u]);
                u1(a,u*400+399,tmp);
                lazy[u]=-1;
            }
        }
        else
        {
            u2(a,u*400+399,x);
            lazy[u]=-1;
        }

        if(lazy[v]!=-1)
        {
            if(lazy[v]>x)
            {
                u1(b+1,v*400+399,lazy[v]);
                int mp =gcd(lazy[v],x);
                u1(v*400,b,mp);
                lazy[v]=-1;
            }
        }
        else
        {
            u2(v*400,b,x);
            lazy[v]=-1;
        }

        for(int i=u+1; i<v; i++)
        {
            if(lazy[i]!=-1)
            {
                if(lazy[i]>x)
                    lazy[i]=gcd(lazy[i],x);
            }
            else
            {
                flag=0;
                u2(i*400,i*400+399,x);
                lazy[i]=-1;
            }
        }
    }
}
int main()
{
    int i,j,t;

//    freopen("1006.in","r",stdin);
//    freopen("out3.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&s[i]);
        int m;
        for(i=0; i<maxn; i++)
            lazy[i]=-1;
        scanf("%d",&m);
        while(m--)
        {
            int a,b,type;
            int x;
            scanf("%d%d%d%d",&type,&a,&b,&x);
            if(a>b)swap(a,b);
            a--;
            b--;
            if(type==1)
                f1(a,b,x);
            else
                f2(a,b,x);
        }
        for(i=0; i<n; i++)
        {
            if(lazy[i/400]!=-1)
                s[i]=lazy[i/400];
            printf("%d ",s[i]);
//            printf("%d\n",s[i]);
//            if(i==0||s[i]!=s[i-1])
//            {
//                cout<<i+1<<" "<<s[i]<<endl;
//            }
        }
        puts("");
    }
}
