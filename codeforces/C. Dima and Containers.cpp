#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100005;
struct array
{
    int index,num;
    bool friend operator < (array x,array y)
    {
        return x.num>y.num;
    }
};
array ans[5];
array now;
int a[maxn],vis[maxn];
multiset<array>s;
multiset<array>::iterator it;
int numback,numque,numsta,numfro;
int main()
{
    int i,j,k,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        s.clear();
        memset(vis,0,sizeof(vis));
        numque=numsta=numfro=0;
        for(int g=1;g<=n;g++)
        {
            scanf("%d",&m);
            a[g]=m;
            if(m==0)
            {
                if(!s.empty())
                {
                    it = s.begin();
                    int num=0;
                    while(it!=s.end())
                    {
                        now.index = it->index;
                        now.num = it->num;
                        it++;
                        num++;
                        ans[num]=now;
                        if(num==3)break;
                    }
                    for(i=1;i<=num;i++)
                    {
                        vis[ans[i].index]=1;
                    }
                }
                s.clear();
            }
            else
            {
                now.index = g;
                now.num = m;
                s.insert(now);
            }
        }
        for(int g=1;g<=n;g++)
        {
            if(a[g]==0)
            {
                int num=0;
                if(numque>0)num++;
                if(numsta>0)num++;
                if(numfro>0)num++;
                if(num==0)
                {
                    puts("0");
                    continue;
                }
                else
                {
                    printf("%d",num);
                    if(numque>0)
                    {
                        numque--;
                        printf(" popQueue");
                    }
                    if(numsta>0)
                    {
                        numsta--;
                        printf(" popStack");
                    }
                    if(numfro>0)
                    {
                        numfro--;
                        printf(" popFront");
                    }
                }
                puts("");
            }
            else
            {
                if(vis[g])
                {
                    int ant = 1,M=numque;
                    if(numsta<M){M=numsta;ant=2;}
                    if(numfro<M){M=numfro;ant=3;}
                    if(ant==1)numque++,puts("pushQueue");
                    else if(ant==2)numsta++,puts("pushStack");
                    else if(ant==3)numfro++,puts("pushFront");
                }
                else puts("pushBack");
            }
        }
    }
}
