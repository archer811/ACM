#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[2000],che[30];
#define ull unsigned long long
pair<ull,ull>a[2265025];
int main()
{
    int i,j,k;
    cin>>s>>che>>k;
    int len = strlen(s);
    int n=0;
    for(i=0;i<len;i++)
    {
        ull h1 =0,h2 =0;
        int t=0;
        for(j=i;j<len;j++)
        {
            if(che[s[j]-'a']=='0')t++;
            if(t>k)
            {

                break;
            }
            h1 = h1*3311+s[j];
            h2 = h2*13111+s[j];
            a[n++]=make_pair(h1,h2);
        }
    }
    sort(a,a+n);
    cout<<unique(a,a+n)-a<<endl;
}
