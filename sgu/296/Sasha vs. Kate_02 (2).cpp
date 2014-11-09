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
维护一个非递减序列，删掉能删的
如果还可以删，从序列末尾往前删

*/
const int N = 1006;
char s[N];
int k;
int b[N],flag[N];
int main()
{
    int i,j;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        int len = strlen(s);
        memset(flag,0,sizeof(flag));
        int x=0;
        for(i=0;i<len;i++)
        {
            for(j=x-1;j>=0;j--)
            {
                if(s[i]>s[b[j]])
                {
                    if(k-1<0)break;
                    k--;
                }
                else break;
            }
            x=j+1;
            b[x++]=i;
        }
        x = x-k;
        for(i=0;i<x;i++)
        {
            printf("%c",s[b[i]]);
        }
        puts("");
    }
    return 0;
}
