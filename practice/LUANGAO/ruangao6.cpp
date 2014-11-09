#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include<cstring>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
#include <stdio.h>
string ans;
int judge(string a)
{
    int len = a.length();
    if(len!=17)return 0;
    for(int i=0;i<len;i++)
    {
        if(i%3==2)
        {
            if(a[i]!='-')return 0;
        }
        else
        {
            if((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='F'));
            else return 0;
        }
    }
    ans="";
    for(int i=0;i<len;i++)
    {
        if(i%3==2)continue;
        ans += a[i];
    }
    return 1;
}
int Ans[20];
int find(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    else return c-'A'+10;
}
string DLL_EXPORT get_mac()
{
    FILE   *fp;
    char   buf[1024];
    memset(buf, 0,sizeof(buf));
    fp = popen( "getmac", "r" );
    fread( buf, sizeof(char), sizeof(buf),  fp);
    string Buf = "";
    int len = strlen(buf);
    for(int i=0;i<len;i++)
        Buf += buf[i];
    string a;
    istringstream stream(Buf);
    int i=0;
    int j = -1;
    while(stream>>a)
    {
        if(judge(a))
        {
            if(j==-1)
            {
                for(int k=0;k<12;k++)
                    Ans[k]=find(ans[k]);
                j = 0;
            }
            else
            {

                for(int k=0;k<12;k++)
                    Ans[k]^=find(ans[k]);
            }
        }
    }
    string Ans_string = "";
    for(i=0;i<12;i++)
    {
        if(Ans[i]<=9)
        {
            Ans_string += (char)(Ans[i]+'0');
        }
        else
        {
            Ans_string += (char)(Ans[i]+'A'-10);
        }
    }
    return Ans_string;
}
