#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
char s[11];
#define ll __int64
const int nodenum = 110;
int sz;
int ch[nodenum][5];
int val[nodenum];
int fail[nodenum];
int idx(char s)
{
    if(s=='A')return 0;
    if(s=='T')return 1;
    if(s=='C')return 2;
    if(s=='G')return 3;
}
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    val[0]=0;
    memset(fail,0,sizeof(fail));
}
const ll mod = 100000;
void insert(char *s)
{
    int len = strlen(s);
    int i,j;
    int u = 0;
    for(i=0;i<len;i++)
    {
        j = idx(s[i]);
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
queue<int>q;
void AC()
{
    while(!q.empty())q.pop();
    int i,j;
    for(i=0;i<4;i++)
    {
        if(ch[0][i])
        {
            fail[ch[0][i]]=0;
            q.push(ch[0][i]);
        }
    }
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(i=0;i<4;i++)
        {
            if(ch[u][i])
            {
                fail[ch[u][i]]=ch[fail[u]][i];
                val[ch[u][i]]|=val[ch[fail[u]][i]];
                q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
    }
}
struct matrix
{
    ll m[110][110];
}mymatrix,ans;
matrix mul(matrix a,matrix b)
{
    int i,j,k;
    matrix c;
    for(i=0;i<sz;i++)
    {
        for(j=0;j<sz;j++)
        {
            c.m[i][j]=0;
            for(k=0;k<sz;k++)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
            }
            c.m[i][j]%=mod;
        }
    }
    return c;
}
matrix powmul(matrix a,ll b)
{
    matrix z;
    int i,j;
    for(i=0;i<sz;i++)
    {
        for(j=0;j<sz;j++)
        {
            z.m[i][j]=0;
            if(i==j)z.m[i][j]=1;
        }
    }
    while(b)
    {
        if(b%2)z = mul(z,a);
        a = mul(a,a);
        b = b/2;
    }
    return z;
}
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    {
        init();
        for(i=1;i<=m;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        AC();
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz;j++)
                mymatrix.m[i][j]=0;
        }


        for(i=0;i<sz;i++)
        {
            for(j=0;j<4;j++)
            {
                if(val[ch[i][j]])continue;
                mymatrix.m[i][ch[i][j]]++;
            }
        }


//        for(i=0;i<sz;i++)
//        {
//            for(j=0;j<sz;j++)
//                cout<<mymatrix.m[i][j]<<" ";
//            cout<<endl;
//        }
        ans = powmul(mymatrix,n);
        ll sum =0;
       //for(i=0;i<sz;i++)
        {
            for(j=0;j<sz;j++)
            {
                if(val[j])continue;
                sum += ans.m[0][j];
                sum %= mod;
            }
        }
        printf("%I64d\n",sum);
    }
}
