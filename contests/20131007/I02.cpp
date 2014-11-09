#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXN 505

struct Item
{
    char name[22];
    int arr[6];
    int Count;
} ar[MAXN];

char str[32], res[MAXN][22];
int N, Member;

int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b) < 0 ? -1 : 1;
}

int main(void)
{
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; ++T)
    {
        scanf("%d", &N);
        Member = 0;
        for (int k = 0; k < N; ++k)
        {
            int count = 0, i;
            while (gets(str) && (int)strlen(str) <1);
            int len = (int)strlen(str), p = 1;
            for (int i = len - 1; i >= 0; --i)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    count += p * (str[i] - '0');
                    p *= 10;
                }
                else
                {
                    str[i] = '\0';
                    break;
                }
            }
            for (i = 0; i < Member; ++i)
            {
                if (strcmp(str, ar[i].name) == 0)
                {
                    int j;
                    if (ar[i].Count >= 5) break;
                    for (j = 0; j < ar[i].Count; ++j)
                    {
                        if (ar[i].arr[j] == count)
                        {
                            break;
                        }
                    }
                    if (j >= ar[i].Count)
                    {
                        ar[i].arr[ar[i].Count++] = count;
                    }
                    break;
                }
            }
            if (i >= Member)
            {
                strcpy(ar[Member].name, str);
                ar[Member].Count = 0;
                ar[Member].arr[ar[Member].Count++] = count;
                Member++;
            }
        }
        printf("Case #%d:\n", T);
        //test
        //	printf("Member: %d\n", Member);
        //end
        int n = 0;
        for (int i = 0; i < Member; ++i)
        {
            if (ar[i].Count < 5)
            {
                strcpy(res[n++], ar[i].name);
            }
        }
        for (int i = 0; i < Member; ++i)
        {
            ar[i].Count = 0;
        }
        qsort(res, n, sizeof(res[0]), cmp);
        for (int i = 0; i < n; ++i)
        {
            printf("%s\n", res[i]);
        }
    }
    return 0;
}

/*

10
6
ahmed 2010
ahmed 2011
ahmed 2009
ahmed 2008
ahmed 2005
mohamed 2001

10
a 1
a 1
b 2
b 3
b 4
b 5
b 3
b 4
b 5
b 2

11
a 1
a 1
b 2
b 3
b 4
b 5
b 3
b 4
b 5
b 2
b 10

10
b 2
b 3
b 4
b 5
b 3
b 4
b 5
b 2
a 1
a 1


*/
