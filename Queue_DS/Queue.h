#ifndef QUEUE_H
#define QUEUE_H

#ifndef NULL
#define NULL 0
#endif

typedef char boolean;
typedef int Entry; //Userdefined

typedef struct Queue_DS
{
    struct Queue_DS *Next;
    Entry Data;
}Queue_Node;

typedef struct
{
    Queue_Node *Front;
    Queue_Node *Rear;
    unsigned int Size;
}Queue;

/**
 @brief      initialize queue (size = 0)  this function must call before execution any functions of the stack
 @param      Address to your queue
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean init (Queue *myQueue);

/**
 @brief      check if the queue is empty or not
 @param      Address to your queue
 @retval     return value of function 0 if isn`t empty || 1 if empty
 @complexity O(1)
*/
boolean Empty (Queue *myQueue);

/**
 @brief      add element to the queue
 @param      Address to your queue & Data of this element
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean push (Queue *myQueue, Entry Data);

/**
 @brief      dequeue element from the front FIFO
 @param      Address to your queue
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean pop (Queue *myQueue);

/**
 @brief      Data at the front of the queue
 @pre        must check if queue empty or not to avoid runtime error
 @param      Address to your queue
 @retval     return the data at front of the queue
 @complexity O(1)
*/
Entry Front (Queue *myQueue);

/**
 @brief      Data at the end of the queue
 @pre        must check if queue empty or not to avoid runtime error
 @param      Address to your queue
 @retval     return the data at the end of the queue
 @complexity O(1)
*/
Entry Back (Queue *myQueue);

/**
 @brief      show the size of the queue
 @param      Address to your queue
 @retval     return the size of the queue
 @complexity O(1)
*/
unsigned int Size (Queue *myQueue);

/**
 @brief      traversing on value of the queue and print it
 @param      Address to your queue
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean print(Queue *myQueue);





#endif // QUEUE
