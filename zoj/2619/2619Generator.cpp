#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=101100;
const int ch=128;
int chd[maxn][ch],fail[maxn],sz;
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
}
vector<int>ans;
void Ins(char *s)
{
     int p=0;
     for(;*s;s++)
     {
           if(!chd[p][(*s)-'A'])
           {
                memset(chd[sz],0,sizeof(chd[sz]));
                chd[p][(*s)-'A']=sz++;
                cout<<p<<"*"<<(*s)-'A'<<" "<<sz-1<<endl;
           }
           p=chd[p][(*s)-'A'];
     }
}
int Que[maxn];

void AC()
{
     int *s=Que,*e=Que;
     for(int i=0;i<26;i++)
         if(chd[0][i])
         {
              fail[chd[0][i]]=0;
              cout<<chd[0][i]<<"@"<<endl;
              *e++=chd[0][i];
         }
     while(s!=e)
     {
          int p=*s++;
          for(int i=0;i<26;i++)
            if(chd[p][i])
            {
                int k=chd[p][i];
                cout<<k<<" !! "<<chd[fail[p]][i]<<endl;
                fail[k]=chd[fail[p]][i];
                *e++=k;
            }
            else
              chd[p][i]=chd[fail[p]][i],cout<<p<<"//"<<i<<" "<<chd[fail[p]][i]<<endl;
     }
}
//int solve(char *s)
//{
//     ans.clear();
//     int p=0,sum=0;
//     for(;*s;s++)
//     {
//         p=chd[p][*s];
//         for(int tmp=p;tmp>0;tmp=fail[tmp])
//             if(word[tmp]) sum++,ans.push_back(word[tmp]);
//     }
//     return sum;
//}
char s[20];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int i,j,k;
    cin>>s;
    Ins(s);
    cin>>s;
    Ins(s);
    AC();
}
