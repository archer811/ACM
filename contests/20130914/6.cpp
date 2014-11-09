#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const ll mod = (ll)1000000007;
char s[100005],t[100005];
ll a[100005],b[100005];
char anss[100005],anst[100005];
int main()
{
    int i,j,k,n,len;
    scanf("%d",&n);
    int cas=0;
    while(n--)
    {
        scanf("%s%s",s,t);
        len = strlen(s);
        printf("Case #%d:\n",++cas);
        if(len==1)
        {
            if((s[0]=='1')||(t[0]=='0'))
            {
                printf("Impossible\n");
            }
            else
            {
                puts("0");puts("1");
            }
            continue;
        }
        for(i=0; i<len; i++)
            anss[i]=s[i],anst[i]=t[i];
        for(i=0; i<len; i++)
        {
            ll tmp;
            if(i==0)tmp = 1;
            else tmp = a[i-1];
            if(s[i]=='?'&&t[i]=='?')
                tmp *= 2;
            a[i]=tmp%mod;

            if(i==len-1)
                tmp = 1;
            else tmp = b[i+1];
            if(s[i]=='?'&&t[i]=='?')
                tmp *= 2;
            b[i]=tmp;
        }
        //cout<<a[0]<<"""""""''''''''''''''''''''''''"<<len<<endl;
        //cout<<anss<<endl<<anst<<endl;
        ll sum =0;
        int flag =0;
        if(len>=2)
        {
            //cout<<s[len-2]<<"&"<<t[len-1]<<endl;
            if(s[len-2]!='0'&&t[len-2]!='0'&&s[len-1]!='0'&&t[len-1]!='1')
            {
                ll tmp;
                if(len-3>=0)tmp=a[len-3];
                else tmp =1;
               // cout<<tmp<<"""""""''''''''''''''''''''''''"<<len<<endl;
                sum += tmp;flag=1;
            }
            //cout<<s[len-2]<<" "<<t[len-2]<<" "<<s[len-1]<<" "<<t[len-1]<<endl;
            if(s[len-2]!='1'&&t[len-2]!='1'&&s[len-1]!='1'&&t[len-1]!='0')
            {

                ll tmp;
                if(len-3>=0)tmp=a[len-3];
                else tmp =1;
                sum += tmp;flag=2;
            }
            sum %= mod;
        }
        //cout<<sum<<"()"<<endl;
        if(flag==1)
        {
            for(i=0; i<len-2; i++)
            {
                if(s[i]!='?'&&t[i]!='?')continue;
                if(s[i]=='?')anss[i]=t[i];
                if(t[i]=='?')anst[i]=s[i];
            }
            anss[len-2]='1';
            anss[len-1]='0';
            anst[len-2]='1';
            anst[len-1]='1';
        }
        else if(flag==2)
        {
            for(i=0; i<len-2; i++)
            {
                if(s[i]!='?'&&t[i]!='?')continue;
                if(s[i]=='?')anss[i]=t[i];
                if(t[i]=='?')anst[i]=s[i];
            }
            anss[len-2]='0';
            anss[len-1]='0';
            anst[len-2]='0';
            anst[len-1]='1';
        }
        //cout<<sum<<endl;
        s[len]=t[len]='0';
        int mark;
        for(i=len; i>=0; i--)
        {
            if(s[i]=='1'||t[i]=='1')break;
            //cout<<i<<"()()"<<endl;
            if(i-2>=0&&s[i-1]!='0'&&t[i-1]!='0')
            {
                //cout<<i<<endl;
                mark = i;
                anss[i]=anst[i]='0';
                anss[i-1]=anst[i-1]='1';

                if(i-2==0)
                {
                    //cout<<"*"<<endl;
                    if(s[i-2]!='1'&&t[i-2]!='0')
                    {
                        sum++;anss[i-2]='0';anst[i-2]='1';
                       // cout<<anss<<endl;
                       // cout<<anst<<endl;
                    }
                }
                if(i-2>0)
                {
                    ll tmp = a[i-3];
                    anss[i-2]='0';
                    anst[i-2]='1';
                    if(s[i-2]=='?'&&t[i-2]=='?')
                    {
                        sum += tmp;
                        sum%=mod;
                    }
                    else if(s[i-2]=='0'&&t[i-2]=='?')
                    {
                        sum += tmp;
                        sum%=mod;
                    }
                    else if(s[i-2]=='?'&&t[i-2]=='1')
                    {
                        sum += tmp;
                        sum%=mod;
                    }
                    else if(s[i-2]=='0'&&t[i-2]=='1')
                    {
                        sum += tmp;
                        sum%=mod;
                    }
                }
                //cout<<anss<<"!"<<endl;
                continue;
            }
            if(s[i]!='?'&&t[i]!='?')continue;
            if(s[i]=='?')anss[i]='0';
            if(t[i]=='?')anst[i]='0';
        }
        i = mark-3;
        //cout<<i<<"&"<<endl;
        for(;i>=0;i--)
        {
            if(s[i]!='?'&&t[i]!='?')continue;
            if(s[i]=='?')anss[i]=t[i];
            if(t[i]=='?')anst[i]=s[i];
        }
        if(sum>1)
            printf("Ambiguous %I64d\n",sum);
        else if(sum==0)
            printf("Impossible\n");
        else
        {
            for(i=0; i<len; i++)
                printf("%c",anss[i]);
            puts("");
            for(i=0;i<len;i++)
                printf("%c",anst[i]);
            puts("");
        }
    }
}
