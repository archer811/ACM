#include <windows.h>
#include <stdio.h>
char cmdstr[256];
int i;
int YN(int k)
{
    FILE *f;
    char fn[40];
    char ln[80];
    int yn=0;

    sprintf(fn,"d:\\ping%d.txt",k);
    f=fopen(fn,"r");
    if (NULL!=f)
    {
        fgets(ln,80,f);
        fgets(ln,80,f);
        fgets(ln,80,f);
        if (1==fscanf(f,"Re%c",&yn)) yn='q'-yn;
        fclose(f);
        unlink(fn);
    }
    return yn;
}
int main()
{
    for (i=115; i<=115; i++)
    {
        sprintf(cmdstr,"cmd /c getmac -v>d:\\ping%d.txt");
        WinExec(cmdstr,SW_HIDE);
    }
    for (i=115; i<130; i++)
    {
        printf("%d 192.168.2.%d\n",YN(i),i);
    }
}
