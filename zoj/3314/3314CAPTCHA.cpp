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
char s[]="111111MMM11111111MMMMMMMMMMM111111111MMMMMMMM1111MMMMMMMMMMM11111MMMMMMMMMMMM1111MMMMMMMMMMMMM1111111MM1MM1111111MM11111111MM111111MM1111111MM111MM111111111MM111MM11111111111111MM11111111111111111MM111MM111111MM11111111MM11111MM111111111MM11MM1111111111MM11MM11111111111111MM1111111111111111MMMMMMMMM11111MMMMMMMMMMM111111MM1111111111111MM1111111111MM11MMMMMMMMMMMM1111MMMMMMMMMMMMM1111MM1111111MM1111MM11111111MM11111MM111111111MM11MM1111111111MM11MM11111111111111MM11111111111111MMM11111111MM111MM11111111MM111111MM1111111MM111MM111111111MM111MM11111111111111MM11111111111111MM1111111111MM11MMMMMMMMMMM111111111MMMMMMMM1111MMMMMMMMMMM11111MMMMMMMMMMMM1111MM111111111111111111MMMMMMMM1111MM111111111MM1111111MMMMMM111111111MMMMMMMM111111MM111111MMM11111MM111111111111111MM1111111MM111MM111111111MM111111111MM11111111111111MM111111111MM11111MMM111111MM11111111111111MM111111111MM11MM111111111MM111111111MM11111111111111MM111111111MM111MMM11111111MM11111111111111MM1111111111111MMMMMMMMMMMMM111111111MM11111111111111MM111111111MMMMM11111111111MM11111111111111MM111111MMMMM11MM111111111MM111111111MM1111111111MM11MM111111111MM111MMM11111111MM111111111111111MM1111111MM111MM111111111MM111111111MM1111111111MMM1MM111111111MM11111MMM111111MM11111111111111111MMMMMMMMM111MM111111111MM1111111MMMMMM1111111111MMMM111111111MM111111MMMM1111MMMMMMMMMMMM111MM1111111111MM11MMM111111111MM111111MMMMMM111111MMMMMMMMMMM111111111MMMMMM111111MMMMMMMMMMM11111MMMM111111MMMM11MMMM11111111MM1111MMM1111MMM1111MM111111111MM11111MMM1111MMM1111MM111111111MM111MM1MM1111MM1MM11MM1MM1111111MM111MMM111111MMM111MM1111111111MM111MMM111111MMM111MM1111111111MM11MM11MMMMM111MM11MM11MM111111MM11MM1111111111MM11MM111111111MM111MM1111111111MM11MM111111111MM111MM1111M11111MM11MM1111MM1111MM111MMM111111MMM111MMMMMMMMMMM111111MMM1MMMM1MMM111MMMMMMMMMMM11111MM1111111111MM11MM111111MMM1MM1111MMM1111MMM1111MM1111111111111111MMM11MMMMM1111MM11111111MM1111MM1111111111MM11MM11111111MMMM111111MMMMMM111111MM1111111111111111111MMMM1MMMM11MM111111111MMM11111MMMMMMMM111111MMMMMMMMMMMM111MM1111111111MM11MMMM111111MMMM11MM1111111111MM111MMM111111MMM11111MM1111111MM1111MMMMMMMMMMMM111MM1111111111MM111MMM111111MMM111MM1111111111MM1111MMM1111MMM11111MMM1111111MMM11111111MM11111111MM1111111111MM111MMM111111MMM1111MM111MM111MM111111MMM11MMM11111111MMMMM11111111111111MM11111111MM1111111111MM1111MMM1111MMM11111MM111MM111MM11111111MMMM1111111MMM111MMMM111111111111MM11111111MMM11111111MMM11111MMM11MMM111111MM111MM111MM111111MMM11MMM1111111MMM11111MMM111111111MM11111111MMM11111111MMM111111MM11MM1111111MM1MM11MM1MM11111MMM1111MMM11111111MMMMMMM11111111111MM1111111111MMMMMMMMMM111111111MMMM111111111MMM1111MMM11111MMM111111MMM1111MMM111111MMM11111MMMMMMMMMM111111MMM1111MMM1111111111111MM11111111MMM11MMM1111111111111MM11111111111MMMM11111111111111MM1111111111111MM1111111111111MM111111111111111MM111111111111MM111111111";
int main()
{
    int i,j;
    int k=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<16;j++)
            cout<<s[k++];
        cout<<endl;
    }
}