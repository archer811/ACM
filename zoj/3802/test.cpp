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
int a[]={2,4,8,16};
int main()
{
    int i,j;
    freopen("in.txt","w",stdout);
    cout<<1<<" "<<500<<endl;
    for(i=0;i<500;i++)
    {
        cout<<a[rand()%4]<<endl;
    }
    return 0;
}
