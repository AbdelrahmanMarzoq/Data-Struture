#include "Double_Linked_List.h"


boolean init(list *myList)
{
    if (NULL == myList) return 0;
    else
    {
        myList->Head = NULL;
        myList->Tail = NULL;
        myList->Size = 0;
    }
}

boolean push_front(list *myList, Entry Data)
{
    if (NULL == myList) return 0;
    else
    {
        List_node *newNode = (List_node *)malloc(sizeof(List_node));
        if (NULL == newNode) return 0;
        else if (!(myList->Size))
        {
            newNode->Next = NULL;
            newNode->Previous = NULL;
            newNode->Data = Data;
            myList->Head = newNode;
            myList->Tail = newNode;
            (myList->Size)++;
            return 1;
        }
        else
        {
            newNode->Data = Data;
            myList->Head->Previous = newNode;
            newNode->Next = myList->Head;
            newNode->Previous = NULL;
            myList->Head = newNode;
            (myList->Size)++;
            return 1;
        }
    }
}

boolean push_back(list *myList, Entry Data)
{
    if(NULL == myList) return 0;
    else
    {
        List_node *newNode = (List_node *)malloc(sizeof(List_node));
        if(NULL == newNode) return 0;
        else if(!(myList->Size))
        {
            newNode->Data = Data;
            newNode->Next = NULL;
            newNode->Previous = NULL;
            myList->Head = newNode;
            myList->Tail = newNode;
            (myList->Size)++;
            return 1;
        }
        else
        {
            newNode->Next = NULL;
            newNode->Data = Data;
            newNode->Previous = myList->Tail;
            myList->Tail->Next = newNode;
            myList->Tail = newNode;
            (myList->Size)++;
            return 1;
        }
    }
}

Entry pop_back(list *myList)
{
    if(NULL == myList) return 0;
    else
    {
        Entry popData;
        List_node *Temp = myList->Tail;
        popData = myList->Tail->Data;
        myList->Tail = myList->Tail->Previous;
        free(Temp);
        (myList->Size)--;
        if(!(myList->Size)) myList->Head = NULL;
        return popData;
    }
}

Entry pop_front(list *myList)
{
    if(NULL == myList) return 0;
    else
    {
        Entry popData;
        List_node *Temp = myList->Head;
        popData = myList->Head->Data;
        myList->Head = myList->Head->Next;
        free(Temp);
        (myList->Size)--;
        if(!(myList->Size)) myList->Tail = NULL;
        return popData;
    }
}

boolean empty(list *myList)
{
    if (NULL == myList) return 0;
    else return (!(myList->Size));
}

Entry back(list *myList)
{
    if(NULL == myList) {}
    else return (myList->Tail->Data);
}

Entry front(list *myList)
{
    if(NULL == myList) {}
    else return (myList->Head->Data);
}

boolean insert(list *myList, Entry Data, unsigned int index)
{
    if (NULL == myList) return 0;
    else
    {
        List_node *newNode = (List_node *)malloc(sizeof(List_node));
        if(NULL == newNode) return 0;
        else
        {
            newNode->Data = Data;
            List_node *Traversing = NULL;
            if(index == (myList->Size))
            {
                if(!(myList->Size))
                {
                    newNode->Next = NULL;
                    newNode->Previous = NULL;
                    myList->Tail = newNode;
                    myList->Head = newNode;
                }
                else
                {
                    Traversing = myList->Tail;
                    newNode->Next = NULL;
                    newNode->Previous = Traversing;
                    Traversing->Next = newNode;
                    myList->Tail = newNode;
                }
                (myList->Size)++;
                return 1;
            }
            else
            {
                Traversing = myList->Head;
                for (unsigned int i = 1; i <= index; i++)
                {
                    Traversing = Traversing->Next;
                }

                if (index) Traversing->Previous->Next = newNode;
                else myList->Head = newNode;
                newNode->Previous = Traversing->Previous;
                newNode->Next = Traversing;
                Traversing->Previous = newNode;
                (myList->Size)++;
                return 1;
            }
        }
    }
}

boolean erase(list *myList)
{
    if (NULL == myList) return 0;
    else
    {
        List_node *Temp = myList->Head;
        while(myList->Head)
        {
            myList->Head = (myList->Head)->Next;
            free(Temp);
            Temp = myList->Head;
        }
        myList->Size = 0;
        myList->Tail = NULL;
        return 1;
    }
}

boolean Delete(list *myList, unsigned int index)
{
    if (NULL == myList) return 0;
    else if (!(index))
    {
        List_node *Temp = myList->Head;
        myList->Head = myList->Head->Next;
        free(Temp);
        (myList->Size)--;
        if (!(myList->Size)) myList->Tail = NULL;
        return 1;
    }
    else
    {
        List_node *Traversing = myList->Head;
        for (unsigned int i = 0; i < index; i++)
        {
            Traversing = Traversing->Next;
        }
        if (index == (myList->Size)-1)
        {
            myList->Tail = Traversing->Previous;
            Traversing->Previous->Next = NULL;
            free(Traversing);
        }
        else
        {
            Traversing->Next->Previous = Traversing->Previous;
            Traversing->Previous->Next = Traversing->Next;
            free(Traversing);
        }
        (myList->Size)--;
        return 1;
    }
}

unsigned int size(list *myList)
{
    if (NULL == myList) {}
    else return (myList->Size);
}

Entry get(list *myList, unsigned int index)
{
    if (NULL == myList) {}
    else
    {
        List_node *Traversing = myList->Head;
        Entry popData;
        for (unsigned int i = 0; i < index; i++)
        {
            Traversing = Traversing->Next;
        }
        popData = Traversing->Data;
        return popData;
    }
}

boolean print_forward(list *myList)
{
    if (NULL == myList) return 0;
    else
    {
        List_node *Traversing = myList->Head;
        while(Traversing)
        {
            printf("%d\t",Traversing->Data);
            Traversing = Traversing->Next;
        }
        printf("\n");
        return 1;
    }
}

boolean print_reverse(list *myList)
{
    if (NULL == myList) return 0;
    else
    {
        List_node *Traversing = myList->Tail;
        while(Traversing)
        {
            printf("%d\t",Traversing->Data);
            Traversing = Traversing->Previous;
        }
        printf("\n");
        return 1;
    }
}
