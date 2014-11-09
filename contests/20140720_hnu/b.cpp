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
int findFirstGreaterThanOrEqual(int array[], int N, int X)
{
    int start = 0, end = N;
    while (start < end)
    {
        int middle = (start + end) / 2;
        if (array[middle] > X)
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    return start;
}
int a[10];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int x;
        cin>>x;
        cout<<findFirstGreaterThanOrEqual(a,n,x)<<endl;
    }
    return 0;
}
