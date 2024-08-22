#ifndef PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_H

/** MAX Size of Array to Priority queue */
/** There Option 2 to make Dynamic list and save size*/
#define MAX 100

typedef char boolean;

/** strut you must take object from it to make your priority queue */
typedef struct
{
    int Data[MAX];
    int top;
}priority_queue;


/**
 @brief      Must call this function after taking object from struct
 @param      Take address of your object
 @retval     No Return
 @complexity O(1)
*/
void priority_queue_init(priority_queue *pq);

/**
 @brief      Add data to priority queue
 @param      Take address of your object
 @param      Take Data to store in priority queue
 @retval     No Return
 @complexity O(log(n))
*/
void priority_queue_push(priority_queue *pq, int x);

/**
 @brief      Give you the min element in priority queue and you must check if the array is empty or not
 @param      Take address of your object
 @retval     return the Data in priority
 @complexity O(1)
*/
int priority_queue_top(priority_queue *pq);

/**
 @brief      Delete min element in priority queue and you must check empty or not
 @param      Take address of your object
 @retval     No Return
 @complexity O(log(n))
*/
void priority_queue_pop(priority_queue *pq);

/**
 @brief      check if the priority queue is empty or not
 @param      Take address of your object
 @retval     1 if empty and 0 if not empty
 @complexity O(1)
*/
boolean priority_queue_empty(priority_queue *pq);

#endif
