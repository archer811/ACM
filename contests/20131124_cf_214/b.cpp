#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    j=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(j==k+1)j=1;
        b[j]+=a[i];
       // cout<<j<<" "<<a[i]<<endl;
        j++;
    }
    int ans=1e9,M=-1;
    for(i=1;i<=k;i++)
    {
        if(b[i]<ans)
            ans=b[i],M=i;
    }
    cout<<M<<endl;
}
