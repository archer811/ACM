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
void dfs(int s,int t,int ff)
{

    if(s==x&&t==-1)
    {
        ll sum=0;
        for(int i=x-1; i>=0; i--)
            sum = sum*10+a[i];
        //if(judge())
        {
            if(ans==-1 || sum>ans)
                ans=sum;
        }
        return;
    }

    if(t == -1 && s-1 >= 0 && digit[s]==digit[s-1])
    {
        if(t+1>=num[s+1] || t==-1)
            dfs(s+1,t,ff);
    }
    if(s>=x || t<= -1)return;

    if(ff == 0 && a[s] == digit[t])
    {
//        if(s==2&&t==0)
//        cout<<s<<"  "<<t<<"  "<<ff<<"  "<<num[s]<<"  "<<num[s+1]<<"  "<<a[s]<<
//        "  "<<digit[t]<<endl;
        a[t] = digit[t];

        if(t>=num[s] || t-1==-1)
        {
//            cout<<"LUctk"<<s<<"  "<<t<<"  "<<ff<<endl;
            dfs(s,t-1,ff);
        }


        if(t>=num[s+1] || t-1 == -1)
            dfs(s+1,t-1,ff);
    }
    else if(ff == 0 && a[s] < digit[t])
    {
        //cout<<s<<" * "<<t<<"  "<<ff<<endl;
        a[t] = a[s];
        if(t>=num[s] || t-1 == -1)
            dfs(s,t-1,1);

        if(t>=num[s+1] || t-1 == -1)
            dfs(s+1,t-1,1);
    }
    else if(ff == 1 )
    {
        a[t]=a[s];

        if(t>=num[s] || t-1 ==-1 )
            dfs(s,t-1,1);

        if(t>=num[s+1] || t-1 == -1)
            dfs(s+1,t-1,1);
    }
}

void DFS(int pos,int num2,int s)
{
    int i,j;
    if(pos==-1)return;
    int s2 = s;
    if(pos==x-1 || (pos<x-1 && digit[pos]!=digit[pos+1]))
        s2 = s+1;


    if(num2==0)
    {
        a[pos]=digit[pos];
        num[pos]=s2;
        if(pos>=s2)
            dfs(pos,pos-1,num2);
        if(pos+1>=s2)
        {
            dfs(pos+1,pos-1,num2);
        }
        DFS(pos-1,num2,s2);
    }






//    if(pos==1)cout<<"ok"<<endl;
    if(digit[pos]>=1)
    {
        if(pos==x-1 || (pos<x-1 && digit[pos]-1!=digit[pos+1]))
            s2 = s+1;
        a[pos]=digit[pos]-1;
        num[pos]=s2;
        for(j=pos-1; j>=-1; j--)
        {
            if(j+1>=s2)
                dfs(pos,j,1);
            if(j+2>=s2)
                dfs(pos+1,j,1);
            if(j>=0)a[j]=9;
        }
        DFS(pos-1,1,s2);
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

        ans = -1;
        DFS(x-1,0,0);

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
