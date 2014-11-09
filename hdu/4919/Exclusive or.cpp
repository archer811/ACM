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
#define ll __int64
int main()
{
    int i,j;
    freopen("out.txt","w",stdout);
    for(i=1;i<=30;i++)
    {
        int sum=0;
        for(j=1;j<i;j++)
        {
            sum += (j^(i-j));
            //cout<<j<<"*"<<(i-j)<<"  "<<(j^(i-j))<<endl;
        }
        cout<<i<<" "<<sum<<endl;
    }
    return 0;
}
