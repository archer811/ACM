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
#define ll long long
ll f[5000005];
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    f[1]=f[2]=1;
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d%d",&k,&n);
        if(n==2)
        {
            printf("%d 3\n",k);
            continue;
        }
        for(j=3; ; j++)
        {
            f[j]=f[j-1]+f[j-2];
            f[j]%=n;

            //cout<<j<<" "<<f[j-1]<<" "<<f[j]<<endl;
            if(f[j-1]==1&&f[j]==1)
            {
                printf("%d %d\n",k,j-2);
                break;
            }
        }

    }

    return 0;
}
