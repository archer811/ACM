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
const int maxn = 100005;
char s[maxn],t[maxn];
void extKmp(int n, const char pat[], int a[])
{
    int p = 0, k = 1;
    a[0] = n;
    while (p + 1 < n && pat[p + 1] == pat[p])
    {
        ++p;
    }
    a[1] = p;
    for (int i = 2; i < n; ++i)
    {
        int x = k + a[k] - i, y = a[i - k];
        if (y < x)
        {
            a[i] = y;
        }
        else
        {
            p = max(0, x);
            while (p + i < n && pat[p + i] == pat[p])
            {
                ++p;
            }
            a[i] = p;
            k = i;
        }
    }
}
int f1[maxn],f2[maxn];
int main()
{
    int i,j;
    while(scanf("%s%s",s,t)!=EOF)
    {
        int len1=strlen(s);
        extKmp(len1,s,f1);
        int len2=strlen(t);
        extKmp(len2,t,f2);
        int ans=0;
        for(i=1,j=1; s[i-1]==t[j-1]&&i<=len1&&j<=len2; i++,j++)
        {
            if(len1%(i)==0&&len2%(j)==0&&f1[i]==len1-i&&f2[j]==len2-j)
            {
               // cout<<i<<endl;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

