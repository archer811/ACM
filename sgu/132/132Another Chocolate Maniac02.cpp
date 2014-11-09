#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int mn = 80,mm = 10,ms = 512,INF = 0x7FFFFFFF/2;
int f[2][ms][ms],n,m,i,j,k,t;
int a[mn],mi[10]= {1};
char op[10];
int tmpJ,tmpK;
void dfs(int p,int j,int k,int s,int cnt)
{
    //��֤��ǰ�е�ǰ���в��ܷ���2*1���ɿ���
    if (p > 0 && ((k & mi[p-1]) == 0) && ((j & mi[p-1]) == 0)) return ;
    //��֤��ǰ����һ�в��ܷ���1*2���ɿ���
    if (p > 1 && ((k & mi[p-1]) == 0) && ((k & mi[p-2]) == 0)) return;
    //ת��
    if (p == m)
    {
        f[i & 1][k][s] = min(f[i & 1][k][s],f[1-(i&1)][tmpJ][tmpK]+cnt);
        return;
    }
    //ʲô�����ŵ�״̬
    dfs(p+1,j,k,s,cnt);
    //�ڵ�ǰ�е���һ�з���һ��1*2�Ĺ���
    if (p < (m-1) && ((k & mi[p]) == 0) && ((k & mi[p+1]) ==0))
        dfs(p+1,j,k | mi[p] | mi[p+1],s,cnt+1);
    //�ڵ�ǰ�е���һ�з���һ��2*1�Ĺ���,��Ӱ�쵽��ǰ��
    if (((k & mi[p]) == 0) && ((s & mi[p])==0))
        dfs(p+1,j,k | mi[p],s | mi[p],cnt+1);
}
int main()
{
    scanf("%d %d",&n,&m);
    t = (1 << m)-1;
    for (i=1; i<=m; ++i) mi[i] = mi[i-1] *2; //����2���ݴ�,�������ټ�����
    for (i = 1; i<=n; ++i)
    {
        scanf("%s",op+1);
        for (j=1; j<=m; ++j)
            a[i] = a[i]*2+(op[j]=='*');
    }
    a[0]=a[n+1]=t;
    for (j = 0; j<=t; ++j)
        for (k=0; k<=t; ++k) f[0][j][k] = INF;
    f[0][t][a[1]] = 0;
    /*
     *�������
     */
    for (i = 1; i<=n; ++i)
    {
        //��ʼ��
        for (j=0; j<=t; ++j)
            for (k=0; k<=t; ++k)
                f[i & 1][j][k] = INF;
        //ö�ٵ�ǰ��ǰ���е�״̬
        for (j=0; j<=t; ++j)
            for (k=0; k<=t; ++k)
                if (f[1 - (i & 1)][j][k] != INF)
                {
                    tmpJ = j,tmpK = k,dfs(0,j,k,a[i+1],0);
                }
    }
    int ans = INF;
    for (i = 0; i<=t; ++i)
        ans = min (ans,f[n & 1][i][t]);
    printf("%d\n",ans);
    return 0;
}
