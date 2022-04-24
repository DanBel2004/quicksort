#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORTED_DEGREE 20.0

typedef struct list
{
    long long int value;
    long long int index;
    struct list* next;
    struct list* prev;
}Node;

void quicksort_for_list(Node* left, Node* right)
{
    long long int i = left->index;
    long long int j = right->index;

    Node* opora = left;
    for (; opora->index < (i + j) / 2; opora = opora->next);
    long long int support = opora->value;

    Node* LEFT = left;
    Node* RIGHT = right;

    do {
        while (LEFT->value < support)
        {
            i++;
            LEFT = LEFT->next;
        }

        while (RIGHT->value > support)
        {
            j--;
            RIGHT = RIGHT->prev;
        }

        if (i <= j)
        {
            if (LEFT->value > RIGHT->value)
            {
                long long int buf = LEFT->value;
                LEFT->value = RIGHT->value;
                RIGHT->value = buf;
            }
            i++;
            LEFT = LEFT->next;
            j--;
            RIGHT = RIGHT->prev;
        }
    } while (i <= j);

    if (i < right->index)
        quicksort_for_list(LEFT, right);

    if (j > left->index)
        quicksort_for_list(left, RIGHT);
}


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
    srand(time(NULL));

    long long int N = 10;

    long long int* array = (long long int*)calloc(N, sizeof(long long int));
    float sorted_elements = (SORTED_DEGREE / 100) * N;

    for (long long int i = 0; i < N; i++)
    {
        if (i < sorted_elements)
            array[i] = i;
        else
            array[i] = rand() % N + (sorted_elements + 1);
    }

    /*for (long long int i = 0; i < N; i++)
        printf("%lld ", array[i]);
    printf("\n");*/


    Node* head = NULL;
    Node* tail = NULL;
    head = malloc(sizeof(Node));
    head->prev = NULL;
    Node* cur = head;

    for (int i = 0; i < N - 1; i++)
    {
        cur->value = array[i];
        cur->index = i;
        cur->next = malloc(sizeof(Node));
        cur->next->prev = cur;
        cur = cur->next;
    }
    cur->value = array[N - 1];
    cur->index = N - 1;
    cur->next = NULL;
    tail = cur;


    double start1 = 0.0;
    double end1 = 0.0;
    double time1 = 0.0;

    printf("quicksort for ARRAY: ");

    start1 = clock();

    quicksort_for_array(array, 0, N - 1);

    end1 = clock();
    time1 = (end1 - start1) / CLOCKS_PER_SEC;

    printf("%lf\n", time1);

    /*for (long long int i = 0; i < N; i++)
        printf("%lld ", array[i]);
    printf("\n");*/


    double start2 = 0.0;
    double end2 = 0.0;
    double time2 = 0.0;

    printf("quicksort for LIST: ");

    start2 = clock();

    quicksort_for_list(head, tail);

    end2 = clock();
    time2 = (end2 - start2) / CLOCKS_PER_SEC;

    printf("%lf\n", time2);

    /*while (head != NULL)
    {
        printf("%lld ", head->value);
        head = head->next;
    }*/

    free(array);
}
