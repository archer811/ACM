#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1000006];
int len;
int judge(int mid)
{
    int i,j=len-1;
    for(i=0;i<mid;i++)
    {
        //if(mid==2)cout<<s[i]<<" "<<s[len-mid+i]<<endl;
        if(s[i]!=s[len-mid+i])return 0;
    }
    //if(mid==2)cout<<"e"<<endl;
    for(i=1;i<len&&i+mid<len;i++)
    {

        if(s[i]!=s[0])continue;
//cout<<i<<" "<<s[i]<<" "<<s[0]<<" "<<j<<endl;
        for(j=0;j<mid;j++)//&&i+j<len
        {
            //cout<<j<<" "<<mid<<endl;
            //if(i==1&&mid==2)cout<<j<<"*("<<endl;

            if(s[i+j]!=s[j])break;
        }//cout<<i<<" "<<s[i]<<" "<<s[0]<<" "<<j<<endl;
        if(j==mid)return 1;
    }
    return 0;
}
int main()
{
    int i,j,k;
    while(cin>>s)
    {
        len = strlen(s);
        int f=0;
        for(i=len-1;i>=1;i--)
        {
            if(judge(i))
            {
                f=1;
                for(j=0;j<i;j++)
                    printf("%c",s[j]);
                puts("");
                break;
            }
        }
        if(f==0)
        cout<<"Just a legend"<<endl;
    }
}
