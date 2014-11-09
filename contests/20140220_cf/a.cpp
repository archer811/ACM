#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[10000];
int main()
{
    int i,j;
    while(cin>>s)
    {
        int len = strlen(s);
        int a=0,b=0,c=0;
        int f1=0,f2=0;
        for(i=0; i<len; i++)
        {
            //cout<<f1<<" "<<f2<<" "<<s[i]<<endl;

            if(s[i]=='+')f1=1;
            if(s[i]=='=')f2=1;
            else if(f1==0)
            {
                if(s[i]=='|')a++;
            }
            else if(f1&&f2==0)
            {
                if(s[i]=='|')b++;
            }
            else if(f1&&f2)
            {
                if(s[i]=='|')c++;
            }
        }
       // c//out<<a<<" "<<b<<" "<<c<<endl;
        if(a+b==c)
        {
            cout<<s<<endl;
        }
        else if(a-1+b==c+1&&a>1)
        {
            for(i=0;i<a-1;i++)
                cout<<"|";
            cout<<"+";
            for(i=0;i<b;i++)
                cout<<"|";
            cout<<"=";
            for(i=0;i<c+1;i++)
                cout<<"|";
            cout<<endl;
        }
        else if(b-1+a==c+1&&b>1)
        {
            for(i=0;i<a;i++)
                cout<<"|";
            cout<<"+";
            for(i=0;i<b-1;i++)
                cout<<"|";
            cout<<"=";
            for(i=0;i<c+1;i++)
                cout<<"|";
            cout<<endl;
        }
        else if(a+1+b==c-1&&c>1)
        {
            for(i=0;i<a+1;i++)
                cout<<"|";
            cout<<"+";
            for(i=0;i<b;i++)
                cout<<"|";
            cout<<"=";
            for(i=0;i<c-1;i++)
                cout<<"|";
            cout<<endl;
        }
        else if(b+1+a==c-1&&c>1)
        {
            for(i=0;i<a;i++)
                cout<<"|";
            cout<<"+";
            for(i=0;i<b+1;i++)
                cout<<"|";
            cout<<"=";
            for(i=0;i<c-1;i++)
                cout<<"|";
            cout<<endl;
        }
        else cout<<"Impossible"<<endl;
    }
}
