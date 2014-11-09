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
int s[40005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int n,m,a;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(s,0,sizeof(s));
        int M=-1;
        int allsu=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&s[i]);
            allsu+=s[i];
            if(s[i]>M)M=s[i];
        }
        sort(s+1,s+1+n);
        int sum=0,ss=0;
        for(i=1; i<=n-m; i++)
        {
            ss += s[i];
//            s[i]=0;
//            cout<<i<<" "<<ss<<endl;
        }

        if(n-m>=1)
        {
            ss += m*s[n-m];

//
        }

        sum += ss/m;
cout<<ss<<endl;
        ss = ss%m;
        ss = m-ss;
        cout<<sum<<" "<<ss<<endl;
        if(n-m>=1&&s[n-m]<s[n-m+1])
        {
            ss = min(m,ss);
            if(ss)
                sum++;
            for(i=n;i>=1;i--)
            {
                if(ss)s[i]--,ss--;
                else break;
            }

            for(i=n-m+1;i<=n;i++)
                cout<<s[i]<<" ";
            cout<<endl;
        }
        else if(n-m>=1&&s[n-m]==s[n-m+1])
        {
            for(i=n-m+1; i<=n;i++)
            {
                if(ss)s[i]++,ss--;
                else break;
            }
        }
        if(n-m>=1)
        {
            for(i=n-m+1; i<=n; i++)
                s[i]-=s[n-m];
            for(i=1; i<=n-m; i++)
                s[i]=0;
        }

        int Max=-1;
        for(i=1; i<=n; i++)
        {
            if(s[i]>Max)Max=s[i];
        }
        if(Max!=-1)sum+=Max;
        sum=max(sum,M);
        printf("%d\n",sum);
    }
}
