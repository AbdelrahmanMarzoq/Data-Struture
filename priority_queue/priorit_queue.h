#ifndef PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_H

#define MAX 100

typedef char boolean;

typedef struct
{
    int Data[MAX];
    int top;
}priority_queue;



void priority_queue_init(priority_queue *pq);
void  priority_queue_push(priority_queue *pq, int x);
int  priority_queue_top(priority_queue *pq);
void  priority_queue_pop(priority_queue *pq);
boolean  priority_queue_empty(priority_queue *pq);

#endif
