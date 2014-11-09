#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100010],b[100010];
int n,t,T,i,j,k,p,q,cnt,ans,mod=1000000007,bit[100010],temp;
int main()
{

    bit[0]=1;
    for(i=1;i<=100000;i++) bit[i]=bit[i-1]*2%mod;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%s",a);
        scanf("%s",b);
        n=strlen(a);
        ans=0;
        printf("Case #%d:\n",t);
        for(cnt=i=0;i<n;i++)
            if(a[i]!='?'&&b[i]!='?'&&a[i]!=b[i])//找出矛盾个数
                cnt++,p=i;
        if(cnt>1)//矛盾>1无解
        {
            puts("Impossible");
            continue;
        }
        else if(cnt==1)//矛盾=1
        {
            for(i=0;i<n;i++)//不同处已确定，只有一个问号的可以直接赋值
                if(a[i]!='?'&&b[i]=='?') b[i]=a[i];
                else if(a[i]=='?'&&b[i]!='?') a[i]=b[i];
            if(p+1<n&&(a[p+1]=='0'||b[p+1]=='0'))
            {
                puts("Impossible");
                continue;
            }
            if(p+2<n)
            {
                for(i=p+2;i<n;i++)
                    if(a[i]=='1'||b[i]=='1') break;
                if(i<n)
                {
                    puts("Impossible");
                    continue;
                }
            }
            if(p+1<n) a[p+1]=b[p+1]='1';
            for(i=p+2;i<n;i++) a[i]=b[i]='0';
            cnt=0;
            for(i=0;i<p;i++)//双问号个数
                if(a[i]=='?') cnt++,q=i;
            if(cnt>1) ans=bit[cnt-1];
            else if(cnt==1)
            {
                ans=1;
                for(i=1,j=a[0]-'0';i<q;i++) j^=a[i]-'0';
                for(i=p-1,k=a[p]-'0';k>q;i--) k^=a[i]-'0';
                if(!q) a[q]=b[q]='0'+k; else a[q]=b[q]='0'+(j^k);
            }
            else{
                for(i=j=0;i<p;i++) j^=a[i]-'0';
                if(j==a[p]-'0') ans=1;
                else{
                    puts("Impossible");
                    continue;
                }
            }
        }
        else{//矛盾=0
            cnt=0;
            for(i=0;i<n;i++)//双问号个数
                if(a[i]=='?'&&b[i]=='?') cnt++;
            for(temp=q=0;q<n;q++)//双问号第一个位置q，从最前端开始推出temp
                if(a[q]=='?'&&b[q]=='?') break;
                else if(a[q]!='?') temp^=a[q]-'0'; else temp^=b[q]-'0';
            for(i=n-1;i>=0;i--)
            {
                if(a[i]=='?'&&b[i]=='?') cnt--;
                if(i<q)
                    if(a[i]!='?') temp^=a[i]-'0'; else temp^=b[i]-'0';
                if(i+1<n&&(a[i+1]=='0'||b[i+1]=='0')) continue;
                if(a[i]=='?'||b[i]=='?')
                    if(a[i]=='?'&&b[i]=='?')
                    {
                        ans=(ans+bit[cnt])%mod;
                        p=i;
                    }
                    else if(cnt>0)
                    {
                        ans=(ans+bit[cnt-1])%mod;
                        p=i;
                    }
                    else{
                        if(a[i]!='?'&&temp==a[i]-'0'||b[i]!='?'&&1-temp==b[i]-'0') ans++,p=i;
                    }
                if(i+1<n&&(a[i+1]=='1'||b[i+1]=='1')) break;
            }
            if(ans==1)
            {
                if(p+1<n) a[p+1]=b[p+1]='1';
                for(i=p+2;i<n;i++) a[i]=b[i]='0';
                if(a[p]=='?'&&b[p]!='?') a[p]='1'+'0'-b[p];
                if(a[p]!='?'&&b[p]=='?') b[p]='1'+'0'-a[p];
                for(i=0;i<p;i++)//不同处已确定，只有一个问号的可以直接赋值
                    if(a[i]!='?'&&b[i]=='?') b[i]=a[i];
                    else if(a[i]=='?'&&b[i]!='?') a[i]=b[i];
                if(a[p]=='?'&&b[p]=='?')
                {
                    for(j=k=0;j<p;j++) k^=a[j]-'0';
                    a[p]='0'+k,b[p]='1'+'0'-a[p];
                }
                else{
                    for(q=0;q<p;q++)
                        if(a[q]=='?') break;
                    if(q<p)
                    {
                        for(i=j=0;i<q;i++) j^=a[i]-'0';
                        for(i=p,k=0;i>q;i--) k^=a[i]-'0';
                        a[q]=b[q]=(j^k)+'0';
                    }
                }
            }
        }
        ans%=mod;
        if(ans>1) printf("Ambiguous %d\n",ans);
        else if(!ans) puts("Impossible");
        else puts(a),puts(b);
    }
}
