#include<cstdio>
using namespace std;
int n;
double p;
//规律题
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        double p;
        scanf("%d%lf",&n,&p);
        int i;
        double ans=0,temp;
        if(p==1) ans=1.0*(n+1)*n/2;
        else
        {
            temp=1;
            for(i=1;i<=n;i++)
            {
                temp*=p;
                ans+=(n+1-i)*temp;
            }
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
