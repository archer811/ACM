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
int f(int x)
{
    int s=0;
    while(x%4==0){s++;x/=4;}return s;
}
int main()
{
    int i,j;
    freopen("k.txt","w",stdout);
    for(i=4;i<=10009;i+=4)
    {
        cout<<i<<" "<<f(i)<<endl;
    }
    return 0;
}
