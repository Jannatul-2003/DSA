#include <bits/stdc++.h>
using namespace std;

typedef int type;
struct CircluarQueue{

    struct Node
    {
        type data;
        Node* next;
    };

    Node* head=NULL;
    Node* tail=NULL;

    void enqueue(type x)
    {
        Node* newNode=new Node();
        newNode->data=x;
        newNode->next=NULL;
        if(!head)
        {
            head=tail=newNode;
            newNode->next=head;//The node.next will point to itself
        }
        else{
            tail->next=newNode;
            tail=newNode;
            newNode->next=head;//The node.next will point to head

        }

    }

    void dequeue()
    {
        if(!head)
            return;
        else if(head==tail)
        {
            free(head);
            head=tail=NULL;
            return;
        }
        Node* temp=head;
        head=head->next;
        free(temp);
        tail->next=head;
    }

    type peek()
    {
        if(head)
        return head->data;
        return INT16_MIN;
    }

    void print()
    {
        Node* temp=head;
        do
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }while(temp!=head);
    
    }
    
};

int main()
{
    CircluarQueue* cq=new CircluarQueue();
    int i=5,p=6;
    while(i--)
    cq->enqueue(p+=2);
    cq->print();
    cout<<endl<<"Head.data="<<cq->peek()<<endl;
    cq->dequeue();
    cq->print();
    cq->dequeue();
    cq->print();
}