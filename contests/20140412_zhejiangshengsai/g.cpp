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
int f(char *s)
{
    if(s[0]=='+'||s[0]=='-')return 1;
    return 0;
}
int f2(int a,int b,char *s)
{
    if(s[0]=='+')return a+b;
    if(s[0]=='-')return a-b;
    if(s[0]=='*')return a*b;
    if(s[0]=='/')return a/b;
    if(s[0]=='%')return a%b;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    char g[2],s[2];
    int a,b,c;
    while(t--)
    {
        scanf("%d%s%d%s%d",&a,g,&b,s,&c);
        int t1=f(g);
        int t2 = f(s);
        int y;
        if(t1==t2||(t1==0&&t2==1))
        {
            int x = f2(a,b,g);
            y = f2(x,c,s);
        }
        else if(t1==1&&t2==0)
        {
            int x = f2(b,c,s);
            y = f2(a,x,g);
        }
        printf("%d\n",y);
    }
}
