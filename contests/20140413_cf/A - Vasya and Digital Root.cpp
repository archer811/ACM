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
    int k,d;
    while(cin>>k>>d)
    {
        if(k>1&&d==0){puts("No solution");continue;}
        cout<<d;
        for(i=0;i<k-1;i++)
            cout<<"0";
    }
}
