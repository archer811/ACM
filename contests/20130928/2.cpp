#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define N 1000001
int prime[N];
int main()
{
    int n,i,j;
    cin>>n;
    //for(i=0;i<num;i++)
    {
        for(j=2;j<=sqrt(n);j++)
        {
             if(n%j==0)cout<<j<<endl;
        }

    }

      cout<<"0"<<endl;
 return 0;
}
