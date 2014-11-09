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
const int maxn = 1000006;
char s[maxn];
int a[maxn<<2],b[maxn<<2],c[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void pushup(int l,int r,int rt)
{
    int mid = (l+r)>>1;
    int t = min(b[lson],c[rson]);
    a[rt]=a[lson]+a[rson]+t;
    b[rt]=b[lson]+b[rson]-t;
    c[rt]=c[lson]+c[rson]-t;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        a[rt]=0;
        if(s[l]=='(')b[rt]=1,c[rt]=0;
        else
        {
            b[rt]=0;c[rt]=1;
        }
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(l,r,rt);
}
void query(int x,int y,int l,int r,int rt,int &ansa,int &ansb,int &ansc)
{
    //cout<<l<<"*"<<r<<endl;
    if(x<=l&&y>=r)
    {
        ansa=a[rt];
        ansb=b[rt];
        ansc=c[rt];
        //cout<<a[rt]<<" "<<b[rt]<<" "<<c[rt]<<endl;
        return ;
    }
    int mid = (l+r)>>1;
    int sum=0;
    int a1=0,b1=0,c1=0,a2=0,b2=0,c2=0;
    if(x<=mid)
        query(x,y,l,mid,lson,a1,b1,c1);
    if(y>mid)
        query(x,y,mid+1,r,rson,a2,b2,c2);
    int t = min(b1,c2);
    ansa = a1+a2+t;
    ansb = b1+b2-t;
    ansc = c1+c2-t;
    //cout<<l<<" "<<r<<" "<<a1<<" "<<b1<<" "<<c1<<" "<<a2<<" "<<b2<<" "<<c2<<" "<<t<<endl;
    //cout<<l<<" "<<r<<" "<<ansa<<" ( "<<ansb<<" ) "<<ansc<<endl;
    return;
}
void output(int l,int r,int rt)
{
    cout<<l<<" "<<r<<" "<<rt<<" "<<a[rt]<<" "<<b[rt]<<" "<<c[rt]<<endl;
    if(l==r)return;
    int mid=(l+r)>>1;
    output(l,mid,lson);
    output(mid+1,r,rson);
}
int main()
{
    int i,j;
    int m,a,b;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
       // memset(num,0,sizeof(num));
        int sum=0;
        build(0,len-1,1);
        //output(0,len-1,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            a--;b--;
            int a1,b1,c2;
            query(a,b,0,len-1,1,a1,b1,c2);
            //cout<<tmp1<<"*"<<tmp2<<endl;
            printf("%d\n",2*a1);
        }
    }
}
