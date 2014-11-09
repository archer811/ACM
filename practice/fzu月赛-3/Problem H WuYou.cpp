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
const int maxn = 10005;
char s[maxn],t[maxn];
int a[maxn];
int len;
int judge()
{
    int i;
    for(i=0;i<len;i++)
    {
        if(a[i]<t[i]-'0')return 1;
        else if(a[i]>t[i]-'0')return 0;
    }
    return 0;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s,t);
        memset(a,0,sizeof(a));
        len = strlen(s);
        bool flag=false;
        int sum=0;
        for(i=0;i<len;i++)
        {
            if(s[i]!='?')
            {
                sum++;a[i]=s[i]-'0';
            }
        }
        if(sum==len)
        {
            if(judge())
            {
                for(i=0;i<len;i++)
                printf("%c",s[i]);
                    puts("");
            }
            else
                puts("-1");
            continue;
        }
        for(i=0; i<len; i++)
        {
            if(s[i]!='?')
            {
                if(flag)continue;
                if(s[i]<t[i]){flag=true;continue;}
            }
            else
            {
                if(flag)
                    a[i]=9;
                else
                {
                    a[i]=t[i]-'0';
                }
            }
        }

//        for(i=0;i<len;i++)
//            cout<<a[i];
//        cout<<"*"<<judge()<<endl;
        if(judge()==0)
        {
            //cout<<"()"<<endl;
            int mark=0;
            for(i=0;i<len;i++)
            {
                if(s[i]!='?'&&s[i]>t[i])break;
            }
            //if(i!=len)
            {
                i--;
                int ff=0;
                for(;i>=0;i--)
                {
                    if(s[i]=='?'&&t[i]!='0')
                    {
                        a[i]--;
                        for(j=i+1;j<len;j++)
                        {
                            if(s[j]=='?')
                                a[j]=9;
                        }
                        ff=1;
                        break;
                    }
                }
                if(ff==0)mark=true;
            }

            if(mark)
            {
                puts("-1");continue;
            }

        }
        if(a[0]==0)
        {
            puts("-1");continue;
        }
        for(i=0;i<len;i++)
            printf("%d",a[i]);
        puts("");
    }
}
