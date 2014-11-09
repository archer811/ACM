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
char s2[1000];
ll f(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    else if(c>='A'&&c<='Z')return 10+c-'A';
    else return 36+c-'a';
}
int main()
{
    int i,j;
    ll s,k;
    while(scanf("%s%lld",s2,&k)!=EOF)
    {
        s=0;
        int len = strlen(s2);
        for(i=0;i<len;i++)
        {
           // cout<<s<<" "<<k<<" "<<f(s2[i])<<" "<<s*k+f(s2[i])<<endl;
            s = s*k+f(s2[i]);

        }
        //cout<<s<<endl;
        ll sum=0;
        ll now = 0;
        ll pow = k;
        if(s<k)
        {
            sum  = 0;
        }
        else if(s>=k&&s<=k*k)
        {
            sum = s/k;
        }
        else
        {
            cout<<sum<<endl;
            while(pow<=s)
            {
                sum += (pow/k-pow/k/k)*now;
               // cout<<(pow/k-pow/k/k)<<" "<<now<<endl;
                now++;
                pow = pow*k;
            }
            //cout<<s<<" "<<pow<<endl;
            if(s==pow/k)
            {
                ll ss=s;
                while(ss%k==0)
                {
                    ss/=k;
                    sum++;
                }
            }
            else
            {
                sum += ((s-pow/k)/k+1)*now;
                cout<<s-pow/k<<" "<<((s-pow/k)/k+1)<<" "<<now<<endl;
            }
            cout<<sum<<endl;
        }

        printf("%lld\n",sum);

    }
    return 0;
}
