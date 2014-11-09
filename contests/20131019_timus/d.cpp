#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int c[105][105];
const int inf = 0x3fffffff;
int a[105];
int prim(int n,int sta)//n��ʾ��n�����㣬sta���sta����������������С������
{
    int mark[105],dis[105];
    int i,sum = 0,j;     //sum���ܵ���С��������Ȩֵ
    for (i = 1; i <= n; i ++) //��ʼ��dis[i] ��Ӷ���sta����i��Ȩֵ
    {
        dis[i] = c[sta][i];
        mark[i] = 0;
    }
    mark[sta] = 1;           //sta ������������С��������
    for (i = 1; i < n; i ++) //ѭ��n-1�Σ�ÿ���ҳ�һ����СȨֵ�ı� n�����ͼ
    {
        //ֻ��n-1����
        int min = inf,flag;       //inf �������
        for (j = 1; j <= n; j ++) //�ҳ���ǰδ����С�������б�Ȩ��С�Ķ���
            if (!mark[j] && dis[j] < min)
                min = dis[j],flag = j;
        mark[flag] = 1;         //�Ѹö��������С��������
        sum += dis[flag];       //sum�������Ȩֵ
        for (j = 1; j <= n; j ++) //��falgΪ�����µ���������СȨֵ
            if (dis[j] > c[flag][j])
                dis[j] = c[flag][j];
    }
    return sum;       //���ر�Ȩ�ܺ�
}

int main()
{
    int i,j,k,n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1; i<=n+1; i++)
        {
            c[i][i]=0;
            for(j=i+1; j<=n+1; j++)
            {
                c[i][j]=c[j][i]=inf;
            }
        }
        for(i=1; i<=k; i++)
        {
            scanf("%d",&a[i]);
            c[a[i]][n+1]=c[n+1][a[i]]=0;
        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%d",&c[i][j]);
        }
        n ++;
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                cout<<c[i][j]<<" ";
//            cout<<endl;
//        }
        int ans = prim(n,n);
        printf("%d\n",ans);
    }
}
