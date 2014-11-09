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
int a[1005],b[1005];
int main()
{
    int i,j;
    int c1,c2,c3,c4;
    while(cin>>c1>>c2>>c3>>c4)
    {
        int n,m;
        cin>>n>>m;
        int s1=0,s2=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            int tmp = min(c1*a[i],c2);
            s1+=tmp;
        }
        if(s1>c3)s1=c3;

        for(i=1;i<=m;i++)
        {
            cin>>b[i];
            int tmp = min(c1*b[i],c2);
            s2+=tmp;
        }
        if(s2>c3)s2=c3;
        int o=min(s1+s2,c4);
        //if(s1+s2<c4)s1+s2=c4;
        cout<<o<<endl;
    }
}
