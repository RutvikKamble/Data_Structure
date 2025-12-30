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

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    struct node *newn = NULL;

    newn = (struct node*)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
    
    (*last)->next = *first;
} 

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
    }
    (*last)->next = *first;
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if((*first)->next == *first)     // (*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        *first = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }

        free(last);
        *last = temp;
        
        (*last)->next = *first;
    }
}

void Display(PNODE first, PNODE last)
{   
    PNODE temp = NULL;

    printf("->"); 
    do
    {
        printf("| %d |->",first->data);
        first = first->next;
    } while(first != last->next);
    printf("\t\t");
}

int Count(struct node *first, PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);   

    return iCount;
}

void InsertAtPos(PPNODE first,PPNODE last, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iSize = 0, iCnt = 0;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    iSize = Count(*first,*last);

    if(pos < 1 || pos > iSize+1)
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first,PPNODE last, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iSize = 0, iCnt = 0;    

    iSize = Count(*first,*last);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Input\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
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
    PNODE tail = NULL;
    int iRet = 0;
    
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);
   
    
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
    Display(head,tail);
    iRet = Count(head,tail);    
    printf("Total nodes are %d\n",iRet);
    
    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);    
    
    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);

    InsertAtPos(&head,&tail,105,1);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);

    InsertAtPos(&head,&tail,105,6);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);
    
    InsertAtPos(&head,&tail,105,3);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);

    DeleteAtPos(&head,&tail,3);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);

    DeleteAtPos(&head,&tail,9);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);
    
    DeleteAtPos(&head,&tail,6);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Total nodes are %d\n",iRet);

    return 0;
}