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
int a[10];
map<string,int>M;
int main()
{
    int i,j;
    for(i=0;i<4;i++)
        a[i]=i+1;
    M.clear();
    while(next_permutation(a,a+4))
    {
        string tmp="";
        for(i=0;i<3;i++)
        {
            if(a[i]<a[i+1])tmp+="U";
            else tmp+="D";
        }
        M[tmp]++;
    }
    j=M.size();
    map<string,int>::iterator it;
    for(it=M.begin();it!=M.end();it++)
        cout<<it->first<< " "<<it->second<<endl;
    return 0;
}
