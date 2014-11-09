
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[100005][22];
char s[6];
int main()
{
    int i,j,T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=0;j<5;j++)
            {
                int d;
                if(s[j]>='0'&&s[j]<='9')
                    d = s[j]-'0';
                else d = s[j]-'A'+10;
                for(int k=j*4+3;k>=j*4;k--)
                    a[i][k]=d%2,d/=2;
            }
        }
        int L = 0,R = 20;
        while(L<=R)
        {

        }
    }
}
