#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
int c[101][101];
int s[101],e[101];
int a,b,A,B;
void dfs(int x,int y);
void dfs2(int x,int y);
void dfs2(int x,int y)
{
    cout<<x<<" "<<y<<endl;
    int i,j;
    int tmp=0;
    int flag=0;
    int g = -1000000;
    for(i=0;i<n;i++)
    {
        if(s[i]>e[i])continue;
        tmp = c[i][e[i]];
        e[i]--;
        B += tmp;
        dfs(x,y+tmp);
        B -= tmp;
        e[i]++;
        if(B-A>g)
        {
            a=A;b=B;
            g=B-A;
        }
        flag=1;
    }
    if(flag==0)a=A,b=B;
}
void dfs(int x,int y)
{
    int i,j;
    int tmp=0;
    int g = -10000004;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(s[i]>e[i])continue;
        tmp = c[i][s[i]];
        cout<<i<<" "<<c[i][s[i]]<<"****"<<endl;
        s[i]++;
        A += tmp;
        dfs2(x+tmp,y);
        A -= tmp;
        s[i]--;
        if(A-B>g)
        {
            a=A;b=B;
            g=A-B;
        }
        flag=1;
    }
    if(flag==0)a=A,b=B;
    cout<<x<<"*"<<y<<" "<<a<<" "<<b<<endl;
}
int main()
{
    int i,j,k,d;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            s[i]=0;
            e[i]=0;
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                scanf("%d",&d);
                c[i][e[i]++]=d;
            }
            if(k)e[i]--;
        }
        for(i=0;i<n;i++)
        {
            cout<<"("<<i<<" "<<c[i][s[i]]<<endl;
        }
        A =0;B=0;
        a=0;b=0;
        dfs(0,0);
        printf("%d %d\n",a,b);
    }
}
