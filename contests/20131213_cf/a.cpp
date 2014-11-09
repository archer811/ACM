#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int i,j;
    int sum=0;
    for(i=1;i<=100;i++)
    {
        sum += i*(i/2);
    }
    cout<<sum<<endl;
}
