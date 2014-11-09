#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std ;
const int MAXN = 55 ;
int n , m ;
char map[MAXN][MAXN] ;
short g[MAXN*MAXN][MAXN*MAXN] ; // ����һ����Ҫ��С���������ֱ��WA !!
                                // ע��ʹ��short��bool ������MLE
int cx[MAXN * MAXN] ;
int cy[MAXN * MAXN] ;
struct Point
{
    int br ;
    int bc ;
    Point():br(-1) , bc(-1) {}
} s[MAXN * MAXN] ;
int ha[MAXN][MAXN] ;     // ��������
bool vis[MAXN * MAXN] ;  // �������
int sumbr = -1 ;
int sumbc = -1 ;
void init ()
{
    memset(ha , -1 , sizeof(ha)) ;
    memset(g , 0 , sizeof(g)) ;
    memset(cx , -1 , sizeof(cx)) ;
    memset(cy , -1 , sizeof(cy)) ;
    sumbr = -1 ;   // ��¼�������
    sumbc = -1 ;   //��¼�������
    scanf("%d%d\n" , &n , &m) ;
    int i , j ;
    for(i = 0 ; i < n ; i ++)
    {
        scanf("%s" , map[i]) ;
    }
    int cnt = 0 ;
    int first = -1 ;
    for(i = 0 ; i < n ; i ++)  // ��������ţ���0��ʼ
    {
        first = -1 ;
        for(j = 0 ; j < m ; j ++)
        {
            if(map[i][j] == '#')
            {
                first = -1 ;
            }
            if(map[i][j] == 'o')
            {
                if(first == -1)
                {
                    sumbr ++ ;
                    first = 1 ;
                }
                s[cnt].br = sumbr ;
                ha[i][j] = cnt ;
                cnt ++ ;
            }
        }
    }
    for(j = 0 ; j < m ; j ++)  // ��������ţ���0��ʼ
    {
        first = -1 ;
        for(i = 0 ; i < n ; i ++)
        {
            if(map[i][j] == '#')
            {
                first = -1 ;
            }
            if(map[i][j] == 'o')
            {
                if(first == -1)
                {
                    sumbc ++ ;
                    first = 1 ;
                }
                int tmp = ha[i][j] ;
                s[tmp].bc = sumbc ;
            }
        }
    }
    for(i = 0 ; i < cnt ; i ++)  // ��ͼ
    {
        g[ s[i].br ][ s[i].bc ] = 1 ;
    }
}
int ca = 0 ;
int path(int v)  // �������㷨
{
    int i ;
    for(i = 0 ; i <= sumbc ; i ++)
    {
        if(g[v][i] == 1 && !vis[i])
        {
            vis[i] = true ;
            if(cy[i] == -1 || path(cy[i]))
            {
                cy[i] = v ;
                cx[v] = i ;
                return 1 ;
            }
        }
    }
    return 0 ;
}
void solve()
{
    int i ;
    int ans = 0 ;
    for(i = 0 ; i <= sumbr ; i ++)
    {
        if(cx[i] == -1)
        {
            memset(vis , 0 , sizeof(vis)) ;
            if(path(i))
                ans ++ ;
        }
    }
    printf("Case :%d\n" , ++ ca) ;
    printf("%d\n" , ans) ;
}
int main()
{
    int T ;
    scanf("%d" , &T) ;
    while (T --)
    {
        init() ;
        solve() ;
    }
    return 0 ;
}
