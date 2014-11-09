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
#define ll long long
const ll mod = 1000000007;
string s[]= {"bowl", "knife", "fork", "chopsticks"};
int main()
{
    int i,j;
    int n;
    string t;
    while(scanf("%d",&n)!=EOF)
    {
        int mark=0;
        while(n--)
        {
            cin>>t;
            int a=t.length();
            int flag=0;
            for(i=0; i<4; i++)
            {
                int g=s[i].length();
                if(g!=a)continue;
                int f=0;
                for(j=0; j<a; j++)
                {
                    if(t[j]!=s[i][j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f)continue;
                flag=1;break;
            }
            if(flag)
            {
                if(mark)printf(" ");
                cout<<t;
                mark=1;
            }
        }
        puts("");
    }
    return 0;
}
