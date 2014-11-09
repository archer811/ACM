//source here
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define pi acos(-1.0)
using namespace std;
char s[22];
double get(double x,char *s)
{
    if(s[0]=='m')return x*1000;
    if(s[0]=='d')return x*100;
    if(s[0]=='c')return x*10;
    if(s[0]=='u')return x*0.001;
    if(s[0]=='n')return x*0.000001;
    return x;
}
char g[100];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        double f,c,o;
        scanf("%s",g);
        int len = strlen(g);
        f=0;
        int flag=0;
        double l = 0.1;
        for(i=0;i<len;i++)
        {
            if(g[i]!='.'&&(g[i]<'0'||g[i]>'9'))break;
            if(g[i]=='.'){flag=1;continue;}
            if(flag)
            {
                f = f+(g[i]-'0')*l;
                l *= 0.1;
            }
            else
            {
                f = f*10+(g[i]-'0');
            }
        }
        j=0;
        for(;i<len;i++)
            s[j++]=g[i];
        f = get(f,s);

        scanf("%s",g);
        len = strlen(g);
        c=0;
        flag=0;
        l = 0.1;
        for(i=0;i<len;i++)
        {
            if(!(g[i]>='0'&&g[i]<='9'))
            {
                if(g[i]!='.')break;
            }

            if(g[i]=='.'){flag=1;continue;}
            if(flag)
            {


                c = c+(double)(g[i]-'0')*l;
                l *= 0.1;
            }
            else
            {
                c = c*10+(g[i]-'0');
            }
        }
        j=0;
        for(;i<len;i++)
            s[j++]=g[i];
        c = get(c,s);


        scanf("%s",g);
        len = strlen(g);
        o=0;
        flag=0;
        l = 0.1;
        for(i=0;i<len;i++)
        {
            if(g[i]!='.'&&(g[i]<'0'||g[i]>'9'))break;
            if(g[i]=='.'){flag=1;continue;}
            if(flag)
            {
                o = o+(g[i]-'0')*l;
                l *= 0.1;
            }
            else
            {
                o = o*10+(g[i]-'0');
            }
        }
        j=0;
        for(;i<len;i++)
            s[j++]=g[i];
        printf("Case %d: %.2fpx\n",++cas,o*f/c*1.0);
    }
    return 0;
}
