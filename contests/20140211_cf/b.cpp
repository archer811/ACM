#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[110000],b[110000];
int judge(int x,int i)
{
    if(x>=1&&x<=a[i])return 1;
    return 0;
}
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            cin>>b[i];
        long long sum=0;
        for(i=1;i<=n;i++)
        {
            int tmp = b[i]/2;
            int t1 = tmp,t2 = tmp;
            if(tmp*2<b[i])
                t1 = tmp,t2=tmp+1;
            if(a[i]*2>=b[i])
            {
                if(judge(t1,i)&&judge(t2,i))
                sum += (long long)t1*(long long)t2;
            else sum -=1;
            }
            else
            {

                {
                    sum-=(long long)1;
                }
            }
        }
        //if(sum<=-1)sum=-1;
        cout<<sum<<endl;
    }
}
