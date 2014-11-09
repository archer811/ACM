#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 1000005;
char s[maxn];
int f[maxn],c[maxn];
int main()
{
    int i,j,k;
    while(gets(s+1))
    {
        memset(c,0,sizeof(c));
        j=0;
        int n = strlen(s+1);
        cout<<n<<endl;
        for(i=2;i<=n;i++)
        {
            while (j>0 && s[i]!=s[j+1]) j=f[j];
            if(s[i]==s[j+1])j++;
            c[f[i]=j]++;
        }//
        for(i=1;i<=n;i++)
            cout<<i<<" "<<s[i]<<" "<<f[i]<<endl;
    }
}
