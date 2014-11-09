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
int a[30];
char s[1000];
int main()
{
    int i,j;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        for(i=0;i<n;i++)
        {
            a[s[i]-'A']++;
        }
        scanf("%s",s);
        int len=strlen(s);
        int flag=0;
        for(i=0;i<len;i++)
        {
            int tmp = s[i]-'A';
            if(a[tmp])a[tmp]--;
            else flag=1;
        }
        if(flag)puts("No");
        else puts("Yes");
    }
    return 0;
}
