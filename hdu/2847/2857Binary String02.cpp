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
char s[22];
int k;
int x=0,y=0;
int a[60],len;
int judge(int g)
{
    int i,j;
    int x2=0,y2=0;
    j=0;
    while(g)
    {
        if(g%2)a[j++]=1,x2++;
        else a[j++]=0,y2++;
        g/=2;
    }
    if(x>x2)return 0;
    int l = j;
    j--;
    for(i=0;i<len;i++)
    {
        if(j<0)break;
        if(s[i]-'0'==a[j]){j--;}
        else
        {
            i--;j--;
        }
    }
    if(i==len)
    {
        for(i=l-1;i>=0;i--)
            printf("%d",a[i]);
        puts("");
        return 1;
    }
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        if(s[0]=='0')
        {
            cout<<0<<endl;
            continue;
        }
        x=0;y=0;
        len = strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='1')x++;
            else y++;
        }
        for(i=1;;i++)
        {
            if(judge(i*k))
            {
                break;
            }
        }
    }
}
