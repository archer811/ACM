#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int a[1001],b[1001],f[1001][1001];
int g[1001][1001];
int score(int i, int j)
{
    if(a[i]>b[j])
        return 1;
    else if(a[i]<b[j])
        return -1;
    else return 0;
}

void init(int n)
{
    for(int p=0; p<=n; p++)
        for(int q=0; q<=n; q++)
            f[p][q]=0;
    for(int i=1; i<=n; i++)
    {
        f[i][0]=f[i-1][0]+g[i][i];
    }
    for(int j=n,g=1; j>=1; j--,g++)
    {
        if(a[j]>b[g])
            f[g][g]=f[g-1][g-1]+1;
        else if(a[j]<b[g])
            f[g][g]=f[g-1][g-1]-1;
        else
            f[g][g]=f[g-1][g-1];
       // cout<<g<<" "<<f[g][g]<<endl;
    }
}

int maxnum(int i,int j)
{
    if(i>j)
        return i;
    else
        return j;
}

bool compare(const int& a, const int& b)
{
    return a>b;
}

int main()
{
    int n,max;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int x=1; x<=n; x++)
        {
            scanf("%d",&b[x]);
        }
        sort(a+1,a+n+1,compare);
        sort(b+1,b+n+1,compare);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=score(i,j);
            }
        }
        init(n);
        for(int j=2; j<=n; j++)
        {
            for(int k=1; k<j; k++)
            {
                f[j][k]=maxnum((f[j-1][k-1]+score(k,j)),(f[j-1][k]+score(n+1-(j-k),j)));
            }
        }
        max = f[n][0];
        for(int g=1; g<=n; g++)
        {
            if(f[n][g]>max)
                max=f[n][g];
        }
        printf("%d\n",max*200);
    }
}

