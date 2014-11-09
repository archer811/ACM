
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
map<string,int>M;
set<int>s[505];
set<int>::iterator it;
int ans[505];
int mark[505];
char str[505][220];
int cmp(int a,int b)
{
    return strcmp(str[a],str[b])<0;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int n;
    int cas=0;
    while(t--)
    {
        M.clear();
        scanf("%d",&n);
        getchar();
        int k=1,g;
        memset(str,0,sizeof(str));
        for(i=1; i<=n; i++)
        {
//            while(!s[i].empty())s[i].pop();
s[i].clear();
            //strcpy(str[i],"");
            for(j=0;j<220;j++)
                str[i][j]='\0';
        }

        char ss[220];
        for(i=1; i<=n; i++)
        {
            j=0;
            g=0;gets(ss);
            int len = (int)strlen(ss), p = 1;
            for (int i = len - 1; i >= 0; --i)
            {
                if (ss[i] >= '0' && ss[i] <= '9')
                {
                    g += p * (ss[i] - '0');
                    p *= 10;
                }
                else
                {
                    ss[i] = '\0';
                    break;
                }
            }
            strcpy(str[i],ss);
            int tmp = M[str[i]];
            if(tmp==0)
            {
                tmp=k;
                M[str[i]]=k++;
            }
            mark[tmp]=i;
            s[tmp].insert(g);
        }
        int gg=0;
        for(i=1; i<k; i++)
        {
            int num=0;
            it=s[i].begin();
            while(it!=s[i].end())
            {
                num++;it++;
            }
            if(num<5)
            {
                ans[gg++]=mark[i];
            }
        }
        printf("Case #%d:\n",++cas);
        sort(ans,ans+gg,cmp);
        for(i=0; i<gg; i++)
            printf("%s\n",str[ans[i]]);
        if(gg==0)puts("");
    }
}
