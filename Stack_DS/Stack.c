#include "Stack.h"




boolean init(stack *myStack)
{
    if(NULL == myStack)
    {
        return 0;
    }
    else
    {
        /** initialization for my stack*/
        myStack->Head = NULL;
        myStack->Size = 0;
        return 1;
    }
}

boolean push(stack *myStack, Entry Data)
{
    /**check pointer if null or not*/
    if(NULL == newNode || NULL == myStack) return 0;
    else
    {
        /** allocate stack node*/
        Stack_node *newNode = (Stack_node *)malloc(sizeof(Stack_node));
        if (NULL == newNode) return 0;
        else
        {
            newNode->Data = Data;
            newNode->Last = myStack->Head;
            myStack->Head = newNode;
            (myStack->Size)++;
            return 1;
        }
    }
}

boolean Empty(stack *myStack)
{
    if(NULL == myStack){}
    else
    {
        return !(myStack->Size);
    }
}

boolean pop(stack *myStack)
{
    Stack_node *temp = NULL;
    if(myStack == NULL) return 0;
    else
    {
        temp = myStack->Head;
        myStack->Head = myStack->Head->Last;
        (myStack->Size)--;
        free(temp);
        return 1;
    }
}

Entry top(stack *myStack)
{
    if(NULL == myStack){}
    else return (myStack->Head->Data);
}

unsigned int Size(stack *myStack)
{
    if(NULL == myStack){}
    else return (myStack->Size);
}

boolean print(stack *myStack)
{
    Stack_node *Traversing = NULL;

    if(NULL == myStack) return 0;
    else
    {
        Traversing = myStack->Head;
        while(Traversing)
        {
            printf("%d\t",Traversing->Data);
            Traversing = Traversing->Last;
        }
        return 1;
    }
}
