#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 50005;
int a[maxn],c[12][maxn];
int n;
int pre[12][12];
int lowbit(int x)
{
    return x&(-x);
}
void add(int index,int x,int num)
{
    while(x <= maxn)
    {
        c[index][x] += num;
        x += lowbit(x);
    }
}
int getsum(int index,int x)//Çósum(x)
{
    int result = 0;
    while(x > 0)
    {
        result += c[index][x];
        x -= lowbit(x);
    }
    return result;
}
int main()
{
    int i,j,k,op,d,q,A,B,C;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=10;i++)
        {
            pre[i][0]=0;
            for(j=1;j<=i;j++)
            {
                pre[i][j]=pre[i][j-1]+(n-j)/i+1;
                //cout<<pre[i][j]<< " ";
            }
            //cout<<endl;
        }

        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d%d%d",&A,&B,&k,&C);
                B = (B-A)/k*k+A;
                //cout<<A<<"*************"<<B<<endl;
                int tmp = A%k;
                if(tmp==0)tmp=k;
                int _a = pre[k][tmp-1]+A/k+1;
                if(A%k==0&&k!=1)_a--;

                tmp = B%k;
                if(tmp==0)tmp=k;
                int _b = pre[k][tmp-1]+B/k+1;
                if(B%k==0&&k!=1)_b--;
                if(k==1)_a--,_b--;
                //cout<<tmp<<" "<<_a<<"________________"<<_b<<endl;
                add(k,_a,C);
                //cout<<c[k][_a]<<"()()()()()()()()("<<endl;
                add(k,_b+1,-C);
            }
            else
            {
                scanf("%d",&d);
                int sum=0;
                for(i=1; i<=10; i++)
                {
                    int tmp = d%i;
                    if(tmp==0)tmp=i;
                    int _b = pre[i][tmp-1]+d/i+1;
                    if(d%i==0&&i!=1)_b--;
                    if(i==1)_b--;
                    sum += getsum(i,_b);
                    //cout<<i<<"()(((((((((((((("<<sum<<endl;
                }
                printf("%d\n",sum+a[d]);
            }
        }
    }
}
