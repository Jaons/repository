#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min (int *array, int *left, int *right, int pos, int end)
{
    if (*left  == pos+1)
    {
        (*right)++;
        return array[*right-1];
    }
    if (*right == end+1)
    {
        (*left)++;
        return array[*left-1];
    }
    if (array[*left] < array[*right])
    {
        ++(*left);
        return array[*left-1];
    }
    ++(*right);
    return array[*right-1];
}
      
int merge (int *array, int beg, int pos, int end)
{
    if (array == NULL || beg > pos || pos > end)
    {
        printf ("merge element error\n");
        return -1;
    }
    int *tmp = (int *)malloc((end - beg + 1)*sizeof(int));
    int i, l=beg, r=pos+1;
    for (i=0; i<=end-beg; ++i)
        tmp[i] = min(array, &l, &r, pos, end);
    for (i=0; i<=end-beg; ++i)
        array[beg+i] = tmp[i];
    free(tmp);
    return 0;
}

int merge_sort (int *array, int beg, int end)
{
    if (array == NULL)
    {
        printf ("sort element error\n");
        return -1;
    }
    if (beg < end)
    {
        int pos = (beg + end) / 2;
        merge_sort (array, beg, pos);
        merge_sort (array, pos+1, end);
        merge(array, beg, pos, end);
    }
    return 0;
}

int main ()
{
    int i, n=10;
    int array[10];
    printf ("Please input 10 numbers:\n");
    for (i=0; i!=n; ++i)
        scanf ("%d", &array[i]);
    if (merge_sort(array, 0, n-1))
        return -1;
    for (i=0; i!=n; ++i)
        printf ("%d ", array[i]);
    printf ("\n");
    return 0;
}
