#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k;
    int sum=0;
    for(i=300; i<=400; i++)
    {
        int ii = i/2,gg = (i+1)/2;
        j = i^(ii);
        int g = i+1;
        k = g^gg;
        int a[10]= {0},b[10]= {0};

        int t=0;
        while(j)
        {
            if(j%2)a[t++]=1;
            else a[t++]=0;
            j/=2;
        }



        t=0;
        while(k)
        {
            if(k%2)b[t++]=1;
            else b[t++]=0;
            k/=2;
        }
        //if(!((a[0]==0&&b[0]==1)||(a[0]==1&&b[0]==0)))
        {
            for(int kk = 9; kk>=0; kk--)
                cout<<a[kk];
            cout<<endl;
            for(int kk = 9; kk>=0; kk--)
                cout<<b[kk];
            cout<<endl;
            cout<<endl;
        }
        sum++;

    }
    cout<<sum<<endl;
}
