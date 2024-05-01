#include "Single_Linked_List.h"


boolean init(list *myList)
{
    if(NULL == myList) return 0;
    else
    {
        myList->Head = NULL;
        myList->Size = 0;
        return 1;
    }
}

boolean push_back (list *myList, Entry Data)
{
    Single_List_Node *Traversing = NULL;
    if(NULL == newNode) return 0;
    else if(!(myList->Size))
    {
        Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
        if (NULL == newNode) return 0;
        else
        {
            newNode->Next = NULL;
            newNode->Data = Data;
            myList->Head = newNode;
            (myList->Size)++;
            return 1;
        }
    }
    else
    {
        Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
        if (NULL == newNode) return 0;
        else
        {
            newNode->Next = NULL;
            newNode->Data = Data;
            Traversing = myList->Head;
            while(Traversing->Next) Traversing = Traversing->Next;
            Traversing->Next = newNode;
            (myList->Size)++;
            return 1;
        }
    }
}

boolean push_front (list *myList, Entry Data)
{
    Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
    if(NULL == newNode) return 0;
    else
    {
        Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
        if (NULL == newNode) return 0;
        else
        {
            newNode->Data = Data;
            newNode->Next = myList->Head;
            myList->Head = newNode;
            (myList->Size)++;
            return 1;
        }
    }
}

Entry pop_back (list *myList)
{
    Single_List_Node *Traversing = NULL;
    Single_List_Node *Temp = NULL;
    Entry popData;
    if(NULL == myList) {}
    else if (myList->Size == 1)
    {
        popData = myList->Head->Data;
        free(myList->Head);
        myList->Head = NULL;
        myList->Size = 0;
        return popData;
    }
    else
    {
        Traversing = myList->Head;
        while(Traversing->Next->Next) Traversing = Traversing->Next;
        Temp = Traversing->Next;
        popData = Traversing->Next->Data;
        Traversing->Next = NULL;
        free(Temp);
        (myList->Size)--;
        return popData;
    }
}

Entry pop_front (list *myList)
{
    Entry popData;
    Single_List_Node *Temp = NULL;
    if (NULL == myList) {}
    else if(myList->Size == 1)
    {
        popData = myList->Head->Data;
        free(myList->Head);
        myList->Head = NULL;
        myList->Size = 0;
        return popData;
    }
    else
    {
        popData = myList->Head->Data;
        Temp = myList->Head;
        myList->Head = myList->Head->Next;
        free(Temp);
        (myList->Size)--;
        return popData;
    }
}

boolean empty(list *myList)
{
    if (NULL == myList) {}
    else return !(myList->Size);
}

Entry back (list *myList)
{
    Single_List_Node *Traversing = NULL;
    Entry popData;
    if(NULL == myList) {}
    else
    {
        Traversing = myList->Head;
        while(Traversing->Next) Traversing = Traversing->Next;
        popData = Traversing->Data;
        return popData;
    }
}

Entry front (list *myList)
{
    if (NULL == myList) {}
    else if (myList->Size) return myList->Head->Data;
}

boolean insert (list *myList, Entry Data, unsigned int index)
{
    Single_List_Node *Temp = NULL;
    if (NULL == myList || NULL == newNode) return 0;
    else if (!index)
    {
        Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
        if (NULL == newNode) return 0;
        else
        {
            newNode->Data = Data;
            newNode->Next = myList->Head;
            myList->Head = newNode;
            (myList->Size)++;
            return 1;
        }
    }
    else if (index > 0 && index <= myList->Size)
    {
        Single_List_Node *newNode = (Single_List_Node *)malloc(sizeof(Single_List_Node));
        if (NULL == newNode) return 0;
        else
        {
            Temp = myList->Head;
            newNode->Data = Data;
            for (int i = 1; i < index; i++)
            {
                Temp = Temp->Next;
            }
            newNode->Next = Temp->Next;
            Temp->Next = newNode;
            (myList->Size)++;
            return 1;
        }
    }
}

boolean erase(list *myList)
{
    Single_List_Node *Traversing = NULL;
    Single_List_Node *Temp = NULL;
    if (NULL == myList) return 0;
    else
    {
        Traversing = myList->Head;
        while(Traversing)
        {
            Temp = myList->Head;
            myList->Head = myList->Head->Next;
            free(Temp);
            Traversing = myList->Head;
            (myList->Size)--;
        }
        myList->Head = NULL;
        return 1;
    }
}

boolean Delete(list *myList, unsigned int index)
{
    Single_List_Node *Traversing = NULL;
    Single_List_Node *Temp = NULL;
    if (NULL == myList) return 0;
    else if (!index)
    {
        Temp = myList->Head;
        myList->Head = myList->Head->Next;
        (myList->Size)--;
        free(Temp);
        return 1;
    }
    else if (index > 0 && index < myList->Size)
    {
        Traversing = myList->Head;
        for (unsigned int i = 1; i < index; i++)
        {
            Traversing = Traversing->Next;
        }
        Temp = Traversing->Next;
        Traversing->Next = Traversing->Next->Next;
        (myList->Size)--;
        free(Temp);
        return 1;
    }
}

unsigned int size(list *myList)
{
    if(NULL == myList) {}
    else return (myList->Size);
}

Entry get(list *myList,unsigned int index)
{
    Entry popData;
    Single_List_Node *Traversing = NULL;
    if(NULL == myList) {}
    else if (!index)
    {
        popData = myList->Head->Data;
        return popData;
    }
    else
    {
        Traversing = myList->Head;
        for(unsigned int i = 0; i < index; i++)
        {
            Traversing = Traversing->Next;
        }
        popData = Traversing->Data;
        return popData;
    }
}

boolean print(list *myList)
{
    Single_List_Node *Traversing = NULL;
    if (NULL == myList) return 0;
    else
    {
        Traversing = myList->Head;
        while(Traversing)
        {
            printf("%d\t",Traversing->Data);
            Traversing = Traversing->Next;
        }
        return 1;
    }
}
