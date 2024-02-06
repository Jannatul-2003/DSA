#include <bits/stdc++.h>
using namespace std;

typedef char type;

// double linked list
struct DoubleLL
{

    // node
    struct node
    {
        node *prev;
        type data;
        node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    // insert at beginning
    void push(type x)
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
    void enqueue(type x)
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
    type pop()
    {
        if (!head)
            return '\0';

        type x = head->data;
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
    string inp;
    cin >> inp;
    DoubleLL *stack = new DoubleLL();
    int i;
    for (i = 0; i < inp.size() / 2; i++)
        stack->push(inp[i]);

    cout << "Stack:" << endl;
    stack->printList();
    cout << endl;

    DoubleLL *queue = new DoubleLL();
    // cout << endl<< "head:" << queue->head << endl<< "tail:" << queue->tail << endl;
    i = ceil(inp.size() / 2.0);
    while (i < inp.size())
    {
        queue->enqueue(inp[i]);
        i++;
    }
    // cout << endl<< "head:" << queue->head << endl<< "tail:" << queue->tail << endl;
    cout << "Queue:" << endl;
    queue->printList();
    // cout << endl<< "head:" << queue->head << endl<< "tail:" << queue->tail << endl;
    cout << endl;

    while (stack->head)
    {
        if (stack->pop() != queue->pop())
        {
            cout << "Not a palindrome" << endl;
            return 0;
        }
    }
    cout << "A palindrome" << endl;

    return 0;
}
