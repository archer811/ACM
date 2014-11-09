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
char o[1700][20],o2[20];
int d[20][20];
const int inf = 0x3fffffff;
int sl,gl;
int len[1700],len2;
int f(int x)
{
    int i,j;
    sl = len[x];
    gl = len2;
    for(i=0;i<=sl;i++)
    {
        for(j=0;j<=gl;j++)
        {
            d[i][j]=inf;
        }
    }
    d[0][0]=0;
//    for(i=1;i<=sl;i++)
//        d[i][0]=i;
//    for(i=1;i<=gl;i++)
//        d[0][i]=i;
//    for(i=1;i<=sl;i++)
//        cout<<o[x][i];
//    cout<<endl;
//    for(i=1;i<=gl;i++)
//        cout<<o2[i];
//    cout<<endl;
//    cout<<endl;
    for(i=1; i<=sl; i++)
    {
        for(j=1; j<=gl; j++)
        {
            if(o[x][i]==o2[j])
            {
//                cout<<"@@@"<<endl;
                d[i][j]=min(d[i][j],d[i-1][j-1]);
            }
            //else
            {
                //d[i][j]=min(d[i][j],d[i-1][j-1]+1);
                d[i][j]=min(d[i][j],d[i-1][j]+1);
                d[i][j]=min(d[i][j],d[i][j-1]+1);
                //if(i-2>=0)
                 //   d[i][j]=min(d[i][j],d[i-2][j]+1);
            }

        }
    }
    return d[sl][gl];
}
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            scanf("%s",o[i]+1);
            len[i]=strlen(o[i]+1);
        }

        printf("Case #%d:\n",++cas);
        for(i=0; i<m; i++)
        {
            int y;
            scanf("%s%d",o2+1,&y);
            int sum=0;
            len2 = strlen(o2+1);

            for(j=1; j<=n; j++)
            {
                //if(abs(len[j]-len2)>y)continue;
                if(f(j)<=y)sum++;
//                cout<<o[j]+1<<" "<<o2+1<<" "<<f(j)<<endl;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
