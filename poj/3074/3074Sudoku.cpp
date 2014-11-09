#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N=9;
const int mm=N*N*N*(N*N*4)+N;
const int mn=N*N*N+N;
int U[mm],D[mm],L[mm],R[mm],C[mm],mark[mm];
int H[mn],S[mn],Q[mn];
char map[mn];
int size;
void prepare(int r,int c)
{
    for(int i=0; i<=c; ++i)
    {
        S[i]=0;
        U[i]=D[i]=i;
        L[i+1]=i;
        R[i]=i+1;
    }
    size = c + 1;
    R[c]=0;
    memset(H,-1,sizeof(H));
}
void remove(int c)
{
    L[R[c]]=L[c],R[L[c]]=R[c];
    for(int i=D[c]; i!=c; i=D[i])
        for(int j=R[i]; j!=i; j=R[j])
            U[D[j]]=U[j],D[U[j]]=D[j],--S[C[j]];
}
void resume(int c)
{
    for(int i=U[c]; i!=c; i=U[i])
        for(int j=L[i]; j!=i; j=L[j])
            ++S[C[U[D[j]]=D[U[j]]=j]];
    L[R[c]]=R[L[c]]=c;
}
bool dance(int k)
{
    if(!R[0])
    {
        for(int i=0; i<k; ++i)map[(mark[Q[i]]-1)/9+1]=(mark[Q[i]]-1)%9+1;
        for(int i=1; i<=N*N; ++i)printf("%d",map[i]);
        puts("");
        return 1;
    }
    int i,j,c,tmp=mm;
    for(i=R[0]; i; i=R[i])
        if(S[i]<tmp)tmp=S[c=i];
    remove(c);
    for(i=D[c]; i!=c; i=D[i])
    {
        Q[k]=i;
        for(j=R[i]; j!=i; j=R[j])remove(C[j]);
        if(dance(k+1))return 1;
        for(j=L[i]; j!=i; j=L[j])resume(C[j]);
    }
    resume(c);
    return 0;
}
void Link(int r,int c)
{
    S[c]++;C[size]=c;
    mark[size]=r;
    D[size]=D[c];
    U[D[c]]=size;
    U[size]=c;
    D[c]=size;
    if(H[r]<0)H[r]=L[size]=R[size]=size;
    else
    {
        R[size]=R[H[r]];
        L[R[H[r]]]=size;
        L[size]=H[r];
        R[H[r]]=size;
    }
    size++;
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
int ans[10][10];
int main()
{
    int i,j,n,m,x,y,d,num,k;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='e')break;
        m = 4*9*9;
        n = 9*9*9;
        memset(ans,0,sizeof(ans));
        for(i=0;i<=m;i++)
        {
            S[i]=0;D[i]=U[i]=i;
            L[i+1]=i;R[i]=i+1;
        }
        R[m]=0;size=m+1;
        memset(H,-1,sizeof(H));
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
        for(i=0;i<81;i++)
        {
            x = i/9+1;
            y = i%9+1;
            num = s[i]-'0';
            if(s[i]!='.')
            {
                ans[x][y]=num;
                d = (x-1)/3*3+(y-1)/3+1;

                    Link((x-1)*81+(y-1)*9+num,(x-1)*9+y);
                    Link((x-1)*81+(y-1)*9+num,81+(x-1)*9+num);
                    Link((x-1)*81+(y-1)*9+num,162+(y-1)*9+num);
                    Link((x-1)*81+(y-1)*9+num,243+(d-1)*9+num);

            }
        }
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                if(ans[i][j]==0)
                {
                    d = (i-1)/3*3+(j-1)/3+1;
                    for(k=1;k<=9;k++)
                        vis[k]=0;
                    for(int g=1;g<=9;g++)
                    {
                        vis[ans[i][g]]=1;
                        vis[ans[g][j]]=1;
                    }
                    for(int g=fx[d][0];g<=fx[d][1];g++)
                    {
                        for(k=fy[d][0];k<=fy[d][1];k++)
                        {
                            vis[ans[g][k]]=1;
                        }
                    }
                    for(k=1;k<=9;k++)
                    {
                        if(vis[k]==0)
                        {
                            Link((i-1)*81+(j-1)*9+k,(i-1)*9+j);
                            Link((i-1)*81+(j-1)*9+k,81+(i-1)*9+k);
                            Link((i-1)*81+(j-1)*9+k,162+(j-1)*9+k);
                            Link((i-1)*81+(j-1)*9+k,243+(d-1)*9+k);
                        }
                    }
                }
            }
        }

        dance(0);
    }
}
