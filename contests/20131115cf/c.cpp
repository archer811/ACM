#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500005],c[1000005];
const int N = 5005;
int lowbit( int n )
{
    return n & (-n);
}

void add( int n, int delta )
{
    while( n <= N )
    {
        c[n] += delta;
        n += lowbit(n);
    }
}

int sum( int n )
{
    int ret = 0;
    while( n != 0 )
    {
        ret += c[n];
        n -= lowbit(n);
    }
    return ret;
}
int s[5005][5005];
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        memset(c,0,sizeof(c));
        int num=0;
        for (i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(i=1;i<=n;i++)
        {
            add(a[i]+1,1);
            for(j=1; j<=n; j++)
                s[i][j]=i-sum(j),cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
            //cout<<i<<" "<<sum(a[i]+1)<<endl;
            num += s[i][a[i]+1];
        }
        int ans=0x3fffffff,Num=0;

        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                swap(a[i],a[j]);
                for(int k=1; k<=n; k++)
                    cout<<a[k]<<" ";
                cout<<endl;
                swap(a[i],a[j]);
                cout<<num<<endl;
                cout<<s[i][a[i]+1]<<"*"<<
                s[j][a[j]+1]<<"*"<<
                s[i][a[j]+1]<<"*"<<
                s[j][a[i]+1]<<
                endl;
                // cout<<i<<" "<<a[i]+1<<" "<<s[i][a[i]+1]<<endl;
                int tmp = num-s[i][a[i]+1]-s[j][a[j]+1];
                tmp += s[i][a[j]+1];
                if(a[i]>a[j])
                    tmp+=1;
                tmp += s[j][a[i]+1];
//                if(a[i]>a[j])
//                    tmp-=1;
                cout<<tmp<<endl;
                if(tmp<ans)
                {
                    ans=tmp;
                    Num=1;
                }
                else Num++;
            }
        }

        printf("%d %d\n",ans,Num);
    }
    return 0;
}

