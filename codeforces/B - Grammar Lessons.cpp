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
#include<iostream>
#include<sstream>
using namespace std;
// 0 adj 1 non 2 v
//0 M 1 fe
struct array
{
    int x,y;
}o[100005];
int k;
string g[]={"lios","liala","etr","etra","initis","inites"};
int num[] = {4,     5,      3,   4,      6,    6};
int f(string x,int len)
{
    for(int i=0;i<6;i++)
    {
        if(len>=num[i])
        {
            int k=len-1;
            int j;
            for(j=num[i]-1;j>=0;j--)
            {
                if(x[k]!=g[i][j])break;
                k--;
            }
            if(j<0)return i;
        }
    }
    return -1;
}
void judge(string x)
{
    int len = x.length();
    int l = f(x,len);
    if(l==0)
    {
        o[k].x= 0;
        o[k++].y=0;
    }
    else if(l==1)
    {
        o[k].x=0;
        o[k++].y=1;
    }
    else if(l==2)
    {
        o[k].x=1;
        o[k++].y=0;
    }
    else if(l==3)
    {
        o[k].x=1;
        o[k++].y=1;
    }
    else if(l==4)
    {
        o[k].x=2;
        o[k++].y=0;
    }
    else if(l==5)
    {
        o[k].x=2;
        o[k++].y=1;
    }
    else{
        o[k].x=-1;
        o[k++].y=-1;
    }
}
int main()
{
	string str, line;
	while(getline(cin, line))
	{
	    k=0;
	    int i;
		istringstream stream(line);
		while(stream>>str)
		{
		    judge(str);
		}
		int flag=0;
		if(k<=1)
        {
            if(o[0].x!=-1)puts("YES");
            else puts("NO");
            continue;
        }
//        for(i=0;i<k;i++)
//        {
//            cout<<i<<"  "<<o[i].x<<"  "<<o[i].y<<endl;
//        }
        int M=-1;
        int t=0;
		for(i=0;i<k;i++)
        {
            if(o[i].x==-1)flag=1;
            if(o[i].y!=o[0].y)flag=1;
            if(o[i].x==1)
            {
                M=i;
                t++;
            }
        }
        if(t!=1)flag=1;
        else if(flag==0)
        {
            for(i=M-1;i>=0;i--)
            {
                if(o[i].x!=0)flag=1;
            }
            for(i=M+1;i<k;i++)
            {
                if(o[i].x!=2)flag=1;
            }
        }
        if(flag)puts("NO");
        else puts("YES");
	}
	return 0;
}

