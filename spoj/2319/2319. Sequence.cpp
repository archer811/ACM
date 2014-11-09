#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct num
{
    int s,a[10];
} f[110],pow[110],l,r,tot,mid,now;
struct two
{
    int s,a[110];
};
int n,m,i;

inline num give(int x)
{
    num a;
    memset(&a,0,sizeof(a));
    if(!x)
    {
        a.s=1;
        return a;
    }
    while(x) a.a[++a.s]=x%10000,x/=10000;
    return a;
}

inline bool operator <(num a,num b)
{
    if(a.s<b.s) return 1;
    if(a.s>b.s) return 0;
    for(int i=a.s; i; i--)
    {
        if(a.a[i]<b.a[i]) return 1;
        if(a.a[i]>b.a[i]) return 0;
    }
    return 0;
}

inline num operator +(num a,num b)
{
    num c;
    memset(&c,0,sizeof(c));
    c.s=max(a.s,b.s);
    int i,jin=0;
    for(i=1; i<=c.s; i++)
    {
        jin+=a.a[i]+b.a[i];
        c.a[i]=jin%10000;
        jin/=10000;
    }
    if(jin) c.a[++c.s]=jin;
    return c;
}

inline num operator -(num a,num b)
{
    num c;
    memset(&c,0,sizeof(c));
    c.s=a.s;
    for(int i=1; i<=c.s; i++)
        if(a.a[i]<b.a[i])
        {
            a.a[i+1]--,a.a[i]+=10000;
            c.a[i]=a.a[i]-b.a[i];
        }
        else c.a[i]=a.a[i]-b.a[i];
    while(c.s>1&&!c.a[c.s]) c.s--;
    return c;
}

inline num operator *(num a,int b)
{
    num c;
    memset(&c,0,sizeof(c));
    c.s=a.s;
    int i,jin=0;
    for(i=1; i<=c.s; i++)
    {
        jin+=a.a[i]*b;
        c.a[i]=jin%10000;
        jin/=10000;
    }
    while(jin) c.a[++c.s]=jin%10000,jin/=10000;
    return c;
}

inline num operator /(num a,int b)
{
    num c;
    memset(&c,0,sizeof(c));
    c.s=a.s;
    int i,temp=0;
    for(i=c.s; i; i--)
    {
        temp=temp*10000+a.a[i];
        c.a[i]=temp/b;
        temp%=b;
    }
    while(c.s>1&&!c.a[c.s]) c.s--;
    return c;
}

inline two turn(num a)
{
    two c;
    c.s=0;
    while(a.s>1||a.a[1])
    {
        c.a[++c.s]=(a.a[1]&1)?1:0;
        a=a/2;
    }
    return c;
}

void prework()
{
    pow[0]=give(1);
    for(i=1; i<=100; i++) pow[i]=pow[i-1]*2;
    f[0]=give(0);
    for(i=1; i<=100; i++) f[i]=f[i-1]*2+pow[i-1];
}

num calc(num x)
{
    int i,j=0;
    num t=give(0);
    two y=turn(x);
    for(i=y.s; i; i--)
        if(y.a[i])
        {
            t=t+f[i-1]+pow[i-1]*j;
            j++;
        }
    t=t+give(j);
    return t;
}

num get(num t)
{
    int i,j=0;
    num x=give(0);
    for(i=n; i>=0; i--)
        if(f[i]+pow[i]*j<t)
        {
            t=t-(f[i]+pow[i]*j);
            j++;
            x=x*2+give(1);
        }
        else x=x*2;
    if(t<give(j)) x=x-give(1);
    return x;
}

int main()
{
    cin>>n>>m;
    prework();
    l=give(1),r=f[n],tot=pow[n]-l;
    while(l<r)
    {
        mid=(l+r)/2;
        now=give(0);
        for(i=1; i<=m; i++)
        {
            now=get(now+mid);
            if(!(now<tot)) break;
            now=calc(now);
        }
        if(i>m) l=mid+give(1);
        else r=mid;
    }
    cout<<l.a[l.s];
    for(i=l.s-1; i; i--) printf("%04d",l.a[i]);
    cout<<endl;
    system("pause");
    return 0;
}
