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
char s[4005];
struct O
{
    char s[2005];
}g[2005];
int cmp(O a,O b)
{
    return strcmp(a.s,b.s)<0;
}
int main()
{
    int i,j,k;
    while(scanf("%d%s",&k,s)!=EOF)
    {
        int len=strlen(s);
        j = len;
        for(i=0;i<j;i++)
            s[len++]=s[i];
        s[len]='\0';

        int lo=0;
        int flag=0;
        for(i=len/4; i>=1; i--)
        {
            //cout<<i<<endl;
            int sum=0;
            int tp = i;
            int pre=0,prex=i;
            for(j=0;j<i;j++,tp++)
            {
                if(s[j]!=s[tp])sum++;
                //cout<<s[j]<<"*"<<tp<<" "<<s[tp]<<" "<<sum<<endl;
            }
            //cout<<sum<<endl;
            if(sum<=k)
            {
                int ff=0;
                for(j=0;j<tp;j++)
                    g[lo].s[ff++]=s[j];
                g[lo].s[ff]='\0';
                //cout<<g[lo].s<<endl;
                lo++;
            }
            tp=i;
            for(j=1;j<len/2;j++,tp++)
            {
                if(s[j-1]!=s[j-1+i])sum--;
                if(s[tp]!=s[tp+i])sum++;
//                for(int tt=j;tt<j+2*i;tt++)
//                    cout<<s[tt];
//                cout<<endl;
//                cout<<sum<<"()"<<j-1<<" "<<j-1+i<<" "<<tp<<" "<<tp+i<<endl;
                if(sum<=k)
                {
                    int ff=0;
                    for(int tt=j;tt<j+2*i;tt++)
                        g[lo].s[ff++]=s[tt];
                    g[lo].s[ff]='\0';
                    //cout<<g[lo].s<<endl;
                    lo++;
                }
            }

            if(lo!=0)
            {
                sort(g,g+lo,cmp);
                printf("%s\n",g[0].s);
                flag=1;
                break;
            }
        }
        if(flag==0)puts("");
    }
    return 0;
}

