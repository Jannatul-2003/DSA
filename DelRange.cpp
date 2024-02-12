
//08
#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int x)
    {
        //insert x at last

        //Your code starts here #001
        node* new_tail=new node();
        new_tail->next=NULL;
        new_tail->val=x;
        if(!head)
            head=new_tail;
        else
            tail->next=new_tail;
        tail=new_tail;
        
        //Your code ends here #001
    }

    void delete_range(int l, int u){
        // deletes values within the range l and u, inclusive

        //Your code starts here #002
        if(!head)
        return;
        else if(head==tail)
        {
            if(head->val>=l && head->val<=u)
            {
                free(head);
                head=tail=NULL;
                return;
            }
        }
        
        else if(head->val>=l && head->val<=u)
        {
            node* current=head->next;
            free(head);
            head=current;
            delete_range(l,u);
            return;
        }
        
        else
        {
            node* prev=head;
            node* current=prev->next;
            while(current)
            {
                if(current->val>=l && current->val<=u)
                {
                prev->next=current->next;
                free(current);
                current=prev->next;
                if(!current)
                    tail=prev;
                }
                else
                {
                prev=current;
                current=current->next;
                }
            }

        }
        //Your code ends here #002

    }

    void print()
    {
        //prints elements from head to tail

        //Your code starts here #003
        node* temp=head;
        while(temp)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
        //Your code ends here #003
    }
};


int main()
{
    
    //Your code starts here #004
    int n;
    cin>>n;
    ll* list=new ll();
    list->print();
    while(n--)
    {
        //cout<<n<<endl;
        int v;
        cin>>v;
        list->insert_last(v);
        
    }
    int l,u;
    cin>>l>>u;
    list->delete_range(l,u);
    list->print();
        
    //Your code ends here #004
    return 0;


}

