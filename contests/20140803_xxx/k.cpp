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
char s[100005];
int a[100005];
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        int flag=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            a[i]=s[i]-'0';
        }
        for(i=1;i<len;i++)
        {
            if(a[i]!=a[i-1])
            {
                for(j=0;j<=i-1;j++)
                    a[j]^=1;
            }
//            for(j=0;j<len;j++)
//                cout<<a[j];
//            cout<<endl;
        }
        int zero=0,onw=0;
        for(i=0;i<len;i++)
        {
            if(a[i])onw++;
            else zero++;
        }
        printf("%d %d\n",zero,onw);
    }
    return 0;
}
