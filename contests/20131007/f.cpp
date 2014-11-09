#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
ll a[1005];
int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        char s[2];
        ll ans =0,suma=0,sumt=0;
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(s[0]=='T')
            {
                if(a[i]-suma>=0)
                {
                    ans += a[i]-suma;
                    suma =0;
                }
                else
                {
                    suma = suma-a[i];
                }
            }
            else
            {
                suma += a[i];
            }
        }
        printf("%I64d\n",ans);
    }
}
