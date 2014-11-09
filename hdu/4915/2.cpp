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
#define ll long long
char s[1000006];
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        int sum=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='(')
                sum++;
            else if(s[i]==')')
            {
                if(sum-1>=0)sum--;
                else break;
            }
            else sum++;
        }
        if(i<len)puts("None");
        else
        {
            if(sum%2)puts("None");
            else if(sum==0||sum==2)puts("Unique");
            else puts("Many");
        }
    }
    return 0;
}
