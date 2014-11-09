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

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0)
        {
            cout<<0<<" "<<1<<endl;
            cout<<0<<" "<<m<<endl;
            cout<<0<<" "<<0<<endl;
            cout<<0<<" "<<m-1<<endl;
        }
        else if(m==0)
        {
            cout<<1<<" "<<0<<endl;
            cout<<m<<" "<<0<<endl;
            cout<<0<<" "<<0<<endl;
            cout<<m-1<<" "<<0<<endl;
        }
        else
        {
            cout<<0<<" "<<0<<endl;
            cout<<n<<" "<<m<<endl;
            if(n>m)
            {
                cout<<0<<" "<<m<<endl;
                cout<<n<<" "<<0<<endl;
            }
            else
            {
                cout<<n<<" "<<0<<endl;
                cout<<0<<" "<<m<<endl;
            }

        }
    }

    return 0;
}
