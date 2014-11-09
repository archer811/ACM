#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
/*
方向考虑，取len-k个，
保留后面k个，前面的取最大的一个
同样方法找

*/
const int N = 1005;
char s[N];
int k;
int ans[N];
int main()
{
    int i,j;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        int f=0;
        int len = strlen(s);
        int x=0;
        k = len-k;
        int kk=k;
        while(f<kk)
        {
            int M=-1,ff=-1;
            for(j=x;j<=len-k;j++)
            {
                if(s[j]>M)
                {
                    M=s[j];
                    ff=j;
                }
            }
            ans[f++]=ff;
            x = ff+1;
            k--;
        }
        for(i=0;i<f;i++)
        {
            printf("%c",s[ans[i]]);
        }
        puts("");
    }
    return 0;
}
