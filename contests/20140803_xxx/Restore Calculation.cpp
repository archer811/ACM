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

#define ll long long
const ll mod = 1e9+7;
string s,t,e,s2,t2,e2;
ll d[1000][2];
int main()
{
    int i,j;
    while(cin>>s2)
    {
        if(s2.length()==1&&s2[0]=='0')break;
        cin>>t2>>e2;
        s=t=e="";
        memset(d,0,sizeof(d));
        int a=s2.length();
        j=0;
        for(i=a-1;i>=0;i--)
        {
            s+=s2[i];
        }
        s+='\0';
        int b=t2.length();
        j=0;
        for(i=b-1;i>=0;i--)
        {
            t+=t2[i];
        }
        t+='\0';
        int c=e2.length();
        j=0;
        for(i=c-1;i>=0;i--)
        {
            e+=e2[i];
        }
        e+='\0';
       // cout<<s<<" "<<t<<" "<<e<<endl;
        int M=max(a,b);
        M = max(M,c);
        for(i=0;i<M;i++)
        {
            int sa=-1,ea=-1,sb=-1,eb=-1,sc=-1,ec=-1;
            if(i==a-1)
            {
                if(s[i]=='?'){sa=1;ea=9;}
                else {sa=ea=s[i]-'0';}
            }
            else if(i>a-1)
            {
                sa=0;ea=0;
            }
            else
            {
                if(s[i]=='?'){sa=0;ea=9;}
                else {sa=ea=s[i]-'0';}
            }


            if(i==b-1)
            {
                if(t[i]=='?'){sb=1;eb=9;}
                else {sb=eb=t[i]-'0';}
            }
            else if(i>b-1)
            {
                sb=0;eb=0;
            }
            else
            {
                if(t[i]=='?'){sb=0;eb=9;}
                else {sb=eb=t[i]-'0';}
            }



            if(i==c-1)
            {
                if(e[i]=='?'){sc=1;ec=9;}
                else {sc=ec=e[i]-'0';}
            }
            else if(i>c-1)
            {
                sc=0;ec=0;
            }
            else
            {
                if(e[i]=='?'){sc=0;ec=9;}
                else {sc=ec=e[i]-'0';}
            }
            //cout<<sa<<"*"<<ea<<" "<<sb<<" "<<eb<<" "<<sc<<" "<<ec<<endl;
            int g1=0,g2=0,g3=0,g4=0;
            for(int x=sa;x<=ea;x++)
            {
                for(int y=sb;y<=eb;y++)
                {
                    for(int z=sc;z<=ec;z++)
                    {
                        if(x+y==z)
                        {
                            if(i-1>=0)
                            (d[i][0]+=d[i-1][0])%=mod;
                            else d[i][0]++;
                            g1++;
                        }
                        if(x+y+1==z)
                        {
                            if(i-1>=0)
                            (d[i][0]+=d[i-1][1])%=mod;
                            //else d[i][0]++;
                            g2++;
                        }
                        if(x+y==z+10)
                        {
                            if(i-1>=0)
                            (d[i][1]+=d[i-1][0])%=mod;
                            else d[i][1]++;
                            g3++;
                        }
                        if(x+y+1==z+10)
                        {
                            if(i-1>=0)
                            (d[i][1]+=d[i-1][1])%=mod;
                            //else d[i][1]++;
                            g4++;
                        }
                    }
                }
            }
            d[i][0]%=mod;
            d[i][1]%=mod;
            //cout<<g1<<"!"<<g2<<" "<<g3<<" "<<g4<<endl;
            //cout<<i<<" * "<<d[i][0]<<" "<<d[i][1]<<endl;
        }
        ll sum=d[M-1][0];
        sum %= mod;
        printf("%lld\n",sum);
    }
    return 0;
}
