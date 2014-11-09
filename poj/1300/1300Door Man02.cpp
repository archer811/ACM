#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=22;
const int INF=1000000000;
typedef __int64 lld;
int dgr[MAX];
int f[MAX];
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
char buf[11111];
bool dig(char x){return x>='0'&&x<='9';}
void build(char s[],int id)
{
    int i,j;
    for(i=0;s[i];i++)
    {
        if(dig(s[i]))
        {
            j=0;
            while(s[i]&&dig(s[i]))
            {
                j=j*10+s[i]-'0';
                i++;
            }
            i--;
            dgr[id]++;
            dgr[j]++;
            int fa=find(id);
            int fb=find(j);
            if(fa!=fb)
            {
                f[fa]=fb;
            }
        }
    }
}
int main()
{
    char cmd[111];
    int m,n;
    while(scanf("%s",cmd)!=EOF)
    {
        if(strcmp(cmd,"ENDOFINPUT")==0)break;
        scanf("%d%d",&m,&n);
        memset(dgr,0,sizeof(dgr));
        int i;
        for(i=0;i<n;i++)f[i]=i;
        getchar();

        for(i=0;i<n;i++)
        {
            gets(buf);
            build(buf,i);
        }
        gets(cmd);
        if(find(m)!=find(0))
        {
            puts("NO");
            continue;
        }
        int sum=0;
        int cnt=0;
        for(i=0;i<n;i++)
        {
            sum+=dgr[i];
            cnt+=(f[i]==i)&&dgr[i]>0;
        }
        if(cnt>1)//判连通
        {
            puts("NO");
            continue;
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            cnt+=(dgr[i]&1)==1;
        }

        if(cnt==0)//度都是偶数
        {
            printf("YES %d\n",sum>>1);
            continue;
        }
        else if(m==0)
        {
            puts("NO");
            continue;
        }
        if(cnt!=2)//奇数度不是两个
        {
            puts("NO");
        }
        else if((dgr[0]&1)&&(dgr[m]&1))//起点和终点是奇数度
        {
            printf("YES %d\n",sum>>1);
        }
        else puts("NO");
    }
    return 0;
}

/*
START 1 2
1

END
START 0 5
1 2 2 3 3 4 4




END
START 0 10
1 9
2
3
4
5
6
7
8
9

END
ENDOFINPUT


START 0 1

END

START 0 2


END

*/
