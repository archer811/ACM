#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
#define e 2.71828182845904523536
#define c 0.57721566490153286060
int w,l,tot;
double cal(int index)
{
    if(index==0)    return 0;
    double ret=0;
    if(index>=10000)
    {
        ret=(log(index)+c);
    }
    else
    {
        int i;
        for(i=1;i<=index;i++)
        {
            ret+=1.0/i;
        }
    }
    return ret;
}
int main()
{
    int cas=1,i,j;
    while(scanf("%d%d",&w,&l)!=EOF)
    {
        if(w==0&&l==0)  break;
        if(l==0&&w%8!=0)
        {
            printf("Case %d:\nSituation Impossible.\n",cas++);
            continue;
        }
        tot=w+l;
        double ans=0,res;
        int wnum=w,lnum=l;
        int ls,rs;
        lnum+=wnum%8;
        wnum-=wnum%8;
        rs=wnum/8+l;
        if(wnum+lnum<=8*l)  ls=l;
        else
        {
            int b=(8*l-lnum)/8;
            ls=wnum/8-b+l;
        }

        int len=rs-ls+1;
        res=tot*1.0/len;

        ans=cal(rs)-cal(ls-1);
        //printf("%d %d %d %.3f\n",ls,rs,tot,ans);
        printf("Case %d:\nOn Average Bob Reaches Round %.2f\n",cas++,ans*res);
    }
    return 0;
}
