#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=(int)1e7;
int F[N+5];
int cnt_1[N+5];
int cnt_2[N+5];
int S[N+5];

void Get_Prime()
{
    S[2]=0;
    for (int i=2; i<=N; i++)
    {
        if(i==100)break;
        if (cnt_1[i]==0)
        {
            F[i]=i;
            cnt_1[i]=1;
        }
        for (int j=2,k=i+i; j<=F[i]; j++,k+=i)
        {
            if (k>N) break;
            F[k]=j;
            //if(k==8)cout<<cnt_2[k]<<" "<<cnt_2[i]<<" *** "<<(j==F[i])<<endl;
            cnt_2[k]=cnt_2[i]+(j==F[i]);  //计算k有多少个i^2形式的因子
            cnt_1[k]=cnt_1[i]+1;    //计算k有多少个因子。
        }
        cout<<i<<" "<<cnt_1[i]<<" "<<cnt_2[i]<<endl;

        int t;
        int &c1=cnt_1[i];
        int &c2=cnt_2[i];
        if (c2==0)
            if (c1&1)
                t=c1;
            else
                t=-c1;
        else if (c2==1) t=( (c1&1)?1:-1 );
        else t=0;
        cout<<i<<"*"<<t<<endl;
        S[i+1]=S[i]+t;
    }
}

int main()
{
    Get_Prime();
    int Tc,m,n,d1,d2,Next_1,Next_2,Next;
    scanf("%d",&Tc);
    while (Tc--)
    {
        scanf("%d%d",&m,&n);
        if (m>n) swap(m,n);
        long long ans=0;
        for (int i=2; i<=m;)
        {
            d1=m/i;
            d2=n/i;
            Next_1=m/d1+1;          //Next_1>i && m/Next_1>m/i
            Next_2=n/d2+1;          //they are the same
            Next=Next_1<Next_2?Next_1:Next_2;   // Get minimum
            ans+=(long long)(S[Next]-S[i])*d1*d2;
            i=Next;
        }
        printf("%lld\n",ans);
    }
}
