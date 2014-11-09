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
#include<vector>
using namespace std;
#define ll long long
const ll mod = 1000000007;
map<string,int>M,N;
vector<string>v;
int main()
{
    int i,j;
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        M.clear();
        N.clear();
        v.clear();
        string s;
        for(i=0;i<a;i++)
        {
            cin>>s;
            M[s]=1;
        }
        for(i=0;i<b;i++)
        {
            cin>>s;
            v.push_back(s);
        }
        for(i=0;i<c;i++)
        {
            cin>>s;
            N[s]=1;
        }
        int len=v.size();
        int mark=0;
        for(i=0;i<len;i++)
        {
            s=v[i];
            if(M[s]&&N[s]==0)
            {
                if(mark)printf(" ");
                mark=1;
                cout<<s;
            }
        }
        if(mark==0)printf("No enemy spy");
        puts("");
    }
    return 0;
}
