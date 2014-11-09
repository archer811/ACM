#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[11];
int main()
{
    int i,j,k;
    while(scanf("%d",&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        char s[13];
        for(i=0;i<4;i++)
        {
            scanf("%s",s);
            for(j=0;j<4;j++)
            {
                int tmp = s[j]-'0';
                if(s[j]>='0'&&s[j]<='9')
                    a[s[j]-'0']++;
            }
           // if(s[])
        }
        bool flag=false;
        for(i=1;i<=9;i++)
        {
            int tmp = a[i];
            if(tmp>k*2)flag=true;
        }
        if(flag)puts("NO");
        else puts("YES");
    }
}
