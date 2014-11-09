#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[501000];
int n;
int a[501000],f[501000];
bool flag=false;
int Len;
int mark[5010000];
int main()
{
    int i,j;
   // cout<<log(500000)<<endl;
    while(scanf("%d",&n)!=EOF)
    {
        //scanf("%d",&n);
	    int len;
        scanf("%s",s);
        len = max(len,20);
        //cout<<s<<" "<<len<<endl;
        flag=false;
        memset(mark,0,sizeof(mark));
        for(i=1;i<=len&&flag==false;i++)
        {
            //cout<<i<<endl;
            for(j=0;j<(1<<i);j++)
                mark[j]=0;
            for(j=0;j<=n-i&&flag==0;j++)
            {
                int sum=0;
                for(int k=j;k<i+j;k++)
                {
                    if(s[k]=='a')sum=sum*2;
                    else if(s[k]=='b')sum=sum*2+1;
                    //cout<<sum<<endl;

                }mark[sum]=1;
                //if(i==1)
                //cout<<i<<" "<<j<<" "<<sum<<endl;

            }
            for(j=0;j<(1<<i)&&flag==false;j++)
            {
                if(mark[j]==0)
                {
                    printf("%d\n",i);
                    for(int k=0;k<i;k++)
                        if(j&(1<<k))printf("b");
                        else printf("a");
                    puts("");
                    flag=true;
                    break;
                }
            }
        }
    }
}
