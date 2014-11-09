#include <iostream>
#include <cstdio>
#include<cstring>
#include<queue>

#include<algorithm>
using namespace std;
int ch[105][4],fail[105],flag[105];
char s[15];
int sz;
const int mod = 100000;
#define mem(a,b) memset(a,b,sizeof(a))
void init()
{
    mem(ch[0],0);
    sz=1;
    fail[0]=0;
    flag[0]=0;
}
struct matrix
{
    __int64 v[105][105];
    matrix()
    {
        mem(v,0);
    }
};
matrix unin;
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j,k;
    for(i=0;i<sz;i++)
    {
        for(j=0;j<sz;j++)
        {
            for(k=0;k<sz;k++)
            {
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%mod;
            }
        }
    }
    return c;
}
matrix power(matrix a,int n)
{
    matrix b= unin;
    while(n)
    {
        if(n&1)
          b=mul(b,a);
        n>>=1;
        a=mul(a,a);
    }
    return b;
}
int num(char ch) {
	switch (ch) {
		case 'A' : return 0;
		case 'C' : return 1;
		case 'T' : return 2;
		case 'G' : return 3;
	}
	return 0;
}
void ins(char *s)
{
    int p=0;
    for(;*s;s++)
    {
        int index = num(*s);
        if(ch[p][index]==0)
        {
            flag[sz]=0;
            fail[sz]=0;
            for(int j=0;j<4;j++)
              ch[sz][j]=0;
            ch[p][index]=sz++;
        }
        p=ch[p][index];
    }
    flag[p]=1;
}
queue<int>q;
void ac()
{
    int i,j;
    while(!q.empty())q.pop();
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            if(ch[u][i])
            {
                if(u==0)fail[ch[u][i]]=0;
                else fail[ch[u][i]]=ch[fail[u]][i];
                if(flag[ch[fail[u]][i]])
                  flag[ch[u][i]]=1;
                q.push(ch[u][i]);
            }
            else
            {
                if(u==0)
                    ch[u][i]=0;
                else ch[u][i]=ch[fail[u]][i];
            }
        }
    }
} matrix A;
void creat()
{

    int i,j;
    for(i=0;i<sz;i++)
    {
        if(flag[i]==0)
        {
            for(j=0;j<4;j++)
            {
                if(flag[ch[i][j]]==0)
                {
                    A.v[i][ch[i][j]]++;
                }
            }
        }
    }
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&m,&n);
    init();
    while(m--)
    {
        scanf("%s",s);
        ins(s);
    }
    ac();
    for(i=0;i<sz;i++)
    {
        unin.v[i][i]=1;
    }
    creat();


    A = power(A,n);
//    for(i=0;i<sz;i++)
//    {
//        for(j=0;j<sz;j++)
//        cout<<A.v[i][j]<<" ";
//        cout<<endl;
//    }
    __int64 ans=0;
    for(i=0;i<sz;i++)
    {
        if(flag[i]==0)
          ans=(ans+A.v[0][i])%mod;
    }
    cout<<ans<<endl;
}
