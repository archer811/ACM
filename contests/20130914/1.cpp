#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int maxn=110000;
const int mo1=1000000007;
const int mo2=1000000009;
char ch1[maxn],ch2[maxn];
int ans1,ans2,sign,len,ca,num;
int f[maxn][2][2];
bool pp[maxn];
void deal(int x)
{
        ans1=(ans1+x)%mo1;
        ans2=(ans2+x)%mo2;
}
bool check(char a,char b)
{
        if ((a==b) || (a=='?')) return true; else return false;
}
bool check2(int x)
{
         if (!((x+1>=len) || (check(ch1[x+1],'1') && check(ch2[x+1],'1')))) return false;
         if (!((x+2>=len) || (pp[x+2]))) return false;
         return true;
}

void solve()
{

        bool sign=false;
        ans1=0, ans2=0;

        len=strlen(ch1);

        memset(pp,0,sizeof(pp));
        for (int i=len-1; i>=0; i--)
        {
                if (!((ch1[i]=='1') || (ch2[i]=='1'))) pp[i]=true; else break;
        }

        memset(f,0,sizeof(f));

        if (check(ch1[0],'0') && check(ch2[0],'0')) f[0][0][0]=1;
        if (check(ch1[0],'1') && check(ch2[0],'1')) f[0][1][0]=1;


        string str1="", str2="";
        for (int i=1; i<len; i++)
        {
                if ((check(ch1[i],'0')) && (check(ch2[i],'1')) && (check2(i)))
                {
                        deal(f[i-1][1][1]);
                        deal(f[i-1][0][0]);
                        if ((ans1!=0) && (!sign))
                        {
                                sign=true;
                                for (int j=0; j<i; j++)
                                {
                                        if (check(ch1[j],'0') && check(ch2[j],'0'))
                                        {
                                                str1+="0";
                                                str2+="0";
                                        }
                                        else
                                        {
                                                str1+="1";
                                                str2+="1";
                                        }
                                }
                                str1+="0";
                                str2+="1";

                                if (i+1<len)
                                {
                                        str1+="1";
                                        str2+="1";
                                }

                                for (int j=i+2; j<len; j++)
                                {
                                        str1+="0";
                                        str2+="0";
                                }
                        }
                }


                if ((check(ch1[i],'1')) && (check(ch2[i],'0')) && (check2(i)))
                {
                        deal(f[i-1][1][0]);
                        deal(f[i-1][0][1]);
                        if ((ans1!=0) && (!sign))
                        {
                                sign=true;
                                for (int j=0; j<i; j++)
                                {
                                        if (check(ch1[j],'0') && check(ch2[j],'0'))
                                        {
                                                str1+="0";
                                                str2+="0";
                                        }
                                        else
                                        {
                                                str1+="1";
                                                str2+="1";
                                        }
                                }
                                str1+="1";
                                str2+="0";

                                if (i+1<len)
                                {
                                        str1+="1";
                                        str2+="1";
                                }

                                for (int j=i+2; j<len; j++)
                                {
                                        str1+="0";
                                        str2+="0";
                                }
                        }

                }

                if ((check(ch1[i],'1')) && (check(ch2[i],'1')))
                {
                        f[i][0][0]=(f[i][0][0]+f[i-1][0][1])%mo1;
                        f[i][0][1]=(f[i][0][1]+f[i-1][0][0])%mo1;
                        f[i][1][0]=(f[i][1][0]+f[i-1][1][1])%mo1;
                        f[i][1][1]=(f[i][1][1]+f[i-1][1][0])%mo1;
                }

                if ((check(ch1[i],'0')) && (check(ch2[i],'0')))
                {
                        f[i][0][0]=(f[i][0][0]+f[i-1][0][0])%mo1;
                        f[i][0][1]=(f[i][0][1]+f[i-1][0][1])%mo1;
                        f[i][1][0]=(f[i][1][0]+f[i-1][1][0])%mo1;
                        f[i][1][1]=(f[i][1][1]+f[i-1][1][1])%mo1;
                }
        }



        printf("Case #%d:\n",++ca);
        if ((ans1==0) && (ans2==0))
        {
                printf("Impossible\n");
                return;
        }

        if ((ans1!=1) || (ans2!=1))
        {
                printf("Ambiguous %d\n",ans1);
                return;
        }


        printf("%s\n%s\n", str1.c_str(), str2.c_str());

}
void init()
{
        scanf("%d",&num);
        while (num--)
        {
                scanf("%s",ch1);
                scanf("%s",ch2);
                solve();
        }
}
int main()
{
        init();
        return 0;
}
