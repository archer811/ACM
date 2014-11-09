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
    int i,j,k;
    freopen("in.txt","w",stdout);
    int t=0;
    cout<<160982<<endl;
    for(i=1;i<=100;i++)
    {
        for(j=0;j<=i;j++)
        {
            for(k=0;k<=j;k++)
                cout<<(++t)<<" "<<i<<" "<<j<<"  "<<k<<endl;
        }
    }
    return 0;
}
