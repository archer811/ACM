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
int s[17];
int a[5][5];
int main()
{
    int i,j,t;
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int d;
    int cas=0;
    while(t--)
    {
        memset(s,0,sizeof(s));
        cin>>d;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                cin>>a[i][j];
        }
        for(i=0;i<4;i++)
            s[a[d-1][i]]++;
        cin>>d;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                cin>>a[i][j];
        }
        for(i=0;i<4;i++)
            s[a[d-1][i]]++;
        int ss=-1,sum=0;
        printf("Case #%d: ",++cas);
        for(i=0;i<=16;i++)
        {
            if(s[i]==2){ss=i;sum++;}
        }
        if(sum>=2)puts("Bad magician!");
        else if(sum==0)puts("Volunteer cheated!");
        else cout<<ss<<endl;
    }
}
