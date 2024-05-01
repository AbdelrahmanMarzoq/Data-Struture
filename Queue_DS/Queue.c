#include "Queue.h"


boolean init (Queue *myQueue)
{
    if(NULL == myQueue) return 0;
    else
    {
        myQueue->Front = NULL;
        myQueue->Rear = NULL;
        myQueue->Size = 0;
        return 1;
    }
}

boolean Empty (Queue *myQueue)
{
    if (NULL == myQueue) {}
    else return !(myQueue->Size);
}

boolean push (Queue *myQueue, Entry Data)
{
    if(NULL == myQueue) return 0;
    else
    {
        Queue_Node *newNode = (Queue_Node *)malloc(sizeof(Queue_Node));
        if(NULL == newNode) return 0;
        else
        {
            newNode->Next = NULL;
            newNode->Data = Data;
            if(!(myQueue->Rear)) myQueue->Front = newNode;
            else myQueue->Rear->Next = newNode;
            myQueue->Rear = newNode;
            (myQueue->Size)++;
            return 1;
        }
    }
}

boolean pop (Queue *myQueue)
{
    Queue_Node *temp = NULL;
    if(NULL == myQueue) return 0;
    else
    {
        temp = myQueue->Front;
        if (myQueue->Front == myQueue->Rear) {
            myQueue->Front = NULL;
            myQueue->Rear = NULL;
            myQueue->Size = 0;
        }
        else
        {
            myQueue->Front = myQueue->Front->Next;
            (myQueue->Size)--;
        }
        free(temp);
        return 1;
    }
}

Entry Front (Queue *myQueue)
{
    if(NULL == myQueue) {}
    else return (myQueue->Front->Data);
}

Entry Back (Queue *myQueue)
{
    if(NULL == myQueue) {}
    else return (myQueue->Rear->Data);
}

unsigned int Size (Queue *myQueue)
{
    if(NULL == myQueue) {}
    else return (myQueue->Size);
}

boolean print(Queue *myQueue)
{
    Queue_Node *Traversing = NULL;
    if(NULL == myQueue) {}
    else {
        Traversing = myQueue->Front;
        while(Traversing)
        {
            printf("%d\t",Traversing->Data);
            Traversing = Traversing->Next;
        }
        return 1;
    }
}
