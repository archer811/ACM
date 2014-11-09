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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char s[1005];
int ans[1005];
int main()
{
    int i,j,n,p;
    scanf("%d%d",&n,&p);

    scanf("%s",s);
    p--;
    int len = strlen(s);

    int flag=-1;
    for(i=len-1;i>=0;i--)
    {
        int x = s[i]+1;
        while( x<= p+'a' && ( (i>=1&&x==s[i-1])||(i>=2&&x==s[i-2])  ))
        {
            //cout<<(char)x<<endl;
            x++;
        }

        if( x<= p+'a' &&x>s[i] )
        {
            flag=i;
            ans[flag]=x;
            break;
        }

    }
    //cout<<flag<<endl;
    if(flag!=-1)
    {
        for(i=0;i<flag;i++)
            ans[i]=(int)s[i];
        for(i=flag+1;i<len;i++)
        {
            int x = (int)'a';
            //cout<<x-(p+'a')<<endl;
            while( x<= p+'a' && ( (i>=1&&x==ans[i-1])||(i>=2&&x==ans[i-2])  ))
            {
                //cout<<(char)x<<endl;
                x++;
            }

            if(x > p+'a')
            {
                puts("NO");return 0;
            }
            ans[i]=x;
        }
        for(i=0;i<len;i++)
            printf("%c",(char)(ans[i]));
        puts("");
    }
    else puts("NO");

    return 0;
}
