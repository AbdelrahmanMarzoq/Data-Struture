#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>

typedef int Entry; //Userdefined

typedef char boolean;

typedef struct single_list
{
    Entry Data;
    struct single_list *Next;
}Single_List_Node;

typedef struct
{
    Single_List_Node *Head;
    unsigned int Size;
}list;

/**
 @brief      initialize list this function must call before any execution any function of list
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean init(list *myList);

/**
 @brief      adding data at end of list
 @param      address of your list && your data
 @retval     c
 @complexity O(n)
*/
boolean push_back (list *myList, Entry Data);

/**
 @brief      adding data at front of list
 @param      address of your list && your data
 @retval     return status of function 0 if failed || 1 if succcess
 @complexity O(1)
*/
boolean push_front (list *myList, Entry Data);

/**
 @brief      deleting element at end of list
 @param      address of your list
 @retval     return the data at end before deleting it
 @complexity O(n)
*/
Entry pop_back (list *myList);

/**
 @brief      deleting element at front of list
 @param      address of your list
 @retval     return the data at front before deleting it
 @complexity O(1)
*/
Entry pop_front (list *myList);

/**
 @brief      check if list is empty or not
 @param      address of your list
 @retval     return 0 if isn`t empty || 1 if is empty
 @complexity O(1)
*/
boolean empty(list *myList);

/**
 @brief      show you data at end of list
 @param      address of your list
 @retval     return data at the end of list
 @complexity O(n)
*/
Entry back (list *myList);

/**
 @brief      show you data at front of list
 @param      address of your list
 @retval     return data at front of list
 @complexity O(1)
*/
Entry front (list *myList);

/**
 @brief      adding data at special index
 @param      address of your list && your data && your target index  index valid ( 0 -> Size list )
 @retval     return status of function 0 if failed || 1 if succcess
 @complexity O(n)
*/
boolean insert (list *myList, Entry Data, unsigned int index);

/**
 @brief      deleting the list
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if succcess
 @complexity O(n)
*/
boolean erase(list *myList);

/**
 @brief      Delete element from special index
 @param      address of your list && you index
 @retval     return status of function 0 if failed || 1 if succcess
 @complexity O(n)
*/
boolean Delete(list *myList, unsigned int index);

/**
 @brief      show you the size of list
 @param      address of your list
 @retval     return value the size of list
 @complexity O(1)
*/
unsigned int size(list *myList);

/**
 @brief      get the data from special index
 @param      address of your list && your index   index valid ( 0 -> (Size list - 1) )
 @retval     return the data at this index
 @complexity O(n)
*/
Entry get(list *myList,unsigned int index);

/**
 @brief      show the data in list at screen
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if succcess
 @complexity O(n)
*/
boolean print(list *myList);

#endif // SINGLE_LINKED_LIST_H
