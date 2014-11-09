#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int t;
char s[100000],str[100000];
int p[100000];
int main()
{
    int i,j,k,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%s",s);
        n=strlen(s);
        str[0]='$';
        str[1]='#';
        memset(p,-1,sizeof(p));
        for(i=0; i<n; i++)
        {
            str[i*2+2]=s[i];
            str[i*2+3]='#';
        }
        n=n*2+2;
        str[n]=0;
        int id,mx=0;

        for(i=1; i<n; i++)
        {
            if(mx>i)
                p[i]=min(p[2*id-i],mx-i);
            else p[i] = 1;
            for(; str[i+p[i]]==str[i-p[i]]; p[i]++)
                if(p[i]+i>mx)
                {
                    mx=p[i]+i;
                    id=i;
                }
        }
        int m=0;
        for(i=0; i<n; i++)
        {
            //cout<<i<<" "<<p[i]<<endl;
            m = max(m,p[i]);
        }
        printf("Case #%d:\n",++cas);
        {
            if(m-1<=1)
            {
                puts("");
                continue;
            }
        }
        //printf("%d\n",m-1);
        int gg=(m-1)/2;
        for(i=n-1;i>=0;i--)
        {
            if(p[i]==m)
            {
                int tmp = (i-2)/2,st,en;
                if((m-1)%2)
                {
                    st=tmp-gg;en=tmp+gg;
                }
                else
                {
                    st = tmp-gg+1;en=tmp+gg;
                }
                for(j=st;j<=en;j++)
                    printf("%c",s[j]);
                puts("");
            }
        }
    }
}
