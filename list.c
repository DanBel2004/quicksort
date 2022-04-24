#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    long long int N = 10;

    long long int* array = (long long int*)calloc(N, sizeof(long long int));

    for (long long int i = 0; i < N; i++)
        array[i] = rand() % N;

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

    printf("quicksort for LIST: ");

    quicksort_for_list(head, tail);

    /*while (head != NULL)
    {
        printf("%lld ", head->value);
        head = head->next;
    }*/

    free(array);
}
