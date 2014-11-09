#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    freopen("out.txt","w",stdout);
    int i,j=0;
    int v[30];
    cout<<"50"<<endl;
    for(i=0;i<50;i++)
    {
         memset(v,0,sizeof(v));
         int mm=0;
         for(j=0;j<14;j++)
         {
             while(1)
             {
                 int tmp = rand()%26;
                 if(mm>=10&&v[tmp]==0)continue;
                 if(v[tmp]==0)mm++;
                 v[tmp]=1;
                 //cout<<tmp<<" "<<mm<<endl;
                 if(mm<=10)
                 {
                     cout<<(char)(tmp+'a');break;
                 }
             }

         }cout<<endl;
    }

}
