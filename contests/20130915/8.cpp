#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define T int
int LMS (const T * data, int size)
{
    if (size <= 0)
        return 0;

    T * S = new T[size];
    int S_Count = 1;
    S[0] = data[0];

    for (int i = 1; i < size; i++)
    {
        const T & e = data[i];
        int low = 0, high = S_Count - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (S[mid] == e)
                break;
            else if (S[mid] > e)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (high == S_Count - 1)
            S[S_Count++] = e;
        else
            S[high + 1] = e;
    }
    return S_Count;
}
int main()
{
    int i,j,k;
    int a[10];
    for(i=0;i<3;i++)
        cin>>a[i];
    cout<<LMS(a,3)<<endl;
}
