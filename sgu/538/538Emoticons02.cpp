#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e5+5;

char mas[N];

int main()
{
//    freopen("in","r",stdin);
    while(gets(mas))
    {
        int len=strlen(mas),res=0;
        bool ok=false;
        for(int i=0; i<len; i++)
        {
            if(mas[i]=='(')
            {
                ok=true;
                res++;
            }
            else if(mas[i]==')')
            {
                if(ok)
                {
                    res--;
                    ok=false;
                }
                else
                {
                    res++;
                }
            }
            else if(mas[i]==32 || (mas[i]>='A' && mas[i]<='Z') || (mas[i]>='a' && mas[i]<='z'))
            {
                continue;
            }
            else
            {
                ok=false;
            }
            cout<<mas[i]<<" "<<res<<endl;
        }
        printf("%d\n",res);
    }
    return 0;
}
