#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
struct matrix
{
    double a[3][3];
    void init(int x)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                a[i][j]=(x&&(i==j)?1:0);
        }
    }
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    c.init(0);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        double x,y,p;
        int n;
        scanf("%d",&n);
        matrix ans;
        ans.init(1);
        while(n--)
        {
            scanf("%lf%lf%lf",&x,&y,&p);
            matrix tmp;
            tmp.init(1);
            tmp.a[2][0]=-x;
            tmp.a[2][1]=-y;
            ans = mul(ans,tmp);

            tmp.init(1);
            tmp.a[0][0]=cos(p);
            tmp.a[0][1]=sin(p);
            tmp.a
        }
    }
    return 0;
}
