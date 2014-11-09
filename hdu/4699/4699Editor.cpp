#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int inf = 0x3fffffff;
struct array
{
    int sum,_min,_max;
    array(int sum,int _min,int _max):sum(sum),_min(_min),_max(_max){}
};
char op[2];
void push(vector<array> &a,int d)
{
    array last = a.back();
    int sum = last.sum+d;
    a.push_back(array(sum,min(sum,last._min),max(sum,last._max)));
}
int pop(vector<array> &a)
{
    array last = a.back();
    a.pop_back();
    return last.sum-a.back().sum;
}
int main()
{
    int i,j,k,q,d;
    while(scanf("%d",&q)!=EOF)
    {
        vector<array>prefix,sufix;
        prefix.push_back(array(0,inf,-inf));
        sufix.push_back(array(0,0,0));
        while(q--)
        {
            scanf("%s",op);
            if(op[0]=='I')
            {
                scanf("%d",&d);
                push(prefix,d);
            }
            else if(op[0]=='D')
            {
                pop(prefix);
            }
            else if(op[0]=='L')
            {
                if(prefix.size()>1)
                {
                    push(sufix,pop(prefix));
                }
            }
            else if(op[0]=='R')
            {
                if(sufix.size()>1)
                {
                    push(prefix,pop(sufix));
                }
            }
            else
            {
                scanf("%d",&d);
                printf("%d\n",prefix[d]._max);
            }
        }
    }
}
