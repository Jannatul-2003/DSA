#include <bits/stdc++.h>
#include <stdlib.h>

struct singleLinkedList
{
    // node
    struct node
    {
        int data;
        struct node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    // node insertion at beginning  O(1)
    void push_front(int value)
    {
        node *NewFirst = new node();
        NewFirst->next = NULL;
        NewFirst->data = value;
        // NewFirst->next = head;
        if (head == NULL)
        {
            tail = NewFirst; // In case of empty list the new list will have same head and tail
            head = NewFirst;
        }
        else
        {
            NewFirst->next = head;
            head = NewFirst;
        }
    }

    // node insertion at last  O(1)
    void push_back(int value)
    {
        node *NewTail = new node();
        NewTail->data = value;
        NewTail->next = NULL;
        if (tail != NULL)
        {
            tail->next = NewTail;
            tail = NewTail;
        }
        else
        {
            head = NewTail; // no element on the list
            tail = NewTail;
        }
    }

    // node deletion at first O(1)
    int pop_front()
    {
        if (head == NULL) // no element
            return INT16_MIN;
        else if (head == tail) // just one element
        {
            int val = head->data;
            tail = NULL;
            head = NULL;
            return val;
        }
        else
        {
            int val = head->data;
            node *temp = head->next;
            free(head);
            head = temp;
            return val;
        }
    }

    // node deletion at last O(n)
    int pop_back()
    {
        if (head == NULL)
            return INT16_MIN;
        else if (head == tail)
        {
            int val = head->data;
            free(head);
            head = NULL;
            tail = NULL;
            return val;
        }
        node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        int val = temp->next->data;
        temp->next = NULL;
        free(tail);
        tail = temp;
        return val;
    }
    // insert at intermediate position
    void insert(int value, int position)
    {
        // if(position==1)
        // return push_front(value);
        node *newNode = new node();
        newNode->data = value;
        newNode->next = NULL;
        node *temp = head;
        position--;
        while (position!=1)
        {
            temp = temp->next;
            position--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        
    }

    // reverse linked list O(n)
    void reverse()
    {
        //tail = NULL;
        tail = head;
        node *temp = NULL;
        node *temp2 = NULL;
        while (head!= NULL)
        {
            temp2 = head->next;
            head->next = temp;
            temp=head;
            head = temp2;
        }
        head=temp;

    }
    // print the data of ll also returns the total num of data O(n)
    int printList()
    {
        int numOfData = 0;
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            numOfData++;
        }
        printf("\n");
        return numOfData;
    }
};

int main()
{
    singleLinkedList *list = new singleLinkedList();

    list->push_front(12);     // no element push front
    int x = list->pop_back(); // one element pop back
    list->push_back(x);       // no element push back
    list->pop_front();    // one elemnet pop front
    list->push_front(14);
    list->push_back(11);
    list->insert(13, 2);
    x=list->printList();
    printf("Total num of elemnts:%d\n", x);
    list->reverse();
    printf("After reversing:\n");
    x=list->printList();
    printf("Total num of elemnts:%d\n",x);
    return 0;
}