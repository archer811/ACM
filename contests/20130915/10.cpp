#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-10


#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)


#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n)  while(scanf("%d",&n)!=-1)
using namespace std;


void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%lld",&x);}
void RD(u64 &x){scanf("%I64u",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%lld%lld",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%lld%lld%lld",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}


void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(i64 x) {printf("%lld\n",x);}
void PR(i64 x,i64 y) {printf("%lld %lld\n",x,y);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {printf("%llu\n",x);}
void PR(double x) {printf("%.2lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}


const int mod=10007;
const i64 inf=((i64)1)<<40;
const double dinf=1000000000000000000.0;
const int INF=100000000;
const int N=200005;


struct point3
{
    i64 x,y,z;

    point3(){}
    point3(i64 _x,i64 _y,i64 _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }

    void get()
    {
        RD(x); RD(y); RD(z);
    }

    point3 operator-(point3 a)
    {
        return point3(x-a.x,y-a.y,z-a.z);
    }

    point3 operator*(point3 a)
    {
        return point3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
    }

    i64 operator^(point3 a)
    {
        return x*a.x+y*a.y+z*a.z;
    }

    i64 len()
    {
        return x*x+y*y+z*z;
    }
};


point3 a,b,c,d,v;
i64 X,Y;


int ok()
{
    i64 A,B;
    A=(c-d)*v^(a-c);
    B=(c-d)*v^(b-c);
    if(A*B>=0) return 0;
    A=(a-b)*v^(c-a);
    B=(a-b)*v^(d-a);
    if(A*B>=0) return 0;
    return 1;
}


i64 len(point3 a)
{
    return a.len();
}


void up(pair<i64,i64> p)
{
    i64 x=p.first;
    i64 y=p.second;
    if(x*Y<y*X)
    {
        X=x;
        Y=y;
    }
}


pair<i64,i64> deal(point3 p,point3 L1,point3 L2)
{
    if(((p-L1)^(L2-L1))<=0) return MP(len(p-L1),1);
    if(((p-L2)^(L1-L2))<=0) return MP(len(p-L2),1);
    return MP(len((p-L1)*(L2-L1)),len(L2-L1));
}


i64 Gcd(i64 x,i64 y)
{
    return !y?x:Gcd(y,x%y);
}


int main()
{
    rush()
    {
        a.get(); b.get();
        c.get(); d.get();
        v=(a-b)*(c-d);
        if(ok())
        {
            X=(a-c)^v;
            X=X*X;
            Y=len(v);
        }
        else
        {
            X=inf; Y=1;
            up(deal(a,c,d));
            up(deal(b,c,d));
            up(deal(c,a,b));
            up(deal(d,a,b));
        }
        i64 temp=Gcd(X,Y);
        X/=temp; Y/=temp;
        PR(X,Y);
    }
}
