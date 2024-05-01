#ifndef STACK_H
#define STACK_H

#ifndef NULL
#define NULL 0
#endif

typedef int Entry; //userDefine
typedef char boolean;

typedef struct stack_node
{
    struct stack_node *Last;
    Entry Data;
}Stack_node;

typedef struct Stack
{
    Stack_node *Head;
    unsigned int Size;
}stack;

/**
 @brief      initialize stack (size = 0)
 @param      Address to your stack
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean init(stack *myStack);

/**
 @brief      add element to the stack
 @param      Address to your stack & Data input stack
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean push(stack *myStack, Entry Data);

/**
 @brief      delete element from the stack
 @pre        must check empty or not to avoid runtime error
 @param      Address to your stack
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean pop(stack *myStack);

/**
 @brief      get the top of the stack
 @pre        must check stack empty or not
 @param      Address to your stack
 @retval     return value  data top of stack
 @complexity O(1)
*/
Entry top(stack *myStack);

/**
 @brief      check empty stack or not
 @pre        must check empty or not to avoid runtime error
 @param      Address to your stack
 @retval     return value of function 0 if stack isn`t empty || 1 if stack is empty
 @complexity O(1)
*/
boolean Empty(stack *myStack);

/**
 @brief      print the date in stack on the screen
 @param      Address to your stack
 @retval     return status of function 0 if failed || 1 if succes
 @complexity O(n)

*/
boolean print(stack *myStack);

/**
 @brief      get the size of stack
 @param      Address to your stack
 @retval     return value of function the size of stack
 @complexity O(1)
*/
unsigned int Size(stack *myStack);

#endif // STACK_H
