#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n;
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;

        for(j=0; j<=99; j++)
        {
            for(k=0; k<=99; k++)
            {
                //if(j!=k)
                {
                    if(n-j-k==0)
                    {
                        //cout<<j<<" "<<k<<endl;
                        sum++;
                    }
                }
            }
        }

        printf("%d\n",sum);
    }
}
