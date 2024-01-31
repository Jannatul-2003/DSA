#include <bits/stdc++.h>
using namespace std;

// double linked list
struct DoubleLL
{

    // node
    struct node
    {
        node *prev;
        char data;
        node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    // insert at beginning
    void push(char x)
    {
        node *newNode = new node();
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->data = x;
        if (!head)
            tail = newNode;

        else
        {
            head->prev = newNode;
            newNode->next = head;
        }

        head = newNode;
    }

    // insert at end
    void enqueue(char x)
    {
        node *newNode = new node();
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->data = x;
        if (!head)
            head = newNode;

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }

    // deleting first element
    char pop()
    {
        if (!head)
            return '\0';

        char x = head->data;
        if (head == tail)
        {
            free(head);
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            free(head->prev);
            head->prev = NULL;
        }

        return x;
    }

    // deleting last element
    char pop_back()
    {
        if (!head)
            return '\0';
        char x = tail->data;
        if (head == tail)
        {
            free(tail);
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            free(tail->next);
            tail->next = NULL;
        }
        return x;
    }
    //insert value at intermediate position
    void insert(char x, int position)
    {
        node* newNode=new node();
        newNode->data=x;
        newNode->next=newNode->prev=NULL;
        node* temp=head;
        position--;
        while(position!=1)
        {
            temp=temp->next;
            position--;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;
    }

    //reversing the list
    void reverse()
    {
        if(!head || head==tail)
            return;
        node* current=head;
        head=tail;//head tail interchange
        while(current)
        {
            node* temp=current->next;//swap among prev next 
            current->next=current->prev;
            current->prev=temp;
            tail=current;//to update tail
            current=current->prev;//next has beome prev so..
        }
    }
    // printlist
    int printList()
    {
        int numOfData = 0;
        node *temp = head;
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;
            numOfData++;
        }
        return numOfData;
    }
};
int main()
{
    // double ll as stack
    cout << "Stack Implementation:" << endl
         << endl
         << "Push five char:" << endl;
    DoubleLL *stack = new DoubleLL();
    int i = 5;
    while (i--)
    {
        char x;
        cin >> x;
        stack->push(x);
    }

    cout<<"Stack:"<<endl;
    stack->printList();

    cout << endl
         << "After popping:" << endl;
    stack->pop();
    stack->printList();
    cout << endl;

    cout << "After popping back:" << endl;
    stack->pop_back();
    stack->printList();
    cout << endl;
    
    char val;
    int pos;
    cout<<"Insert:";
    cin>>val;
    cout<<"At intermediate position:";
    cin>>pos;
    stack->insert(val,pos);
    cout<<"New stack:"<<endl;
    stack->printList();
    cout << endl;

    cout<<"After reversal:"<<endl;
    stack->reverse();
    stack->printList();
    cout << endl;
    // double ll as queue
    cout << endl
         << "Queue Implementation:" << endl
         << endl
         << "Enqueue five char:" << endl;
    DoubleLL *queue = new DoubleLL();
    i = 5;
    while (i--)
    {
        char x;
        cin >> x;
        queue->enqueue(x);
    }
    cout<<"Queue:"<<endl;
    queue->printList();
    
    cout << endl
         << "After dequeueing:" << endl;
    queue->pop();
    queue->printList();
    cout << endl;

    cout << "After popping back:" << endl;
    queue->pop_back();
    queue->printList();
    cout << endl;

    cout<<"Insert:";
    cin>>val;
    cout<<"At intermediate position:";
    cin>>pos;
    queue->insert(val,pos);
    cout<<"New queue:"<<endl;
    queue->printList();
    cout << endl;
        
    cout<<"After reversal:"<<endl;
    queue->reverse();
    queue->printList();
    cout << endl;
    return 0;
}