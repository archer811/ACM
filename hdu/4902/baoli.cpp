#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int s[110000];
void u1(int a,int b,int x)
{
    //if(b>a)return;
    for(int i=a; i<=b; i++)
    {
        s[i]=x;
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
    //if(b>a)return;
    for(int i=a; i<=b; i++)
    {
        if(s[i]>x)s[i]=gcd(s[i],x);
    }
}
int main()
{
    int i,j,t;

    freopen("1006.in","r",stdin);
    freopen("out3.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&s[i]);
        int m;
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
                u1(a,b,x);
            else
                u2(a,b,x);
        }
        for(i=0; i<n; i++)
        {
            if(i==0||s[i]!=s[i-1])
            {
                cout<<i+1<<" "<<s[i]<<endl;
            }
        }
        puts("");
    }
}
