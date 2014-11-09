#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;
char s[100];
int a[100];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        getchar();
        for(i=0;i<n;i++)
        {
            gets(s);
            int x = s[0]-'A';
            a[x]=1;
        }
        j=-1;
        for(i=0;i<26;i++)
        {
            if(a[i]==0)break;
            j=i;
        }
        printf("%d\n",j+1);
    }

    return 0;
}
