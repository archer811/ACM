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
    int i,j;
    long long sum=0;
    for(i=1;i<=100;i++)
    {
        long long tmp=1;
        for(j=1;j<=i;j++)
            tmp = tmp*i%7;
        sum += tmp;
        //cout<<i<<" "<<tmp%7<<endl;
        cout<<i<<" "<<tmp<<" "<<sum<<" "<<sum%7<<endl;
    }
}
