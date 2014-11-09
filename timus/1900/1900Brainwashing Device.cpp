#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 505;
int w[maxn][maxn],d[maxn][maxn],ok[maxn][maxn];
int pre[maxn][maxn];
vector<int>nn;
int main()
{
    int i,j,k,n,tmp;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int flag=0;
        memset(w,0,sizeof(w));
        memset(d,-1,sizeof(d));
        memset(ok,0,sizeof(ok));
        memset(pre,-1,sizeof(pre));
        //for(i=0;i<=n;i++)
            d[0][0]=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                scanf("%d",&tmp);
                if(tmp)flag=1;
                for(int g=i+1;g<=j;g++)
                    w[i][g]+=tmp;
                for(int g=i;g<j;g++)
                    ok[g][g+1]+=tmp;
            }
        }
        if(flag==0)
        {
            printf("0\n1");
            for(i=2;i<=k;i++)
            {
                printf(" %d",i);
            }
            printf("\n");continue;
        }
        for(i=2;i<=n;i++)
        {
            for(j=i-1;j>=1;j--)
            {
                for(int g=1;g<j;g++)
                {
                    w[j][i]+=w[g][i];
                }
            }
        }
//        for(i=1;i<n;i++)
//            cout<<ok[i][i+1]<<endl;
//        for(i=1;i<n;i++)
//        {
//            for(j=i+1;j<=n;j++)
//                cout<<i<<" "<<j<<" "<<w[i][j]<<endl;
//        }
        for(i=1;i<n;i++)
        {
            d[i][0]=0;
            for(j=1;j<=i&&j<=k;j++)
            {
                for(int g=0;g<i;g++)
                {
                    if(d[i][j]<d[g][j-1]+ok[i][i+1]-w[g][i+1])
                    {
                        d[i][j]=d[g][j-1]+ok[i][i+1]-w[g][i+1];
                        pre[i][j]=g;
//                      cout<<i<<" "<<j<<" "<<
//                            g<<"()"<<ok[i][i+1]<<" "<<
//                            d[i][j]<<"&"<<pre[i][j]<<endl;
                    }

                   // cout<<i<<"**"<<j<<" "<<g<<" "<<w[g+1][i]<<" "<<d[i][j]<<endl;

                }
                //cout<<i<<"*"<<j<<" "<<d[i][j]<<endl;
            }
        }

        nn.clear();
        int a=n-1,b=k;
        for(i=1;i<n;i++)
        {
            if(d[i][k]>d[a][k])a=i;
        }
        cout<<d[a][k]<<endl;
        nn.push_back(a);
//        for(i=1;i<n;i++)
//        {
//            for(j=i+1;j<=n;j++)
//                cout<<i<<" "<<j<<" "<<pre[i][j]<<endl;
//        }
        while(pre[a][b]!=-1&&pre[a][b]!=0)
        {
            tmp = pre[a][b];
            a=tmp;b--;
            nn.push_back(tmp);
        }
        sort(nn.begin(),nn.end());
        for(i=0;i<nn.size();i++)
        {
            if(i==0)printf("%d",nn[i]);
            else printf(" %d",nn[i]);
        }
        printf("\n");
    }
}
/*
5 3
5 0 6 5
5 3 7
5 3
10

4 2
5 0 6
5 3
5

4 3
5 0 6
5 3
5

3 2
0 0
0
*/
