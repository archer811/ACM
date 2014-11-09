#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define V 3000000
const int N =9;
const int inf = 0x3fffffff;
int U[V],D[V],L[V],R[V],C[V],H[N],S[V],mark[V];
int size,n,m,ok[V],flag;
const int mm=N*N*N*(N*N*4)+N;
const int mn=N*N*N+N;
void prepare(int r,int c)
{
    for(int i=0; i<=c; ++i)
    {
        S[i]=0;
        U[i]=D[i]=i;
        L[i+1]=i;
        R[i]=i+1;
    }
    R[size=c]=0;
    while(r)H[r--]=-1;
}
void link(int r,int c)
{
    S[c]++;C[size]=c;
    U[size]=U[c];
    D[U[c]]=size;
    D[size]=c;
    U[c]=size;
    if(H[r]==-1)H[r]=L[size]=R[size]=size;
    else
    {
        L[size]=L[H[r]];
        R[L[H[r]]]=size;
        R[size]=H[r];
        L[H[r]]=size;
    }
    mark[size]=r;
    size++;
}
void remove(int c)
{
    int i,j;
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    for(i=D[c];i!=c;i=D[i])
    {
        for(j=R[i];j!=i;j=R[j])
        {
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            S[C[j]]--;
        }
    }
}
void resume(int c)
{
    int i,j;
    for(i=U[c];i!=c;i=U[i])
    {
        for(j=L[i];j!=i;j=L[j])
        {
            U[D[j]]=j;
            D[U[j]]=j;
            S[C[j]]++;
        }
    }
    L[R[c]]=c;
    R[L[c]]=c;
}
int ans[82][82];
int dance(int k)
{
    int i,j,Min,c;
    if(!R[0])
    {
        flag=1;
        int x,y,num,t;
        for(i=0;i<k;i++)
        {
            t = mark[ok[i]];
            if(t%81==0)x=t/81;
            else x=t/81+1;
            if((t-(x-1)*81)%9==0)
                y = (t-(x-1)*81)/9;
            else  y = (t-(x-1)*81)/9+1;
            num = (t-(x-1)*81-(y-1)*9);
            ans[x][y]=num;
            //cout<<t<<" "<<x<<" "<<y<<" "<<num<<endl;
        }

        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                printf("%d",ans[i][j]);
            }
        }puts("");
        return 1;
    }
    for(Min=inf,i=R[0];i;i=R[i])
    {
       if(S[i]<Min)Min=S[i],c=i;
    }
    remove(c);
    for(i=D[c];i!=c;i=D[i])
    {
        ok[k]=i;
        for(j=R[i];j!=i;j=R[j])
        {
            remove(C[j]);
        }
        if(dance(k+1))return 1;
        for(j=L[i];j!=i;j=L[j])
        {
            resume(L[j]);
        }
    }
    resume(c);
    return 0;
}
char s[100];
int vis[10];
int fx[][2]={0,0,
            1,3,1,3,1,3,
            4,6,4,6,4,6,
            7,9,7,9,7,9};
int fy[][2]={0,0,
            1,3,4,6,7,9,
            1,3,4,6,7,9,
            1,3,4,6,7,9};
int tk[9*9*9+10][4*81+10];
void place(int &r,int &c1,int &c2,int &c3,int &c4,int i,int j,int k)
{
    r=(i*N+j)*N+k,c1=i*N+j+1,c2=N*N+i*N+k,c3=N*N*2+j*N+k,c4=N*N*3+((i/3)*3+(j/3))*N+k;
}
int v[4*9*9+10];
int main()
{
    int i,j,k,r,c1,c2,c3,c4;
    while(scanf("%s",s),s[0]!='e')
    {
        prepare(mn,N*N*4);
        for(i=1; i<=mn; ++i)v[i]=0;
        for(k=0,i=0; i<9; ++i)
            for(j=0; j<9; ++j,++k)
                if(s[k]>'0'&&s[k]<='9')
                {
                    place(r,c1,c2,c3,c4,i,j,s[k]-'0');
                    if(i==1&&j==3)cout<<r<<" "<<s[k]-'0'<<"**********"<<endl;
                    link(r,c1),link(r,c2),link(r,c3),link(r,c4);
                    v[c2]=v[c3]=v[c4]=1;
                }
            int ok =0;
        for(i=0; i<9&&ok<=200; ++i)
            for(j=0; j<9&&ok<=200; ++j)
                for(k=1; k<=9&&ok<=200; ++k)
                {
                    place(r,c1,c2,c3,c4,i,j,k);
                    if(r==109)cout<<i<<" "<<j<<" "<<k<<"fdasf"<<s[i*9+j]<<endl;
                    ok++;
                    if(ok==200)break;
                    if(v[c2]||v[c3]||v[c4])continue;
                    if(ok>=100&&ok<=200)
                    cout<<r<<" "<<c1<<" "<<c2<<" "<<c3<<" "
                    <<c4<<endl;

                    link(r,c1),link(r,c2),link(r,c3),link(r,c4);
                }
        dance(0);
    }
    return 0;
}
