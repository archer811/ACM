#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "windows.h"
using namespace std;
//命令行输出缓冲大小
const long MAX_COMMAND_SIZE = 10000;

//获取MAC命令行
char szFetCmd[] = "ipconfig /all";

//网卡MAC地址的前导信息

const string str4Search = "Physical Address. . . . . . . . . : ";

//用命令行方式获取网卡MAC地址

BOOL GetMacByCmd(char *lpszMac);

BOOL GetMacByCmd(char *lpszMac)

{

    //初始化返回MAC地址缓冲区

    memset(lpszMac, 0x00, sizeof(lpszMac));

    BOOL bret;

    SECURITY_ATTRIBUTES sa;

    HANDLE hReadPipe,hWritePipe;

    sa.nLength = sizeof(SECURITY_ATTRIBUTES);

    sa.lpSecurityDescriptor = NULL;

    sa.bInheritHandle = TRUE;

    //创建管道

    bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);

    if(!bret)

    {

        return FALSE;

    }

    //控制命令行窗口信息

    STARTUPINFO si;

    //返回进程信息

    PROCESS_INFORMATION pi;

    si.cb = sizeof(STARTUPINFO);

    GetStartupInfo(&si);

    si.hStdError = hWritePipe;

    si.hStdOutput = hWritePipe;

    si.wShowWindow = SW_HIDE; //隐藏命令行窗口

    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

//创建获取命令行进程

    bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL,

                          NULL, &si, &pi );

    char szBuffer[MAX_COMMAND_SIZE+1]; //放置命令行输出缓冲区

    string strBuffer;

    vector<string> strBuffers;

    if (bret)

    {

        WaitForSingleObject (pi.hProcess, INFINITE);

        unsigned long count;

        CloseHandle(hWritePipe);

        memset(szBuffer, 0x00, sizeof(szBuffer));

        bret  =  ReadFile(hReadPipe,  szBuffer,  MAX_COMMAND_SIZE,  &count,  0);

        if(!bret)

        {

            //关闭所有的句柄

            CloseHandle(hWritePipe);

            CloseHandle(pi.hProcess);

            CloseHandle(pi.hThread);

            CloseHandle(hReadPipe);

            return FALSE;

        }

        else

        {

            strBuffer = szBuffer;

            long ipos = 0 ;

            while(1)

            {

                ipos = 0;

                ipos = strBuffer.find(str4Search,ipos);

                if(ipos == -1)

                    break;

                //提取MAC地址串

                strBuffer = strBuffer.substr(ipos+str4Search.length());

                int ipos1 = strBuffer.find("\n");

                strBuffers.push_back(strBuffer.substr(0, ipos1));

                cout << strBuffers[strBuffers.size()-1].c_str();

                cout << endl;

            }

        }

    }

    memset(szBuffer, 0x00, sizeof(szBuffer));

    strcpy(szBuffer, strBuffers[0].c_str());

    //去掉中间的“00-50-EB-0F-27-82”中间的'-'得到0050EB0F2782

    int j = 0;

    for(int i=0; i<strlen(szBuffer); i++)

    {

        if(szBuffer[i] != '-')

        {

            lpszMac[j] = szBuffer[i];

            j++;

        }

    }

    //关闭所有的句柄

    CloseHandle(hWritePipe);

    CloseHandle(pi.hProcess);

    CloseHandle(pi.hThread);

    CloseHandle(hReadPipe);

    return TRUE;

}

extern BOOL GetMacByCmd(char *lpszMac);

int main ()
{

    char lpszMac[128];

    memset(lpszMac, 0x00, sizeof(lpszMac));

    //获取MAC

    GetMacByCmd(lpszMac);

    //打印出MAC

    cout << lpszMac << endl;

    //写入文件

    //FILE *fp = NULL;

    //fp = fopen("c:\\1.txt", "w");

    //fwrite(lpszMac, sizeof(char), strlen(lpszMac), fp);

    //fclose(fp);
}

