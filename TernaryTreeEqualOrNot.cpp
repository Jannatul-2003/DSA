#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left_child;
    node* mid_child;
    node *right_child;
    node(int data)
    {
        val = data;
        left_child = mid_child=right_child = NULL;
    }
};
struct Tree{
    node* root= NULL;
    node* buildTree(int lmr, int parent_val,int value, node* cur)
    {
        if(cur==NULL)
        return NULL;
        if(cur->val==parent_val)
        {
            if(lmr==0)
            {
                node* temp = new node(value);
                cur->left_child = temp;
                return NULL;
            }
            else if(lmr==1)
            {
                node* temp = new node(value);
                cur->mid_child = temp;
                return NULL;
            }
            else if(lmr==2)
            {
                node* temp = new node(value);
                cur->right_child = temp;
                return NULL;
            }
            buildTree(lmr, parent_val, value, cur->left_child);
            buildTree(lmr, parent_val, value, cur->mid_child);
            buildTree(lmr, parent_val, value, cur->right_child);
            return cur;
        }
    }
    void In_Order_Traversal(node *p)
    {
        if (!p)
            return;
        In_Order_Traversal(p->left_child);
        In_Order_Traversal(p->mid_child);
        cout << p->val <<endl;
        In_Order_Traversal(p->right_child);
    }

};

bool isEquals(node* root1, node* root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    if(root1==NULL || root2==NULL)//first case handles the case when both are NULL, second case handles the case when one of them is NULL
    return false;
    if(root1->val!=root2->val)
    return false;
    bool b1= isEquals(root1->left_child, root2->left_child);
    bool b2= isEquals(root1->mid_child, root2->mid_child);
    bool b3= isEquals(root1->right_child, root2->right_child);
    bool b= b1 && b2 && b3;
    return b;
}
int main()
{
    int rootVal,n;
    cin>>rootVal>>n;
    Tree t;
    node* root1 = new node(rootVal);
    t.root = root1;
    for(int i=0;i<n;i++)
    {
        int lmr, parent_val, value;
        cin>>lmr>>parent_val>>value;
        t.buildTree(lmr, parent_val, value, root1);
    }
    cin>>rootVal>>n;
    node* root2 = new node(rootVal);
    Tree t2;
    t2.root = root2;
    for(int i=0;i<n;i++)
    {
        int lmr, parent_val, value;
        cin>>lmr>>parent_val>>value;
        t2.buildTree(lmr, parent_val, value, root2);
    }
    cout<<isEquals(root1, root2)<<endl;
    return 0;
}