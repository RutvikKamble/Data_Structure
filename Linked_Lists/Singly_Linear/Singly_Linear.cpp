// Singly Circular

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;


class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }
            last->next = first;
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else
            {
                last->next = newn;
                last = newn;
            }
            last->next = first;
            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first->next == last->next)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                PNODE temp = NULL;

                temp = first;

                first = first->next;
                last->next = first;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first->next == last->next)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;

                while (temp->next != last)
                {
                    temp = temp->next;
                }
                last = temp;
                delete temp->next;
                temp->next == NULL;
                last->next = first;                
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;
            int iCnt = 0;

            temp = this->first;

            for(iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp->next;
            }
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > iCount+1)
            {
                cout<<"Invalid Input";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }
        
        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Input";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }
                target = temp->next;

                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
};


int main()
{
     SinglyCL obj;
    int iRet = 0;

    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"\t\tNumber of nodes are : "<<iRet<<"\n";


    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"\t\tNumber of nodes are : "<<iRet<<"\n";

    
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"\t\tNumber of nodes are : "<<iRet<<"\n";


    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"\t\tNumber of nodes are : "<<iRet<<"\n";

    
    obj.InsertAtPos(105,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"\t\tNumber of nodes are : "<<iRet<<"\n";

    
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
   

    return 0;

}
