#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    struct node *newn = NULL;

    newn = (struct node*)malloc(sizeof(struct node));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;   
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = temp->next;
        free(temp);
    }

}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


void Display(struct node *first)
{
    while (first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");

}

int Count(struct node *first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iSize = 0, iCnt = 0;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize+1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }       

        newn->next = temp->next;
        temp->next = newn;
    }
}
void DeleteAtPos(PPNODE first, int pos)
{
    PNODE temp = NULL;
    PNODE target= NULL;
   
    int iSize = 0, iCnt = 0;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        target = NULL;

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }       

        target = temp->next;

        temp->next = target->next;
        free(target);
    }
}


int main()
{
    struct node *head = NULL;
    int iRet = 0;
    
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);
    
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,112);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    InsertAtPos(&head,105,1);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    InsertAtPos(&head,105,6);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    InsertAtPos(&head,105,3);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);

    DeleteAtPos(&head,7);
    Display(head);
    iRet = Count(head);
    printf("Total nodes are %d\n",iRet);


    return 0;
}