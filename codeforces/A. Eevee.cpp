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
string a[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main()
{
    char s[100];
    int len,i,j;
    while(scanf("%d",&len)!=EOF)
    {
        scanf("%s",s);
        for(i=0;i<8;i++)
        {
            if(a[i].length()==len)
            {
                int flag=0;
                for(j=0;j<len;j++)
                {
                    if(s[j]!='.'&&s[j]!=a[i][j])flag=1;
                }
                if(flag==0)
                {
                    cout<<a[i]<<endl;break;
                }
            }
        }
    }

    return 0;
}
