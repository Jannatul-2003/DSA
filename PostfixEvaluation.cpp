#include <bits/stdc++.h>
using namespace std;

typedef double type;//  to change the type of the stack here

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

double operation(char operate,double a,double b)
{
    if(operate=='+')
        return a+b;
    else if(operate=='-')
        return a-b;
    else if(operate=='*')
        return a*b;
    else if(operate=='/')
        return a/b;
    return pow(a,b);
}


double PostfixEvaluation(string input)
{
    Stack* stack=new Stack();
    double res;
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]>='0' && input[i]<='9')
        stack->push(input[i]-'0');
        else
        {
            double val2=stack->peek();
            stack->pop();
            double val1=stack->peek();
            stack->pop();
            res=operation(input[i],val1,val2);
            stack->push(res);
        }
    }
    return res;
}

int main()
{
    cout<<PostfixEvaluation("231*+9-");
}
