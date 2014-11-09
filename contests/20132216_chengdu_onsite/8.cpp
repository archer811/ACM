#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
map<char,int>M;
char s[][10]={"B","KB","MB","GB","TB","PB","EB","ZB","YB"};
char g[10000];
int main()
{
    int i,j,k,t;
    double p=1000.00/1024.00;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%s",g);
        int len = strlen(g);
        char a[10];
        int num=0;
        for(i=0;i<len;i++)
        {
            if(g[i]=='[')break;
            num = num*10+g[i]-'0';
        }
        i++;j=0;
        //cout<<num<<endl;
        for(;i<len;i++)
        {
            if(g[i]=='B')
            {
                a[j++]=g[i];break;
            }
            a[j++]=g[i];
        }a[j]='\0';
        //cout<<a<<endl;
        for(i=0;i<9;i++)
        {
            if(strcmp(s[i],a)==0)
            {
                break;
            }
        }
        double q = 1;
        //cout<<i<<endl;
        for(j=1;j<=i;j++)
        {
            //cout<<q<<"*"<<endl;
            q = q*p;
            //cout<<q<<endl;
        }
        q = 1-q;
        printf("Case #%d: %.2f%%\n",++cas,q*100.0);
    }
}
