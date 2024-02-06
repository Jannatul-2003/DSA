#include <bits/stdc++.h>
using namespace std;

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
        if (head == NULL)
            tail = NewFirst; // In case of empty list the new list will have same head and tail
        else
            NewFirst->next = head;
        head = NewFirst;
    }

    // node insertion at last  O(1)
    void push_back(int value)
    {
        node *NewTail = new node();
        NewTail->data = value;
        NewTail->next = NULL;
        if (tail != NULL)
            tail->next = NewTail;

        else
            head = NewTail; // no element on the list
        tail = NewTail;
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

    // sort the ll
    void sort()
    {
        if (!head)
            return; // no element on the list
        else if (head == tail)
            return; // just one element on the list
        else
        {
            node *current = head; // bubble sort
            while (current->next) // first loop for i
            {
                node *nxt = current->next;
                while (nxt) // second loop for j
                {
                    if (current->data > nxt->data)
                    {
                        int temp = current->data; // swap
                        current->data = nxt->data;
                        nxt->data = temp;
                    }
                    nxt = nxt->next;
                }
                current = current->next;
            }
        }
    }

    // insert at intermediate position
    void insert(int value, int position)
    {
        node *newNode = new node();
        newNode->data = value;
        newNode->next = NULL;
        node *temp = head;
        position--;
        while (position != 1)
        {
            temp = temp->next;
            position--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete in the range
    void delRange(int l, int u)
    {
        if (!head)
            return;
        else if (head == tail)
        {
            if (head->data >= l && head->data <= u)
            {
                free(head);
                head = tail = NULL;
                return;
            }
        }
        else if (head->data >= l && head->data <= u)
        {
            node *temp = head;
            head = head->next;
            free(temp);
            delRange(l, u);
            return;
        }

        else
        {
            node *prev = head;
            node *current = prev->next;
            while (current)
            {
                if (current->data >= l && current->data <= u)
                {
                    prev->next = current->next;
                    free(current);
                    if (current == tail)
                    {
                        tail = prev;
                        return;
                    }
                    current = prev->next;
                }
                else
                {
                    prev = prev->next;
                    current = current->next;
                }
            }
        }
    }
    // delete first occurance of x
    int delFirst(int val)
    {
        int position = 1;
        node *temp = NULL;
        if (head == NULL) // no element on the list
            return INT16_MIN;
        temp = head;
        if (temp->data == val)
        {
            pop_front();
            return 1;
        }
        while (temp)
        {
            position++;
            if (temp->next->data == val)
            {
                node *tofree = temp->next;
                temp->next = temp->next->next;
                free(tofree);
                if (temp->next == NULL)
                    tail = temp; // tail update
                break;
            }
            temp = temp->next;
        }
        return position;
    }

    // reverse linked list O(n)
    void reverse()
    {
        tail = head;
        node *prev = NULL;
        node *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
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
    list->pop_front();        // one elemnet pop front
    list->push_front(14);
    //
    int t = 6, i = 7;
    while (t--)
        list->push_front(i++);

    //
    list->push_back(11);
    list->insert(13, 2);
    cout << "The list:\n";
    x = list->printList();
    cout << "Total num of elements:" << x << endl;

    list->delRange(8, 11);
    cout << "The list after delRange:" << endl;
    x = list->printList();

    list->sort();
    cout << "Sorted list:" << endl;
    x = list->printList();

    int pos = list->delFirst(13);
    cout << "The list:" << endl;
    x = list->printList();
    cout << "Poistion of the number that was deleted:" << pos << endl;
    list->reverse();
    cout << "After reversing:" << endl;
    x = list->printList();
    cout << "Total num of elements:" << x << endl;

    return 0;
}
