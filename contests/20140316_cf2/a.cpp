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
    int k,a,b,v;
    while(cin>>k>>a>>b>>v)
    {
        int sum=0;
        while(a>0)
        {
            int tmp = k-1;
            if(b<tmp)tmp=b;
            //if(tmp==0)
            a = a-v*(1+tmp);
            //cout<<a<<endl;
            b -= tmp;
            sum++;
        }
        cout<<sum<<endl;
    }
}
