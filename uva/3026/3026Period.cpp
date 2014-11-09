#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1000006];
int f[1000006];
int main()
{
    int i,j,len;
    int cas=0;
    while(scanf("%d",&len)!=EOF)
    {
        if(len==0)break;
        scanf("%s",s);
       f[0]=f[1]=0;
       for(i=1;i<len;i++)
       {
           j = f[i];
           while(j&&s[i]!=s[j])j=f[j];
           f[i+1]=(s[i]==s[j]?j+1:0);
       }
        printf("Test case #%d\n",++cas);
        for(i=1;i<=len;i++)
        {
            if(f[i]>0&&i%(i-f[i])==0)
                cout<<i<<" "<<i/(i-f[i])<<endl;
        }
        puts("");
    }
}
