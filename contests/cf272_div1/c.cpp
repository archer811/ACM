
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
char s[2005],p[555];
int a[2005];
int d[3005][3005];
int main()
{
    int i,j,k;
    while(scanf("%s%s",s,p)!=EOF)
    {
        int lens = strlen(s);
        int lenp = strlen(p);
        for(i=0; i<lens; i++)
        {
            j=0;
            for(k=i; k<lens; k++)
            {
                if(s[k]==p[j])j++;
                if(j>=lenp)break;
            }
            if(j>=lenp)
                a[i]=k-i+1;
            else
                a[i]=-1;
                //cout<<i<<" "<<a[i]<<endl;
        }
        memset(d,0,sizeof(d));
        for(i=0; i<lens; i++)
        {
            for(j=0; j<=i; j++)
            {
                d[i+1][j]=max(d[i+1][j],d[i][j]);
                d[i+1][j+1]=max(d[i+1][j+1],d[i][j]);
                if(a[i]!=-1)
                    d[i+a[i]][j+a[i]-lenp]=max(d[i+a[i]][j+a[i]-lenp],d[i][j]+1);
            }
        }
        for(i=0; i<=lens; i++)
        {
            printf("%d ",d[lens][i]);
        }
        puts("");
    }
    return 0;
}

