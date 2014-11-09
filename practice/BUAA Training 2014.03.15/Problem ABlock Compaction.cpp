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
int n;
struct array
{
    int x,y,p,q;
}s[555];
int x[1005],y[1005];
int cmp1(array a,array b)
{
    return a.y<b.y;
}
int cmp2(array a,array b)
{
    return a.x<b.x;
}
int Maxx[1005],Maxy[1005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int xn=0,yn=0;
        memset(Maxx,0,sizeof(Maxx));
        memset(Maxy,0,sizeof(Maxy));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].p,&s[i].q);
            x[xn++]=s[i].x;
            x[xn++]=s[i].p;

        }
        sort(x,x+xn);

        xn = unique(x,x+xn)-x;

        sort(s+1,s+1+n,cmp1);
        for(i=1;i<=n;i++)
        {
            int tmp = lower_bound(x,x+xn,s[i].x)-x;
            int M=0;
            for(j=tmp;j<xn;j++)
            {
                if(x[j]==s[i].p)break;
                if(Maxx[j]>M)M=Maxx[j];
            }
            s[i].q-=(s[i].y-M);
            s[i].y=M;
            for(j=tmp;j<xn;j++)
            {
                if(x[j]==s[i].p)break;
                if(Maxx[j]<s[i].q)Maxx[j]=s[i].q;
            }
        }

        for(i=1;i<=n;i++)
        {
            y[yn++]=s[i].y;
            y[yn++]=s[i].q;
            //cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].p<<" "<<s[i].q<<endl;
        }
        sort(y,y+yn);
        yn = unique(y,y+yn)-y;

        sort(s+1,s+1+n,cmp2);
//        for(i=0;i<yn;i++)
//            cout<<y[i]<<" ";
//        cout<<endl;
        for(i=1;i<=n;i++)
        {
            int tmp = lower_bound(y,y+yn,s[i].y)-y;
           // cout<<s[i].y<<" "<<tmp<<endl;
            int M=0;
            for(j=tmp;j<yn;j++)
            {
                if(y[j]==s[i].q)break;
                if(Maxy[j]>M)M=Maxy[j];
            }
            s[i].p-=(s[i].x-M);
            s[i].x=M;
            for(j=tmp;j<xn;j++)
            {
                if(y[j]==s[i].q)break;
                if(Maxy[j]<s[i].p)Maxy[j]=s[i].p;
            }
        }
        int Mx=0,My=0;
        for(i=1;i<=n;i++)
        {
            //cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].p<<" "<<s[i].q<<endl;
            if(Mx<s[i].p)Mx=s[i].p;
            if(My<s[i].q)My=s[i].q;
        }
        printf("%d %d\n",Mx,My);
    }
}
