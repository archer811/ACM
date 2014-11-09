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
int next[maxn];
char s[maxn];
int main()
{
    int i,j,k;
    while(cin>>s)
    {
        int len = strlen(s);
        j=next[0]=-1;
        i=0;
        while(i<len)
        {
            while(-1!=j&&s[i]!=s[j])j=next[j];
            next[++i]=++j;
        }
        for(i=0;i<=len;i++)
            cout<<i<<" "<<s[i]<<" "<<next[i]<<endl;
    }
}
