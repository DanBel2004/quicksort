#include <stdio.h>
#include <stdlib.h>

void quicksort_for_array(long long int* array, long long int left, long long int right)
{
    long long int i = left;
    long long int j = right;
    long long int opora = array[(left + right) / 2];
    long long int temp = 0;

    do {
        while (array[i] < opora)
            i++;

        while (array[j] > opora)
            j--;

        if (i <= j)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < right)
        quicksort_for_array(array, i, right);

    if (j > left)
        quicksort_for_array(array, left, j);
}

int main()
{
    long long int N = 10;

    long long int* array = (long long int*)calloc(N, sizeof(long long int));

    for (long long int i = 0; i < N; i++)
        array[i] = rand() % N;

    /*for (long long int i = 0; i < N; i++)
        printf("%lld ", array[i]);
    printf("\n");*/

    printf("quicksort for ARRAY: ");
    
    quicksort_for_array(array, 0, N - 1);
    
    /*for (long long int i = 0; i < N; i++)
        printf("%lld ", array[i]);
    printf("\n");*/

    free(array);
}
