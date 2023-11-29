#include "linkedl.h"
#include <iostream>
using namespace std;

node::node(int r, string b, int bc, string jt, float f)
{
    {
        rollno = r;
        branch = b;
        branch_code = bc;
        job_title = jt;
        ctc = f;
        next = NULL;
    }
}
void sll_insert(node **head, int r, string b, int bc, string jt, float f) 
{
    node *newNode = new node(r, b, bc, jt, f);
    newNode->next = *head;
    *head = newNode;
}
void sll_print(node **head)
{
    if(*head == NULL)
    {
       cout << "Linked list is empty, nothing to print!" << endl;
       return;
    }
   
    node *ptr = *head;
    while(ptr != NULL)
    {
        cout << "Roll no: " << ptr-> rollno << " Role: " << ptr->job_title << " CTC: " << ptr->ctc <<endl;
        ptr = ptr -> next;
    }
    cout << "\n";
}
void sll_delete(node **head, int r, string b, int bc, string jt, float f)
{
    int position = sll_search(head, r, b, bc, jt, f);
    if(position == 0)
    {
        node *temp = (*head) -> next;
        *head = temp;

    }
    else if(position != -1)
    {
       node *ptr = *head;
       for (int i = 1; ptr != NULL && i < position; i++)
       {
           ptr = ptr -> next;
       }
       if((ptr -> next) -> next != NULL)
       {
           node *temp = (ptr -> next) -> next;
           ptr -> next = temp;
           
       }
       else
       {
           node *t = ptr -> next;
           ptr -> next = NULL;
           free(t);
       }
    }
    else
    {
	cout << "The company and role you are looking for does not exist!\n";
    }
}
int sll_search(node **head, int r, string b, int bc, string jt, float f)
{
    int s = 0;
    node *ptr = *head;
    while(ptr != NULL)
    {
        if(ptr -> rollno == r && ptr->job_title == jt)
        {
            return s;
        }
        ptr = ptr -> next;
	s++;
    }
    return -1;
    
}