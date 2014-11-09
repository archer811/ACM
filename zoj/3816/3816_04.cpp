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
int digit[22];
int x;
int a[22];
void f(ll n)
{
    x=0;
    while(n)
    {
        digit[x++] = n%10;
        n/=10;
    }
}

ll ans;
int b[22];
int num[22];
int judge()
{
    int k=0,i,j;
    for(i=x-1; i>=0; i--)
    {
        if(i==x-1 || (i<x-1 && a[i]!=a[i+1]))
            b[k++]=a[i];
    }
    i=0;
    j=k-1;
    for(i=0; i<k; i++,j--)
    {
        if(b[i]!=b[j])return 0;
    }
    return 1;
}
int k;
void dfs(int pos,int id,int ff)
{
    int i,j;
    //cout<<pos<<"  "<<id<<endl;
    if(pos==-1)
    {
//        for(i=x-1;i>=0;i--)
//            cout<<a[i];
//        cout<<endl;
        //if(judge())
        {
            ll sum=0;
            for(i=x-1; i>=0; i--)
                sum = sum*10+a[i];
            if(ans<sum)
                ans=sum;
               // cout<<sum<<"*"<<endl;
        }
        return;
    }
    //cout<<pos<<" "<<id<<endl;
    if(id==0)
    {
        for(i=pos; i>=0; i--)
        {
            if( ff==0 && b[id] == digit[pos])
            {
                a[i]=b[id];
            }
            else if(ff == 0 &&b[id] < digit[pos])
            {
                a[i]=b[id];
            }
            else if(ff==1)
            {
                a[i]=b[id];
            }
            else return;
        }
        dfs(-1,-1,ff);
        return;
    }
    for(i=pos; i-(id)>=0; i--)
    {
        if(ff==0 && b[id] == digit[pos])
        {
            a[i]=b[id];
            dfs(pos-1,id-1,ff);
        }
        else if(ff == 0 &&b[id] < digit[pos])
        {
            a[i]=b[id];
            dfs(pos-1,id-1,1);
        }
        else if(ff==1)
        {
            a[i]=b[id];
            dfs(pos-1,id-1,1);
        }
    }
}
int main()
{
    int i,j,t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(num,0,sizeof(num));
        if(n==1)
        {
            puts("0");
            continue;
        }
        f(n);
        int flag=0;
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
        if(digit[x-1]==1)
        {
            flag=0;
            for(i=0; i<x-1; i++)
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

        ans = -1;

        for(i=x-1; i>=0; i--)
        {
            a[i]=digit[i];
            flag=0;
            k=0;
            for(j=x-1; j>=i; j--)
            {
                if(flag==0&&a[j]==0)continue;
                flag=1;
                if(j<x-1 && a[j]==a[j+1])continue;
                b[k++]=a[j];
            }
//            for(j=0; j<k; j++)
//                cout<<b[j];
//            cout<<endl;
            if(i>=k)
            {
                dfs(i-1,k-1,0);
            }
            if(k>=2 && i>=k-1)
            {
//                cout<<"ok"<<endl;
                dfs(i-1,k-2,0);
            }



            if(digit[i]>=1)
            {
                a[i]=digit[i]-1;

                flag=0;
                k=0;
                for(j=x-1; j>=i; j--)
                {
                    if(flag==0&&a[j]==0)continue;
                    flag=1;
                    if(j<x-1 && a[j] == a[j+1])continue;
                    b[k++]=a[j];
                }
//                for(j=0; j<k; j++)
//                    cout<<b[j];
//                cout<<endl;
                if( k && i >= k)
                    dfs(i-1,k-1,1);
                if( k >= 2 && i>=k-1)
                    dfs(i-1,k-2,1);
                a[i]=digit[i];
            }
        }

        printf("%lld\n",ans);

    }
    return 0;
}
/*
1111111
11221
12
123
1224
1122

*/
