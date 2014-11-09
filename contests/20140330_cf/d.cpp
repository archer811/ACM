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
char s[10000],t[10000];
int main()
{
    int num[1000];
    memset(num, 0, sizeof(num));
    scanf("%s",s);
    scanf("%s",t);
    for(int i = 0; s[i]; i++) num[ s[i] ] ++;
    int ans = 0;
    for(int i = 0; t[i]; i++)if(num[t[i]])
        {
            num[t[i]]--;
            ans++;
        }
        if(ans==0)ans=-1;
    printf("%d\n",ans);
}
