#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int srange = 10000000;      //���귶Χ
const int ra = 131072;     //�߶�������
int c[ ra * 2 ], d[ ra * 2 ];     //�߶���
int a[ 100000 ], b[ 100000 ];   //������ʱ����
int order[ 400000 ], torder[ 100000 ]; //������
int index[ 100000 ];     //������ȡ����Ϊ���ڳ���ʱ����ȡ��ĳ����λ�ã�
int road[ 100000 ][ 8 ];    //ÿ�������ӳ�ȥ��8����
int y[ 100000 ], x[ 100000 ];     //������
int n;         //�����
int swap( int &a, int &b )    //����������
{
    int t = a;
    a = b;
    b = t;
}
int insert( int a, int b, int i ) //���߶����в���һ����
{
    a += ra;
    while ( a != 0 )
    {
        if ( c[ a ] > b )
        {
            c[ a ] = b;
            d[ a ] = i;
        }
        else break;
        a >>= 1;
    }
}
int find( int a )      //��c[0..a]������С�������߶�����ѯ
{
    a += ra;
    int ret = d[ a ], max = c[ a ];
    while ( a > 1 )
    {
        if ( ( a & 1 ) == 1 )
            if ( c[ --a ] < max )
            {
                max = c[ a ];
                ret = d[ a ];
            }
        a >>= 1;
    }
    return ret;
}
int ta[ 65536 ], tb[ 100000 ];    //����������ʱ����
int radixsort( int *p )     //����������pΪ��׼
{
    memset( ta, 0, sizeof( ta ) );
    for (int i = 0; i < n; i++ ) ta[ p[ i ] & 0xffff ]++;
    for (int i = 0; i < 65535; i++ ) ta[ i + 1 ] += ta[ i ];
    for (int i = n - 1; i >= 0; i-- ) tb[ --ta[ p[ order[ i ] ] & 0xffff ] ] = order[ i ];
    memmove( order, tb, n * sizeof( int ) );
    memset( ta, 0, sizeof( ta ) );
    for (int i = 0; i < n; i++ ) ta[ p[ i ] >> 16 ]++;
    for (int i = 0; i < 65535; i++ ) ta[ i + 1 ] += ta[ i ];
    for (int i = n - 1; i >= 0; i-- ) tb[ --ta[ p[ order[ i ] ] >> 16 ] ] = order[ i ];
    memmove( order, tb, n * sizeof( int ) );
}
int work( int ii )                //��ÿ������һ������������ĵ�
{
    for (int i = 0; i < n; i++ ) //����ǰ��׼������
    {
        a[ i ] = y[ i ] - x[ i ] + srange;
        b[ i ] = srange - y[ i ];
        order[ i ] = i;
    }
    radixsort( b );      //����
    radixsort( a );
    for (int i = 0; i < n; i++ )
    {
        torder[ i ] = order[ i ];
        order[ i ] = i;
    }
    radixsort( a );      //Ϊ�߶�������������
    radixsort( b );
    for (int i = 0; i < n; i++ )
    {
        index[ order[ i ] ] = i; //orderȡ������index
    }
    for (int i = 1; i < ra + n; i++ ) c[ i ] = 0x7fffffff; //�߶�����ʼ��
    memset( d, 0xff, sizeof( d ) );
    for (int i = 0; i < n; i++ ) //�߶�������ɾ������
    {
        int tt = torder[ i ];
        road[ tt ][ ii ] = find( index[ tt ] );
        insert( index[ tt ], y[ tt ] + x[ tt ], tt );
    }
}
int distanc( int a, int b )       //������ľ��룬֮������һ��e����Ϊ����������ʹ��distance��Ϊ������
{
    return abs( x[ a ] - x[ b ] ) + abs( y[ a ] - y[ b ] );
}
int ttb[ 400000 ];      //���������ʱ����
int rx[ 400000 ], ry[ 400000 ], rd[ 400000 ]; //�ߵĴ洢
int rr = 0;
int radixsort_2( int *p )    //���ǻ�������copy+paste�Ĳ���
{
    memset( ta, 0, sizeof( ta ) );
    for (int i = 0; i < rr; i++ ) ta[ p[ i ] & 0xffff ]++;
    for (int i = 0; i < 65535; i++ ) ta[ i + 1 ] += ta[ i ];
    for (int i = rr - 1; i >= 0; i-- ) ttb[ --ta[ p[ order[ i ] ] & 0xffff ] ] = order[ i ];
    memmove( order, ttb, rr * sizeof( int ) );
    memset( ta, 0, sizeof( ta ) );
    for (int i = 0; i < rr; i++ ) ta[ p[ i ] >> 16 ]++;
    for (int i = 0; i < 65535; i++ ) ta[ i + 1 ] += ta[ i ];
    for (int i = rr - 1; i >= 0; i-- ) ttb[ --ta[ p[ order[ i ] ] >> 16 ] ] = order[ i ];
    memmove( order, ttb, rr * sizeof( int ) );
}
int father[ 100000 ], rank[ 100000 ];    //���鼯
int findfather( int x )                  //���鼯Ѱ�Ҵ���Ԫ
{
    if ( father[ x ] != -1 )
        return ( father[ x ] = findfather( father[ x ] ) );
    else return x;
}
long long kruskal()                      //��С������
{
    rr = 0;
    int tot = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++ )         //�õ��߱�
    {
        for (int j = 0; j < 4; j++ )
        {
            if ( road[ i ][ j ] != -1 )
            {
                rx[ rr ] = i;
                ry[ rr ] = road[ i ][ j ];
                rd[ rr++ ] = distanc( i, road[ i ][ j ] );
            }
        }
    }
    for (int i = 0; i < rr; i++ ) order[ i ] = i; //����
    radixsort_2( rd );
    memset( father, 0xff, sizeof( father ) ); //���鼯��ʼ��
    memset( rank, 0, sizeof( rank ) );
    for (int i = 0; i < rr; i++ )     //kruskal��С��������׼�㷨
    {
        if ( tot == n - 1 ) break;
        int t = order[ i ];
        int x = findfather( rx[ t ] ), y = findfather( ry[ t ] );
        if ( x != y )
        {
            ans += rd[ t ];
            tot++;
            int &rkx = rank[ x ], &rky = rank[ y ];
            if ( rkx > rky ) father[ y ] = x;
            else
            {
                father[ x ] = y;
                if ( rkx == rky ) rky++;
            }
        }
    }
    return ans;
}
int casenum = 0;
int main() //������
{
    while ( cin >> n )
    {
        if ( n == 0 ) break;
        for (int i = 0; i < n; i++ )
            scanf( "%d %d", &x[ i ], &y[ i ] );
        memset( road, 0xff, sizeof( road ) );
        for (int i = 0; i < 4; i++ )             //Ϊ�˼��ٱ�̸��Ӷȣ�work()����ֻд��һ�֣����������ת������ķ�ʽ���ƴ���
        {
            //Ϊ�˽����㷨���Ӷȣ�ֻ���4������ı�
            if ( i == 2 )
            {
                for (int j = 0; j < n; j++ ) swap( x[ j ], y[ j ] );
            }
            if ( ( i & 1 ) == 1 )
            {
                for (int j = 0; j < n; j++ ) x[ j ] = srange - x[ j ];
            }
            work( i );
        }
        printf( "Case %d: Total Weight = ", ++casenum );
        cout << kruskal() << endl;
    }
}
