#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    // node
    struct node
    {
        char data;
        struct node *next;
    };

    node *head = NULL;
    node *tail = NULL;

    // node insertion at beginning  O(1)
    void push(char value)
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

    char peek()
    {
        return head->data;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
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

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

string InfixToPostfix(string input)
{
    string output;
    Stack *operator_stack = new Stack();

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
            output += input[i];
        else if(input[i]=='(')
            operator_stack->push('(');
        else if(input[i]==')')
        {
            while(operator_stack->peek()!='(')
            {
                output += operator_stack->peek();
                operator_stack->pop();
            }
            operator_stack->pop();
        }
        else
        {
            while (!operator_stack->isEmpty() && (precedence(input[i]) < precedence(operator_stack->peek()) ||
            (precedence(input[i]) == precedence(operator_stack->peek()) && input[i]!='^')) )
            {
                output += operator_stack->peek();
                operator_stack->pop();
            }
            operator_stack->push(input[i]);
        }
    }

    while (!operator_stack->isEmpty())
    {
        output += operator_stack->peek();
        operator_stack->pop();
    }
    return output;
}

int main()
{
    cout<<InfixToPostfix("1+3*5-((5+2)*3^4^2+3)")<<endl;
    return 0;
}
