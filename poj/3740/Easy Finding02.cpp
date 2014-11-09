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
const int N = 9;
const int mm = N*N*N*(N*N*4)+N;
const int nn = N*N*N+N;
int U[mm],D[mm],L[mm],R[mm],C[mm],X[mm];
int H[nn],S[nn],Q[nn];
bool v[nn];
char map[nn];
int size;
void prepare(int r,int c)
{
    for(int i=0;i<=c;i++)
    {
        S[i]=0;
        U[i]=D[i]=i;
        L[i+1]=i;
        R[i]=i+1;
    }
    size = c+1;
    R[c]=0;
    memset(H,-1,sizeof(H));
}
void remove(int c)
{
    L[R[c]]=L[c];R[L[c]]=R[c];
    for(int i=D[c];i!=c;i=D[i])
        for(int j=R[i];j!=i;j=R[j])
            U[D[j]]=U[j],D[U[j]]=D[j],--S[C[j]];
}
void resume(int c)
{
    for(int i=U[c];i!=c;i=U[i])
        for(int j=L[i];j!=i;j=L[j])
            ++S[C[j]]
}
