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
#define ll long long
int m[1000];
char str[111];
int main()
{

    int count=0;
    int ff=0,fi=0,fl=0,ffi=0,ffl=0;
    int num1=0,num2=0;
    while (gets(str))
    {
        int len=strlen(str);
        for (int i=0 ;i<len ;)
        {
            //cout<<i<<" "<<str[i]<<" "<<count<<"*"<<num1<<" "<<num2<<"\n";
            //int hh=str[i];
            //cout<<"i= "<<i<<" "<<count<<" "<<str[i]<<" "<<hh<<" "<<m[hh]<<endl;

            if (str[i]==' ')
                {i++; continue;}

            if (str[i]>='A' && str[i]<='Z')
            {
                if(m[str[i]]==0){
                m[str[i]]=1; count++;i++;continue; }
                if(m[str[i]]==1)
                {
                    i++;continue;
                }
            }

            if (str[i]>='a' && str[i]<='z'&&str[i]!='f')
            {
                if(m[str[i]]==0){
                m[str[i]]=1;
                count++;
                i++;
                continue;}
                if(m[str[i]]==1)
                {
                    i++;continue;
                }

            }

            if (str[i]=='f')
            {
                if (i+1<len && str[i+1]=='f')
                {
                    if (i+2<len && str[i+2]=='i')
                    {
                        if(ffi==0) {ffi=1;count++;}
                        i+=3;

                        //m['f']=1 ;m['i']=1;
                        continue;
                    }
                    if (i+2<len && str[i+2]=='l')
                    {
                        if(ffl==0) {ffl=1;count++;}
                        i+=3;
                        //m['f']=1;m['l']=1;
                        continue;
                    }
                    //m['f']=1;
                    if(ff==0) {ff=1;count++;}
                    i+=2;
                    continue;
                }
                if (i+1<len && str[i+1]=='i')
                {
                    //m['f']=1 ;m['i']=1;
                    i+=2;
                    if(fi==0) {fi=1;count++;}
                    continue;
                }
                if (i+1<len && str[i+1]=='l')
                {
                    //m['f']=1 ;m['l']=1;
                    if (fl==0) {fl=1;count++; }
                    i+=2;
                    continue;
                }
                if (m['f']==0) {count++;m['f']=1; }
                i++;continue;
            }
            int k=str[i];
            int k1=0;
            if (k==39||k==96)
            {
                if (i+1<len) k1=str[i+1];
                //if (k==96||k==39||k1==96||k1==39)
                if(k==k1)
                {
                    if(k==39)
                    {
                        if (num1==0) {num1=1;count++;}
                    }
                    if (k==96)
                    {
                        if (num2==0) {num2=1;count++; }
                    }

                    i+=2;continue;
                }
                if (m[str[i]]==0){m[str[i]]=1; count++;}
                i++;continue;
            }
            else
            {
                if(m[str[i]]==0) {m[str[i]]=1;count++;}
                i++;continue;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}

