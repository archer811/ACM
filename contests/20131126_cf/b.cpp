#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,d,a[100005],b[100005];
set<int>s;
set<int>::iterator it;
int main()
{
    int i,j,k,m;
    while(cin>>n>>m)
    {
        s.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);

        }
        for(i=n;i>=1;i--)
        {
            s.insert(a[i]);
            b[i]=s.size();
        }
        while(m--)
        {
            cin>>j;
            cout<<b[j]<<endl;
        }
    }
}
