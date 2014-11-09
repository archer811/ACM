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
const int maxn = 100005;
int a[maxn],b[maxn];
struct array
{
    int id;
    char s[55];
}g[maxn*2];
int cmp(array x,array y)
{
    return strcmp(x.s,y.s)<0;
}
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        int k=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",g[k].s);
            g[k].id=i*2;
            k++;
            scanf("%s",g[k].s);
            g[k].id=i*2+1;
            k++;
        }
        sort(g,g+k,cmp);
        for(i=0;i<k;i++)
        {
            int t = g[i].id;
            if(t%2==0)
                a[t/2]=i+1;
            else
                b[t/2]=i+1;
        }
        int M=0,flag=0;
//        for(i=0;i<n;i++)
//            cout<<a[i]<<" "<<b[i]<<endl;
        for(i=0;i<n;i++)
        {
            cin>>j;j--;
            int o = min(a[j],b[j]);
            if(o<M)
            {
                int o2 = max(a[j],b[j]);
                if(o2<M)
                flag=1;
                else
                {
                    M = max(M,o2);
                }
            }
            else M = max(M,o);
//        cout<<o<<"*"<<M<<endl;
        }
        if(flag)puts("NO");
        else puts("YES");
    }
    return 0;
}
