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
char s[2000];
int siusernam(int l,int r)
{
    int len=r-l+1;
    if(!(len>=1&&len<=16))return 0;
    int i,j,flag=0;
    for(i=l;i<=r;i++)
    {
        if(s[i]>='a'&&s[i]<='z')continue;
        if(s[i]>='A'&&s[i]<='Z')continue;
        if(s[i]>='0'&&s[i]<='9')continue;
        if(s[i]=='_')continue;
        flag=1;
    }
    if(flag)return 0;
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        int s1=0,s2=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='@')s1++;
            if(s[i]=='/')s2++;
        }
        if(!(s1==1&&s2<=1))
        {
            puts("NO");continue;
        }
        s1=-1;s2=-1;
        for(i=0;i<len;i++)
        {
            if(s[i]=='@')s1=i;
            if(s[i]=='/')s2=i;
        }
        int flag=0;
        if(!siusernam(0,s1-1))flag=1;
        if(s2==-1)s2=len;
        else
        if(!siusernam(s2+1,len-1))flag=1;
        int pre=s1+1;
        s[s2]='.';
        for(i=s1+1;i<=s2;i++)
        {
            if(s[i]=='.')
            {
                if(!siusernam(pre,i-1))flag=1;
                pre=i+1;continue;
            }
        }
        if(!(s2-1-s1>=1&&s2-1-s1<=32))flag=1;
        if(flag)puts("NO");
        else puts("YES");
    }
    return 0;
}
