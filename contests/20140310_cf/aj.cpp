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
    int i,j,n;
    int sum=0,x;
    while(cin>>n>>x)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            sum+=j;
        }
        if(sum<0)sum=-sum;
        int t=0;
        if(sum%x==0)t=sum/x;
        else t=sum/x+1;
        cout<<t<<endl;
    }
}
