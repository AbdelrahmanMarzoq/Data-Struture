#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#ifndef NULL
#define NULL 0
#endif
#define double_linked_list dll
typedef int Entry;  //user defined
typedef char boolean;  //user defined

typedef struct dll
{
    struct dll *Next;
    struct dll *Previous;
    Entry Data;
}List_node;

typedef struct
{
    List_node *Head;
    List_node *Tail;
    unsigned int Size;
}list;

/**
 @brief      init your list and must call this before any execution any other function
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean init(list *myList);

/**
 @brief      add data at front of list
 @param      address of your list && data will be stored
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean push_front(list *myList, Entry Data);

/**
 @brief      add data at end of list
 @param      address of your list && data will be stored
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(1)
*/
boolean push_back(list *myList, Entry Data);

/**
 @brief      delete data at end of list
 @pre        must check list empty or not
 @param      address of your list
 @retval     return the data at end before deleting it from list
 @complexity O(1)
*/
Entry pop_back(list *myList);

/**
 @brief      delete data at front of list
 @pre        must check list empty or not
 @param      address of your list
 @retval     return the data at front before deleting it from list
 @complexity O(1)
*/
Entry pop_front(list *myList);

/**
 @brief      check the list is empty or not
 @param      address of your list
 @retval     return 1 if the list is empty || 0 if the list isn`t empty
 @complexity O(1)
*/
boolean empty(list *myList);

/**
 @brief      Show you the data at end of list
 @pre        must check list empty or not
 @param      address of your list
 @retval     return the data at end of list
 @complexity O(1)
*/
Entry back(list *myList);

/**
 @brief      Show you the data at front of list
 @pre        must check list empty or not
 @param      address of your list
 @retval     return the data at front of list
 @complexity O(1)
*/
Entry front(list *myList);

/**
 @brief      adding data in list
 @pre        at empty list you have to add in index 0 otherwise your index (0 -> Size list)
 @param      address of your list && data will be stored && target index
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean insert(list *myList, Entry Data, unsigned int index);

/**
 @brief      deleting all data in list
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean erase(list *myList);

/**
 @brief      delete data from target index
 @pre        must check list empty or not && index must in range ( 0 -> (Size list - 1) )
 @param      address of your list && your target index
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean Delete(list *myList, unsigned int index);

/**
 @brief      show the size of list
 @param      address of your list
 @retval     return the address of your list
 @complexity O(1)
*/
unsigned int size(list *myList);

/**
 @brief      show the data at target index
 @pre        must check empty or not && index must be in range ( 0 -> (Size list) - 1 )
 @param      address of your list and your target index
 @retval     return the data at your target index
 @complexity O(n)
*/
Entry get(list *myList,unsigned int index);

/**
 @brief      print data from Front to Tail
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean print_forward(list *myList);

/**
 @brief      print data from Tail to Front
 @param      address of your list
 @retval     return status of function 0 if failed || 1 if success
 @complexity O(n)
*/
boolean print_reverse(list *myList);

#endif // DOUBLE_LINKED_LIST_H
