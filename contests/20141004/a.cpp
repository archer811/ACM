#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
ll n,k;
int flag;
int ans[1005],num;
int digit2[20],g2,digit3[20];
int judge()
{
    int x = min(g2,num);
    for(int i=0;i<x;i++)
    {
        if(digit2[i]>ans[i])return 0;
        if(digit2[i]<ans[i])return 1;
    }
    if(g2>num)return 0;
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        if(n==0&&k==0)break;
        if(k==1)
        {
            puts("1");
            continue;
        }
        int g=0;
        ll nn = n;
        while(nn)
        {
            g++;
            nn/=10;
        }
        flag=0;
        for(i=1; i<=9; i++)
        {
            for(j=g-1; j>=0; j--)
            {
                ll tmp = (ll)i;
                ll ex = (ll)1;
                for(int t=j-1; t>=0; t--)
                    tmp = tmp*(ll)10,ex = ex*(ll)10;
                ll tmp2 = ((-tmp)%k+k)%k;
//                if(tmp==1)
//if(tmp==100)
//                cout<<tmp<<"*"<<tmp2<<" "<<ex<<endl;
                if(tmp2<ex)
                {
                    tmp += tmp2;
                    if(tmp<=n)
                    {
//                        if(tmp==1)
//                            cout<<"ooo"<<endl;
                        int gg2=0;
                        while(tmp)
                        {
                            digit3[gg2++]=tmp%10;
                            tmp/=10;
                        }
                        g2=0;
                        for(int o=gg2-1;o>=0;o--)
                            digit2[g2++]=digit3[o];
                        if(flag==0 || judge())
                        {
                            num=0;
                            for(int o=0;o<g2;o++)
                                ans[num++]=digit2[o];
                            flag=1;
                        }
                    }
                }
            }
        }
        for(i=0;i<num;i++)
            printf("%d",ans[i]);
        puts("");
        //cout<<f<<endl;
        //printf("%lld\n",ans);
    }
    return 0;
}
