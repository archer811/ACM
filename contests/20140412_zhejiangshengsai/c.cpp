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
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a);
            if(a>M)M=a;
            s[a]++;
        }
        int sum=0;
        int num=0,Max=-1;
        for(i=1; i<=M; i++)
        {
            if(s[i])
            {
                num+=s[i];
                if(i>Max)Max=i;
            }
        }
        if(num<=m)
        {
            sum += Max;
        }
        else
        {
            for(i=M; i>=1; i--)
            {
                if(s[i]>=m)
                {
                    sum += i*s[i]/m;
                    s[i]=0;
                    int tt = i*s[i]-i*s[i]/m*m;
                    s[1]+=tt;
                }
            }
//            cout<<sum<<endl;
//            for(i=1;i<=M;i++)
//                    cout<<i<<" "<<s[i]<<endl;
//                cout<<endl;
            while(1)
            {
                int x=0;
                for(i=M; i>=1; i--)
                {
                    if(s[i])
                    {
                        if(x+s[i]>=m)
                        {
                            int gg = min(m-x,s[i]);
                            s[i-1]+=gg;
                            s[i]-=gg;
//                            cout<<i<<"****"<<gg<<endl;
                            sum++;
                            for(j=i+1; j<=M; j++)
                            {
                                if(s[j])
                                {
                                    s[j-1]+=s[j];
                                    s[j]=0;
                                }
                            }
                            break;
                        }
                        else
                        {
                            x += s[i];
                        }
                    }
                }
//                for(i=1;i<=M;i++)
//                    cout<<i<<" "<<s[i]<<endl;
//                cout<<endl;
//cout<<sum<<endl;
                num=0,Max=-1;
                for(i=M; i>=1; i--)
                {
                    if(s[i])
                    {
                        num+=s[i];
                        if(i>Max)Max=i;
                    }
                }
                if(num<=m)
                {
                    if(Max>=0)
                      sum+=Max;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
}
