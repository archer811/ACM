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
int digit[20];
int x;
int ans[22];
void f(ll n)
{
    int i,j=0;
    while(n)
    {
        digit[j++]=n%10;
        n/=10;
    }
    x = j;
}
int flag;
void f(int x,int y)// change x to y
{
    if(flag == 0)
    {
        flag = 0;
    }
    else if(flag == -1)
    {
        if(y>x)flag=0;
        else if(y<x)flag=1;
    }
    else
    {
        if(y>x)flag=0;
    }
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        ll n;
        memset(digit,0,sizeof(digit));
        memset(ans,0,sizeof(ans));
        scanf("%lld",&n);

        flag=0;
        f(n);
        if(x==1)
        {
            printf("%lld\n",n-1);
            continue;
        }


        if(digit[0]==1&&digit[x-1]==1)
        {
            for(i=1; i<x-1; i++)
            {
                if(digit[i]!=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(i=0; i<x-1; i++)
                    printf("9");
                puts("");
                continue;
            }
        }

        n --;
        f(n);


        if(x==1)
        {
            printf("%lld\n",n);
            continue;
        }


        i = x-1;
        j = 0;
        flag = -1;
        while(i-j>=2)
        {
            if(i+1<=x-1 && digit[i]==digit[i+1])
            {
                ans[i]=digit[i];
                i--;
            }
            else
            {
                //cout<<i<<"*"<<j<<" "<<digit[j]<<" "<<digit[i]<<"  "<<flag<<endl;
                f(digit[j],digit[i]);
                //cout<<flag<<endl;
                ans[i]=digit[i];
                ans[j]=digit[i];
                i--;
                j++;
            }
            if(i==j+1 && i+1<=x-1 && digit[i] == digit[i+1])
            {
                ans[i]=digit[i];
                i--;
            }
        }


        //cout<<i<<" "<<j<<"  "<<flag<<endl;
        if(i==j+1)
        {
            if(flag==0)
            {
                if( (digit[j]>digit[i]) )
                {
                    ans[i]=ans[j]=digit[i];
                    if(i+1<=x-1 && ans[i+1]>ans[j] && ans[i+1] <digit[j])
                        ans[j]=digit[i+1];
                }
                else
                {
                    if(i+1<=x-1 && digit[i+1]<digit[j])
                    {
                        ans[j]=digit[i+1];
                        ans[i]=digit[i];
                    }
                    else
                    {
                        if(digit[i]>=1)
                        {
                            ans[i]=digit[i]-1;
                            int tmp = ans[i];
                            if(i+1<=x-1)
                                tmp = max(tmp,ans[i+1]);
                            ans[j]=tmp;
                        }
                        else
                        {
                            int g = i+1;
                            if(g+1<=x-1 && digit[g] == digit[g+1])
                            {
                                ans[j]=digit[g]-1;
                                ans[i]=9;
                                ans[g]=digit[g]-1;
                            }
                            else
                            {
                                ans[j-1]=ans[g]=digit[g]-1;
                                ans[i]=ans[j]=9;
                            }
                        }
                    }
                }
            }
            else
            {
                if(digit[j]>digit[i])
                {
                    ans[i]=ans[j]=digit[i];
                    if(i+1<=x-1&&ans[i+1]>ans[j]&&ans[i+1]<=digit[j])
                        ans[j]=ans[i+1];
                }
                else if(digit[i]==digit[j])
                {
                    ans[i]=ans[j]=digit[i];
                }
                else
                {
                    if(i+1<=x-1 && digit[i+1]<=digit[j])
                    {
                        ans[i]=digit[i];
                        ans[j]=digit[i+1];
                    }
                    else
                    {
                        ans[i]=digit[i]-1;
                        int tmp = ans[i];
                        if(i+1<=x-1)
                            tmp = max(tmp,ans[i+1]);
                        ans[j]=tmp;
                    }
                }
            }
        }
        else if(i==j)
        {
            //cout<<digit[i]<<"()"<<endl;
            if(flag==0)
            {
                if(digit[j]>=1)
                {
                    ans[j]=digit[j]-1;
                }
                else
                {
                    if(digit[j+1]>=1)
                    {
                        if(j+2<=x-1 && digit[j+2] == digit[j+1])
                        {
                            // cout<<"oo"<<endl;
                            ans[j+1]=digit[j+1]-1;
                            int tmp = ans[j+1];
                            tmp = max(tmp,ans[j+2]);
                            ans[j]=tmp;
                        }
                        else
                        {
                            ans[j-1]=ans[j+1]=digit[j+1]-1;
                            ans[j]=9;
                        }
                    }
                    else
                    {
                        for(int g=j+1; g<x; g++)
                        {
                            if(digit[g]!=0)
                            {
                                if(g+1<=x-1 && digit[g+1] == digit[g])
                                {
                                    ans[j-1]= ans[g] = digit[g]-1;
                                    for(int ss=g-1; ss>=j; ss--)
                                        ans[ss]=9;
                                }
                                else
                                {
                                    ans[g]=ans[j-2]=digit[g]-1;
                                    for(int ss=g-1; ss>=j-1; ss--)
                                        ans[ss]=9;
                                }
                                break;
                            }
                        }
                    }

                }

            }
            else
            {
                ans[j]=digit[j];
            }
        }
        for(i=x-1; i>=0; i--)
            printf("%d",ans[i]);
        puts("");
    }
}
/*
4132323
12
123
1224
1122

*/
