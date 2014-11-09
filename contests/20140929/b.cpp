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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
int f[20002];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int i,j,n,k;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
            cin>>f[i];
        sort(f+1,f+1+n,cmp);
        int sum=0;
        for(i=1;i<=n;i++)
        {
            int tmp = f[i]-1;
            sum += tmp*2;
            i = i+k-1;
            if(i>n)i=n;
        }
        cout<<sum<<endl;
    }
    return 0;
}
