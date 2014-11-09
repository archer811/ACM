#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[100005];
int n,m;
int g[100005];
int judge(int a)
{
    int a1=0,a2=0,a3=0;
    bool flag=false;
    for(int i=0; i<7; i++,a++)
    {
//        if(s[a]=='z'&&s[a+1]=='y'&&s[a+2]=='x')flag=true;
//        if(s[a]=='x'&&s[a+1]=='z'&&s[a+2]=='y')flag=true;
//        if(s[a]=='y'&&s[a+1]=='x'&&s[a+2]=='z')flag=true;
        if(s[a]=='z')a1++;
        if(s[a]=='y')a2++;
        if(s[a]=='x')a3++;
//        if(s[a+1]=='z')a1++;
//        if(s[a+1]=='y')a2++;
//        if(s[a+1]=='x')a3++;
//        if(s[a+2]=='z')a1++;
//        if(s[a+2]=='y')a2++;
//        if(s[a+2]=='x')a3++;
        //
    }
    if(a1>=1&&a2>=1&&a3>=1)return 0;
    return 1;
}
#define max(a,b) ((a>b)?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

const int maxn=100001;
int mx[maxn][32],mn[maxn][32];

void rmq_init()
{
    int i,j;
    for(j=1; j<=n; j++) mx[j][0]=mn[j][0]=g[j];
    int m=floor(log((double)n)/log(2.0));
    for(i=1; i<=m; i++)
    {
        for(j=n; j>0; j--)
        {
            mx[j][i]=mx[j][i-1];
            if(j+(1<<(i-1))<=n) mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
        }
    }
    for(i=1; i<=m; i++)
    {
        for(j=n; j>0; j--)
        {
            mn[j][i]=mn[j][i-1];
            if(j+(1<<(i-1))<=n) mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
        }
    }
}
int Max,Min;
void rmq(int l,int r)
{
    int m=floor(log((double)(r-l+1))/log(2.0));
    int a=max(mx[l][m],mx[r-(1<<m)+1][m]);
    int b=min(mn[l][m],mn[r-(1<<m)+1][m]);
    Max=a;
    Min=b;
}
int x[maxn],y[maxn],z[maxn];
int judge2(int a,int b)
{
    int num1 = x[b]-x[a-1];
    int num2 = y[b]-y[a-1];
    int num3 = z[b]-z[a-1];
//                cout<<num1<<" * "<<num2<<" "<<num3<<endl;
    if((num1>=(b-a+1)/3&&num2>=(b-a+1)/3&&num3>=(b-a+1)/3))return 1;
    return 0;
}
int main()
{
    int i,j,k,a,b;
    while(cin>>s)
    {
        n = strlen(s);
        scanf("%d",&m);
        memset(g,0,sizeof(g));
        for(i=0; i<n-7; i++)
        {
            if(judge(i))g[i+1]=1;
            else g[i+1]=0;
        }
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        for(i=0; i<n; i++)
        {
            x[i+1]=x[i]+(s[i]=='x'?1:0);
            y[i+1]=y[i]+(s[i]=='y'?1:0);
            z[i+1]=z[i]+(s[i]=='z'?1:0);
            //if(i==1)cout<<
        }
//        for(i=1;i<=n;i++)

//            cout<<i<<"!"<<g[i]<<endl;
        while(m--)
        {
            scanf("%d%d",&a,&b);

            {
                int num1 = x[b]-x[a-1];
                int num2 = y[b]-y[a-1];
                int num3 = z[b]-z[a-1];
//                cout<<num1<<" * "<<num2<<" "<<num3<<endl;
                if((num1>=(b-a+1)/3&&num2>=(b-a+1)/3&&num3>=(b-a+1)/3))cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }

        }
    }
}

