#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int f[10];
int main()
{
    int i,j;
    f[0]=-1;
    f[1]=2;
    int pos = lower_bound(f,f+2,0)-f;
    cout<<pos<<endl;
}
