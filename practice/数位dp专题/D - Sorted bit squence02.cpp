#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
long long o = (long long )1<<31;
int main()
{
    cout<<o<<endl;
    for(int i=0;i>=-5;i--)
    {
        int j = i^(1<<31);
        cout<<i<<" "<<j<<" "<<o+i<<endl;
    }
}
