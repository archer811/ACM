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
#define ll long long
const ll mod = 1000000007;
string s[11][4];
int a[5];
int main()
{
    int i,j;
    s[0][0]=" _ ",s[1][0]="   ",s[2][0]=" _ ",s[3][0]=" _ ",s[4][0]="   ",s[5][0]=" _ ",s[6][0]=" _ ",s[7][0]=" _ ",s[8][0]=" _ ",s[9][0]=" _ ",
    s[0][1]="| |",s[1][1]="  |",s[2][1]=" _|",s[3][1]=" _|",s[4][1]="|_|",s[5][1]="|_ ",s[6][1]="|_ ",s[7][1]="  |",s[8][1]="|_|",s[9][1]="|_|",
    s[0][2]="|_|",s[1][2]="  |",s[2][2]="|_ ",s[3][2]=" _|",s[4][2]="  |",s[5][2]=" _|",s[6][2]="|_|",s[7][2]="  |",s[8][2]="|_|",s[9][2]=" _|";
    while(~scanf("%d",&a[1]))
    {
        for(int i=2;i<=4;i++) scanf("%d",&a[i]);
        for(int i=0;i<3;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cout<<s[a[j]][i];
            }
            puts("");
        }
    }
    return 0;
}
