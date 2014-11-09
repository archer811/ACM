#include<stdio.h>
#include<string.h>
int Ans[20];
int flag;
int change(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    else return c-'A'+10;
}
void judge(char a[])
{
    int len = strlen(a);

    if(len!=17)return;
    int i;
    for(i=0;i<len;i++)
    {
        if(i%3==2)
        {
            if(a[i]!='-')return;
        }
        else
        {
            if((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='F'));
            else return;
        }
    }
    int j=0;
    for(i=0;i<len;i++)
    {
        if(i%3==2)continue;
        if(flag==0)
        {
            Ans[j++]=change(a[i]);
        }
        else
        {
            Ans[j] = ((change(a[i]))^Ans[j]);
            j++;
        }
    }
    flag=1;
    return;
}
char* get_mac()
{
    FILE   *fp;
    char   buf[1024];
    memset(buf, 0,sizeof(buf));
    fp = popen( "getmac -v", "r" );
    fread( buf, sizeof(char), sizeof(buf),  fp);
    char Buf[1024];
    flag=0;
    memset(Buf,0,sizeof(Buf));
    int len = strlen(buf);
    int i,j;
    for(i=0;i<len;i++)
        Buf[i] = buf[i];
    i=0;
    while(i<len)
    {
        while(i<len&&(Buf[i]==' '||Buf[i]=='\n'))i++;
        char a[1024];
        memset(a,0,sizeof(a));
        j=0;
        while(i<len&&Buf[i]!=' ')
        {
            a[j++]=Buf[i];
            i++;
        }
        a[j]='\0';
        judge(a);
    }
    char Ans_string[1024];
    memset(Ans_string,0,sizeof(Ans_string));
    for(i=0;i<12;i++)
    {
        if(Ans[i]<=9)
        {
            Ans_string[i] = (char)(Ans[i]+'0');
        }
        else
        {
            Ans_string[i] = (char)(Ans[i]+'A'-10);
        }
    }
    return Ans_string;
}
int main()
{
    printf("%s\n",get_mac());
}
