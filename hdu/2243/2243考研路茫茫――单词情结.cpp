#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll unsigned __int64
const int nodenum = 30;
int ch[nodenum][26];
int sz;
int val[nodenum];
int fail[nodenum];
ll l;
int n;
char s[10];
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    val[0]=0;
    memset(fail,0,sizeof(fail));
}
void insert(char *s)
{
    int len = strlen(s);
    int i,j;
    int  u = 0;
    for(i=0; i<len; i++)
    {
        j = s[i]-'a';
        if(ch[u][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            ch[u][j]=sz++;
        }
        u = ch[u][j];
    }
    val[u]=1;
}
int Q[nodenum];
void AC()
{
    int *s = Q,*e = Q;
    int i,j;
    for(i=0; i<26; i++)
    {
        if(ch[0][i])
        {
            *e++ = ch[0][i];
            fail[ch[0][i]]=0;
        }
    }
    while(s!=e)
    {
        int u = *s++;
        for(i=0; i<26; i++)
        {
            if(ch[u][i])
            {
                fail[ch[u][i]]=ch[fail[u]][i];
                val[ch[u][i]] |= val[ch[fail[u]][i]];
                *e++ = ch[u][i];
            }
            else ch[u][i] = ch[fail[u]][i];
        }
    }
}
struct matrix
{
    ll m[30][30];
} my,ans,tmp1,tmp2,tmp3,tmp4;
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j,k;
    for(i=0; i<sz; i++)
    {
        for(j=0; j<sz; j++)
        {
            c.m[i][j]=0;
            for(k=0; k<sz; k++)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j];
            }
        }
    }
    //cout<<"Ok"<<endl;
    return c;
}
matrix add(matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<sz; i++)
    {
        for(int j=0; j<sz; j++)
        {
            c.m[i][j] = (a.m[i][j]+b.m[i][j]);
        }
    }
    return c;
}
matrix powmul(matrix a,ll m)
{
    matrix z;
    int i,j;
    for(i=0; i<sz; i++)
    {
        for(j=0; j<sz; j++)
        {
            z.m[i][j]=0;
            if(i==j)z.m[i][j]=1;
        }
    }
    while(m)
    {
       // cout<<m<<"*"<<endl;
        if(m%2)z = mul(z,a);
        a = mul(a,a);
        m /= 2;
    }
    return z;
}
void print(matrix a)
{
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
            cout<<a.m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
matrix getsum(ll m,matrix a)
{
    matrix z;
    if(m==1)return a;
    if(m%2)
    {
        tmp1 = getsum(m/2,a);
        tmp2 = powmul(a,(m+1)/2);
        tmp3 = add(mul(tmp2,tmp1),tmp2);
        tmp3 = add(tmp3,tmp1);
        return tmp3;
    }
    else
    {
        tmp1 = getsum(m/2,a);
        tmp2 = powmul(a,(m)/2);
        tmp3 = add(tmp1,mul(tmp1,tmp2));
        return tmp3;
    }
}
ll mypow(ll m)
{
    ll z = 1,a = (ll)26;
    while(m)
    {
        if(m%2) z = z*a;
        a = a*a;
        m /= 2;
    }
    return z;
}
ll getsum(ll m)
{
    if(m==1)return (ll)26;
    if(m%2)
    {
        ll tmp1 = getsum(m/2);
        ll tmp2 = mypow((m+1)/2);
        return tmp1+tmp1*tmp2+tmp2;
    }
    else
    {
        ll tmp1 = getsum(m/2);
        ll tmp2 = mypow(m/2);
        return tmp1+tmp1*tmp2;
    }
}
int main()
{
    int i,j;
    while(scanf("%d%I64u",&n,&l)!=EOF)
    {
        init();
        for(i=1; i<=n; i++)
        {
            scanf("%s",s);
            insert(s);
        }
        AC();
        for(i=0; i<sz; i++)
        {
            for(j=0; j<sz; j++)
            {
                my.m[i][j]=0;
            }
        }

        for(i=0; i<sz; i++)
        {
            for(j=0; j<26; j++)
            {
                if(val[ch[i][j]])continue;
                my.m[i][ch[i][j]]++;
            }
        }
//        tmp4 = powmul(my,3);
//        ll mysum =0;
//        for(i=0; i<sz; i++)
//        {
//            if(val[i])continue;
//            mysum += tmp4.m[0][i];
//        }
        //cout<<"##############"<<endl;
        //print(my);
        //cout<<"##############"<<endl;
        ans = getsum(l,my);
        ll sum=0;
//        for(i=0; i<sz; i++)
//        {
//            for(j=0; j<sz; j++)
//                cout<<ans.m[i][j]<<" ";
//            cout<<endl;
//        }
        for(i=0; i<sz; i++)
        {
            if(val[i])continue;
            //if(ch[0][i]==0)continue;
            sum += ans.m[0][i];
            //cout<<i<<"SS"<<sum<<endl;
        }
        ll sum2=0;
        sum2 = getsum(l);
        printf("%I64u\n",sum2-sum);
    }
}
