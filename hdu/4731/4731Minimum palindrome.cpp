#include<stdio.h>
#include<string.h>
const int MN=1000010;
char ans[MN];
int num[30];

int main()
{
    int i,j,T;
    int m,n;//m个字母，n个长度
    int tes=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",tes++);
        if(m==1)
        {
            for(i=0; i<n; i++) printf("a");
        }
        else if(m==2)
        {
            if(n==1) printf("a");
            else if(n==2) printf("ab");
            else if(n==3) printf("aab");
            else if(n==4) printf("aabb");
            else if(n==5) printf("aaaba");
            else if(n==6) printf("aaabab");
            else if(n==7) printf("aaababb");
            else if(n==8) printf("aaababbb");
            else
            {
                if((n-2)%6==0 || (n-2)%6==5)
                {
                    printf("aa");
                    int tt=1;
                    for(i=3; i<=n; i++)
                    {
                        if(tt==1) printf("a");
                        if(tt==2) printf("a");
                        if(tt==3) printf("b");
                        if(tt==4) printf("a");
                        if(tt==5) printf("b");
                        if(tt==6) printf("b");
                        tt++;
                        if(tt==7) tt=1;
                    }
                }
                else
                {
                    printf("aa");
                    int tt=1;
                    for(i=3; i<=n-(n-2)%6; i++)
                    {
                        if(tt==1) printf("a");
                        if(tt==2) printf("a");
                        if(tt==3) printf("b");
                        if(tt==4) printf("a");
                        if(tt==5) printf("b");
                        if(tt==6) printf("b");
                        tt++;
                        if(tt==7) tt=1;
                    }
                    for(;i<=n;i++) printf("a");
                }
            }
        }
        else
        {
            if(n==1) printf("a");
            else if(n==2) printf("ab");
            else if(n==3) printf("abc");
            else
            {
                int cas=0;
                for(i=1; i<=n; i++)
                {
                    if(cas==0) printf("a");
                    else if(cas==1) printf("b");
                    else if(cas==2) printf("c");
                    cas++;
                    cas%=3;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
