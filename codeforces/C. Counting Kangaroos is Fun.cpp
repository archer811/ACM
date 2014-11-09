#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
const int maxn = 500005;
int s[maxn];
int judge(int mid)
{
    int i,j;
    j = mid+1;
    for(i=1;i<=mid;i++)
    {
        if(j>n)break;
//        if(mid==5)
//        cout<<i<<" "<<j<<" "<<s[j]<<" "<<s[i]<<endl;
        while(j<=n&&s[j]<2*s[i]){j++;}
        if(j<=n&&s[j]>=2*s[i]){j++;continue;}
        else
        {
            break;
        }


    }
    //cout<<i<<"&"<<j<<endl;
    if(i>mid)return 1;
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
        sort(s+1,s+n+1);
        int l = 1,r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(judge(mid)==0)r=mid;
            else l=mid+1;
        }
//        for(i=1;i<=n;i++)
//            cout<<judge(i)<<"("<<i<<endl;
        cout<<n-l+1<<endl;
    }
}
