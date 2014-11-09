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
char s[100005],ss[100005];
int main()
{
    int i,j;
    while(gets(s))
    {
        int len = strlen(s);
        strcpy(ss,s);
        int start=-1,start2;
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                start=start2=i;break;
            }
        }
        int sum=-1;
        int tmp=0;
        //第一种情况，向右
        while(1)
        {
            int f=0;
            while(start<len)
            {
                if(start+1<len&&s[start+1]=='R')
                {
                    f=1;
                    swap(s[start],s[start+1]);
                    tmp++;
                    start++;
                }
                else if(start+2<len&&s[start+2]=='R')
                {
                    f=1;
                    swap(s[start],s[start+2]);
                    tmp++;
                    start+=2;
                }
                else
                {
                    break;
                }
            }
            while(start>=0)
            {
                if(start-1>=0&&s[start-1]=='L')
                {
                    f=1;
                    swap(s[start],s[start-1]);
                    tmp++;
                    start--;
                }
                else if(start-2>=0&&s[start-2]=='L')
                {
                    f=1;
                    swap(s[start],s[start-2]);
                    tmp++;
                    start-=2;
                }
                else break;
            }
            if(f==0)break;
        }
        sum = tmp;
        strcpy(s,ss);
        start=start2;
        tmp=0;
        //第二种情况：向左
        while(1)
        {
            int f=0;
            while(start>=0)
            {
                if(start-1>=0&&s[start-1]=='L')
                {
                    f=1;
                    swap(s[start],s[start-1]);
                    tmp++;
                    start--;
                }
                else if(start-2>=0&&s[start-2]=='L')
                {
                    f=1;
                    swap(s[start],s[start-2]);
                    tmp++;
                    start-=2;
                }
                else break;
            }
            while(start<len)
            {
                if(start+1<len&&s[start+1]=='R')
                {
                    f=1;
                    swap(s[start],s[start+1]);
                    tmp++;
                    start++;
                }
                else if(start+2<len&&s[start+2]=='R')
                {
                    f=1;
                    swap(s[start],s[start+2]);
                    tmp++;
                    start+=2;
                }
                else break;
            }
            if(f==0)break;
        }
        if(sum<tmp)sum=tmp;
        cout<<sum<<endl;

    }
}
