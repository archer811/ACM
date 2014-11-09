#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
struct array
{
    int x,y;
}g[1000005];
char s[1000005];
int ts[1000005];
#define ll __int64
ll a_odd,b_odd,a_even,b_even;
int main()
{
    int i,j;
    while(scanf("%s",s+1)!=EOF)
    {
        int num=1;
        memset(ts,0,sizeof(ts));
        int len = strlen(s+1);
        ll even=0,odd=0;
        a_odd=0;
        b_odd=0;
        a_even=0;
        b_even=0;
        for(i=1;i<=len;i++)
        {
            if(s[i]=='a')
            {
                if(i%2==0)a_even++;
                else a_odd++;
                even+=(i%2==0?a_odd:a_even);
                odd+=(i%2==0?a_even:a_odd);

            }
            else
            {
                if(i%2==0)b_even++;
                else b_odd++;
                even+=(i%2==0?b_odd:b_even);
                odd+=(i%2==0?b_even:b_odd);

            }
            //cout<<a_odd<<" "<<a_even<<" "<<b_odd<<"  "<<b_even<<" "<<odd<<" "<<even<<endl;
        }

        cout<<even<<" "<<odd<<endl;
    }
    return 0;
}
