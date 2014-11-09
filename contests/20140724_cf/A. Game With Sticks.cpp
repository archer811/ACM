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
    int i,j,n,m;
    while(cin>>n>>m)
    {
        n = min(n,m);
        if(n%2)puts("Akshat");
        else puts("Malvika");
    }
    return 0;
}
