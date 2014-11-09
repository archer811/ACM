#include "stdio.h"
#define M 4

int Partition(int array[], int low, int high)
{
    int x;
    x = array[low];
    //array[0]=array[low];

    while(low < high)
    {
        while(low < high && array[high] >= x)
        {
            high--;
        }
        if(low<high)
        {
            array[low] = array[high];low++;
        }


        while(low < high && array[low] <= x)
        {
            low++;
        }
        if(low<high)
        {
            array[high] = array[low];high--;
        }


    }
    array[low] = x;

    return low;
}

int QSort(int array[], int low, int high)
{
    int flag;
    if(low < high)
    {
        flag = Partition(array, low, high);
        QSort(array, low, flag-1);
        QSort(array, flag+1, high);
    }

    return 0;
}

int main()
{
    int array[M];
    int i,low,high;

    for(i=0; i<M; i++)
        scanf("%d",&array[i]);
    low=0;
    high=M-1;

    QSort(array, low, high);

    for(i=0; i<M; i++)
        printf("%d ",array[i]);
    return 0;
}
