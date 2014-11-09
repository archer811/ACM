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
int a[100005];
int prime[100005+5000];
int a2[10005];
map<int,int>M;
int f[100005];
int Gcd[50005];
int sum[50005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k=0;
    for(i=2;i<=100000;i++)
    {
        if(a[i]==0)
        {
            prime[k++]=i;
            for(j=i+i;j<=100000;j+=i)
                a[j]=1;
        }
    }
    int n,m;
    while(cin>>n>>m)
    {
        M.clear();
        for(i=1;i<=n;i++)
        {
            cin>>a2[i];
            j = a2[i];
            for(int t=0;t<k;t++)
            {
                if(j==1)break;
                if(j%prime[t]==0)
                {
                    while(j%prime[t]==0)
                        j/=prime[t];
                }
            }
            if(j>1)
                prime[k++]=j;
        }
        for(i=0;i<m;i++)
        {
            cin>>j;
            M[j]=1;
        }
        int ans=0;
        for(i=1;i<=n;i++)
            Gcd[i]=1;
        for(i=0;i<k;i++)
        {
            int f=0;
            if(M[prime[i]])f=1;
            int X=1;
            for(j=1;j<=n;j++)
            {
                int tmp=0;
                int Y=1;
                if(a2[j]%prime[i]==0)
                {
                    while(a2[j]%prime[i]==0)
                    {
                        a2[j]/=prime[i];
                        tmp++;
                        Y*=prime[i];
                    }
                }
                if(f)ans-=tmp;
                else ans+=tmp;


                if(j==1)X=Y;
                else if(X>Y)X=Y;
                Gcd[j]*=X;
            }
        }
        int de=0;
//        cout<<ans<<endl;
//        for(i=1;i<=n;i++)
//            cout<<Gcd[i]<<" ";
//        cout<<endl;
        for(i=n;i>=1;i--)
        {
            int tmp = Gcd[i];
            if(Gcd[i]==Gcd[i+1])continue;
            int s=0;
            //cout<<tmp<<"Lool"<<endl;
            for(j=0;j<k;j++)
            {
                int tmp2=0;
                if(tmp==1)break;
                if(tmp%prime[j]==0)
                {
                    while(tmp%prime[j]==0)
                    {
                        tmp/=prime[j];tmp2++;
                    }
                }
                if(M[prime[j]])s-=tmp2;
                else s+=tmp2;
            }
           // cout<<s<<"-"<<de<<"   "<<i<<endl;
            if(s-de<0)
            {
                ans -= i*(s-de);
                de += s-de;
            }
           // cout<<ans<<"(("<<endl;
        }
        cout<<ans<<endl;
    }
}
