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
char s[105];
int a[36][36];
int d[105][105][26];
char s2[20],t2[20];
const int inf = 0x3fffffff;
int mark[26][26];
int main()
{
    int i,j,k;
    while(scanf("%s%d",s+1,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(mark,0,sizeof(mark));
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int x,y,c;
            scanf("%s%s%d",s2,t2,&c);
            x=s2[0]-'a';
            y=t2[0]-'a';
            a[x][y]=c;
            mark[x][y]=1;
        }
        int len=strlen(s+1);
        for(i=0;i<105;i++)
        {
            for(j=0;j<105;j++)
            {
                for(int g=0;g<26;g++)
                {
                    d[i][j][g]=-inf;
                }
            }
        }
        for(i=0;i<26;i++)
        {
            if(i!=s[1]-'a')d[1][1][i]=0;
            else
            {
               d[1][0][i]=0;
               //d[1][1][i]=0;
            }
        }
        for(i=2;i<=len;i++)
        {
            for(int g=0;g<=k;g++)
            {
                for(j=0;j<26;j++)
                {
                    for(int t=0;t<26;t++)
                    {

                        //if(t==0&&j==1)cout<<"*"<<endl;
                        int tmp = 0;
                        if(mark[t][j])tmp=a[t][j];
                        if(g>=1&&j!=s[i]-'a'&&d[i-1][g-1][t]!=-inf)
                        {
                            d[i][g][j]=max(d[i][g][j],d[i-1][g-1][t]+tmp);
                        }


                        if(j==s[i]-'a'&&d[i-1][g][t]!=-inf)
                        {
                            d[i][g][j]=max(d[i][g][j],d[i-1][g][t]+tmp);
                        }
                        //if(d[i][g][j]>0)
                        //    cout<<i<<" "<<g<<" "<<d[i-1][g][t]<<"*"<<a[t][j]<<endl;
                    }
                }
            }
        }
        int M=0,flag=0;
        for(i=0;i<=k;i++)
        {
            for(j=0;j<26;j++)
            {
                if(flag==0)M=d[len][i][j];
                else
                {
                    M=max(M,d[len][i][j]);
                }
                flag=1;
                //cout<<d[len][i][j]<<endl;
            }
        }
        printf("%d\n",M);
    }
    return 0;
}
