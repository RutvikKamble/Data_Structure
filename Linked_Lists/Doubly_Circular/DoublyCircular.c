#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    struct node *newn = NULL;

    newn = (struct node*)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
    
    (*last)->next = *first;
    (*first)->prev = *last;
} 

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last;
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

        (*last)->next = *first;
        (*first)->prev = *last;
    }   
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if((*first)->next == *first)
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

        free(*last);
        *last = temp;
        
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void Display(PNODE first, PNODE last)
{   
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else
    {
        printf("<->"); 
        do
        {
            printf("| %d |<->",first->data);
            first = first->next;
        } while(first != last->next);
        printf("\t\t");
    }
}

int Count(struct node *first, PNODE last)
{
    int iCount = 0;
    if(first == NULL)
    {
        return 0;
    }
    else
    {
        do
        {
            iCount++;
            first = first->next;
        }while(first != last->next);  
        
        return iCount;
    }

    
}

void InsertAtPos(PPNODE first,PPNODE last, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iSize = 0, iCnt = 0;

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
        newn = (PNODE)malloc(sizeof(NODE));
        if(newn == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
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
        temp->next->prev = temp;
        free(target);
    }
}


int main()
{
    PNODE head= NULL;
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