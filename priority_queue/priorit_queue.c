#include "priorit_queue.h"

static void swap(priority_queue *pq, int index1, int index2);

void priority_queue_init(priority_queue *pq)
{
    pq->top = 0;
}

void priority_queue_push(priority_queue *pq, int x)
{
    pq->Data[pq->top] = x;
    int index = pq->top++;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (pq->Data[index] < pq->Data[parent])
        {
            swap(pq, index, parent);
            index = parent;
        }
        else break;
    }
}

int priority_queue_top(priority_queue *pq)
{
    return pq->Data[0];
}

void priority_queue_pop(priority_queue *pq)
{
    pq->top--;
    swap(pq, 0, pq->top);
    int index = 0;
    while (index < pq->top)
    {
        int min_child;
        int right_child = 2*index + 2;
        int left_child = 2*index + 1;
        if (left_child >= pq->top) break;
        if (right_child < pq->top)
        {
            min_child = pq->Data[left_child] < pq->Data[right_child] ? left_child : right_child;
            if (pq->Data[index] > pq->Data[min_child])
            {
                swap(pq, index, min_child);
            }
            else break;
        }
        else if (right_child == pq->top)
        {
            min_child = left_child;
            if (pq->Data[index] > pq->Data[min_child])
            {
                swap(pq, index, min_child);
            }
            else break;
        }
        index = min_child;
    }
}

boolean priority_queue_empty(priority_queue *pq)
{
    return !(pq->top);
}

static void swap(priority_queue *pq, int index1, int index2)
{
    pq->Data[index1] += pq->Data[index2];
    pq->Data[index2] = pq->Data[index1] - pq->Data[index2];
    pq->Data[index1] -= pq->Data[index2];
}
