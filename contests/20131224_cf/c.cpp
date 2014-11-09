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
    j = 1;
    for(i=1;i<=100;i++)
    {
        cout<<j%7<<endl;
        j = j*10%7;
    }
}
