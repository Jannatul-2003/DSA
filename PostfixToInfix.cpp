#include <bits/stdc++.h>
using namespace std;

typedef string type;//  to change the type of the stack here

struct Stack
{
    // node
    struct node
    {
        type data;
        struct node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    // node insertion at beginning  O(1)
    void push(type value)
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

    // node deletion at first O(1)
    void pop()
    {
        if (head == NULL) // no element
            return;
        else if (head == tail) // just one element
        {
            free(head);
            tail = NULL;
            head = NULL;
            return;
        }
        else
        {
            node *temp = head->next;
            free(head);
            head = temp;
            return;
        }
    }

    type peek()
    {
        return head->data;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
    }
};

bool isOperand(char c)
{
    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
        return 1;
    return 0;
}



string PostfixToInfix(string input)
{
    Stack* stack=new Stack();
    for(int i=0; i<input.size(); i++)
    {
        if(isOperand(input[i]))
        {
            string in(1,input[i]);//char to string operation
            stack->push(in);
        }
        else
        {
            type val2=stack->peek();
            stack->pop();
            type val1=stack->peek();
            stack->pop();
            type res=("("+val1+input[i]+val2+")");
            stack->push(res);
        }
    }
    return stack->peek();
}

int main()
{
    cout<<PostfixToInfix("ab*c+");
}
