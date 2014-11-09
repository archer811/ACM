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
int main()
{
    int i,j,t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        int a[20],s=0;
        for(i=0;i<15;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>a[i-1])s++;
        }
        cout<<k<<" "<<s<<endl;
    }
    return 0;
}
