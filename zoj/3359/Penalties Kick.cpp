#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int home[100];
int away[100];
int main()
{
    int ca,n(1),i,j;
    char ctmp[10];
    scanf("%d",&ca);
    while( ca-- )
    {
        memset(home,0,sizeof(home));
        memset(away,0,sizeof(away));
        for(i=0; i<22; ++i)
        {
            for(j=0; j<3; ++j)
            {
                scanf("%s",ctmp);
                if( ctmp[0]=='y' )
                {
                    if( i<11 )    home[i+j*11]=1;
                    else          away[(i-11)+j*11]=1;
                }
            }
        }
        int  shome=0,saway=0;
        for(i=0; i<3*11; ++i)
        {
            if( i>5 && shome!=saway )  break;

            shome+=home[i];
            if( i<5 && (shome>saway+5-i||saway>shome+4-i) )  break;
            saway+=away[i];
            if( i<5 && (shome>saway+4-i||saway>shome+4-i) )   break;
        }

        printf("Match %d:\n",n++);
        printf("Winner: ");
        if( shome>saway ) printf("home\n");
        else              printf("away\n");
        printf("Score: %d:%d\n",shome,saway);
    }

    return 0;
}
