#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 100010
#define inf 0x3f3f3f3f

int s[maxn];
int num[maxn];
int num2[maxn];
int sum[maxn];

int main()
{
    int n,m,query,pos;
    while(~scanf("%d",&n))
    {
        memset(s,0,sizeof(s));
        memset(num,0,sizeof(num));
        memset(num2,0,sizeof(num2));
        memset(sum,0,sizeof(sum));
        bool flag=false;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            if(i%3)
            {
                if(num[i]!=-1)
                {
                    flag=true;    //记录是否有除了3,6,9..之外的值给出。。。
                    pos=i;
                }
            }
            num2[i]=num[i];
        }

        for(int i=1; i<=n; i++)
            scanf("%d",&sum[i]);

        for(int i=1; i<=n; i++)
            if(i%3==0) num[i] = sum[i-1] - sum[i-2] + num[i-3];

        if(n%3==0)
        {
            for(int i=n; i>=1; i--)
                if(i%3==1)
                    num[i] = sum[i+1] - sum[i+2] + num[i+3];

            for(int i=1; i<=n; i++)
                if(i%3==2)
                    num[i] = sum[i] -num[i-1] -num[i+1];


            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&query);
                query++;
                printf("%d\n",num[query]);
            }
        }
        else if(n%3==1)
        {
            num[n] = sum[n] - num[n-1];
            for(int i=n-2; i>=1; i--)
                num[i] = sum[i+1] - num[i+1] -num[i+2];

            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&query);
                query++;
                printf("%d\n",num[query]);
            }
        }
        else
        {
            if(flag==true)
            {
                if(pos%3==2)
                {
                    num[pos-1] = sum[pos-1] -num[pos-2] -num[pos];
                    pos=pos-1;
                }
                for(int i=pos-2; i>=1; i--)
                    num[i]=sum[i+1]-num[i+1] -num[i+2];
                for(int i=pos+1; i<=n; i++)
                    num[i]=sum[i-1]-num[i-1]-num[i-2];

                scanf("%d",&m);
                while(m--)
                {
                    scanf("%d",&query);
                    query++;
                    printf("%d\n",num[query]);
                }
            }
            else
            {
                int t=1;
                for(int i=1; i<=(n-2); i++)
                {
                    if(i%3==2)
                    {
                        s[t++] = sum[i] - num[i+1];
                        s[t++] = sum[i+1] - num[i+1];
                    }
                }
                s[t] = sum[n];

                int mi=0,ma=inf,temp=0,cnt=1;
                for(int i=2; i<=n; i++)
                {
                    if(i%3)
                    {
                        num[i] = s[cnt++] - temp;
                        if(i%3==1) mi=max(mi,-num[i]);
                        else if(i%3==2) ma=min(ma,num[i]);
                        temp=num[i];
                    }
                }
                num[1] = 0;
                scanf("%d",&m);
                while(m--)
                {
                    scanf("%d",&query);
                    query++;
                    if(num2[query]!=-1) printf("%d\n",num2[query]);
                    else
                    {
                        if(query%3==0) printf("%d\n",num[query]);
                        else if(query%3==1) printf("%d\n",num[query]+ma);
                        else printf("%d\n",num[query]-mi);
                    }
                }
            }
        }
    }
    return 0;
}
