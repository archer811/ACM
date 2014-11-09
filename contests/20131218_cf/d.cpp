#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char str[1000005];
int a[1000005];
#define ll __int64
ll f[4][50005];
#define  A i%3
#define B (i-1+3)%3
#define C (i-2+3)%3
int main()
{
    int i,j;
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        for(i=1;i<=len;i++)
            a[i]=str[i-1]-'0';
        memset(f,0,sizeof(f));
        ll sum=1;
        ll tmp=1;
        for(i=1;i<=len;i++)
        {
            if(a[i]+a[i+1]==9&&i+1<=len)
            {
                for(j=i+1;j<=len;j++)
                {
                    if(a[j]+a[j+1]!=9)break;
                }
                tmp = j-i+1;
                if(tmp%2)sum*=(tmp/2+1);
                i=j;
            }
        }
        cout<<sum<<endl;
    }
}
