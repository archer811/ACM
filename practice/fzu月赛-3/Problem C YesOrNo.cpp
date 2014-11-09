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
const int maxn = 510000;
char s[maxn],t[maxn];
int len1,len2;
int judge(int mid)
{
    int strt=mid;
    int i=mid,j=0;
    for(; i<len1; i++)
    {
        if(s[i]!=t[j])break;
        j++;
    }
    if(i==len1)
    {
        for(i=0; i<strt; i++)
        {
            if(s[i]!=t[j])break;
            j++;
        }
    }
    if(j==len2)return 1;
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%s%s",s,t)!=EOF)
    {
        len1=strlen(s);
        len2= strlen(t);
        if(len1!=len2)
        {
            puts("No");
            continue;
        }
        int f=0;
        for(i=0; i<len1; i++)
        {
            if(s[i]==t[0])
            {
                if(judge(i))
                {
                    f=1;
                    break;
                }
            }
        }

        if(f)
            puts("Yes");
        else
            puts("No");
    }
}
