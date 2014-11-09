#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 1015

int N;
int worm[M];    //����Ƿ���worm
int Tree[M][M]; //���ӱ�
int Success[M]; //��ʾ��iΪ���������ϳɹ��ҵ�House������������,��iΪҶ��ʱ,Success[i]=0
int Failure[M]; //��ʾ��iΪ�����������Ҳ���House�Ĳ���,��worm[i]=1����iΪҶ��ʱ,��ôFailure[i]=0
int Leaves[M];  //iΪ����������Ҷ�ӽڵ����Ŀ,��ΪҶ��ʱ,Leaves[i]=0

bool cmp(const int &u, const int &v)
{
       return (Failure[u] + 2) * Leaves[v] < (Failure[v] + 2) * Leaves[u];
}

void solve(int now)
{
       int i, k;

       if (Tree[now][0] == 0)
       {
              Leaves[now] = 1;
              Failure[now] = 0;
              Success[now] = 0;
              return;
       }

       for (i = 1; i <= Tree[now][0]; i++)
       {
              solve(Tree[now][i]);
       }
       for (i = 1; i <= Tree[now][0]; i++)
       {
              Leaves[now] += Leaves[Tree[now][i]];
              if (worm[now] == 0)
              {
                     Failure[now] += (Failure[Tree[now][i]] + 2);
              }
       }

       int temp[M];
       for (i = 0; i < Tree[now][0]; i++)
       {
              temp[i] = Tree[now][i + 1];
       }

       sort(temp, temp + Tree[now][0], cmp);
       for (i = 0, k = 0; i <Tree[now][0]; i++)
       {
              Success[now] += (k + 1) * Leaves[temp[i]] + Success[temp[i]];
              k += Failure[temp[i]] + 2;
       }
}

int main()
{
       int i, a;
       char c;
       while (scanf("%d", &N) && N != 0)
       {
              memset(Tree, 0, sizeof(Tree));
              for (i = 1; i <= N; i++)
              {
                     worm[i] = 0;
                     scanf("%d %c", &a, &c);
                     if (a != -1)
                     {
                            Tree[a][++Tree[a][0]] = i;
                     }
                     if (c == 'Y')
                     {
                            worm[i] = 1;
                     }
                     Leaves[i] = 0; Failure[i] = 0; Success[i] = 0;
              }
              //����dp+����̰��
              solve(1);
              double ans = ((double)Success[1]) / ((double)Leaves[1]);
              printf("%.4lf/n", ans);
       }

       return 0;
}
