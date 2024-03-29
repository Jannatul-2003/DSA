#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left_child;
    node *right_child;
    node* parent;
    node(int data)
    {
        val=data;
        left_child=right_child=parent=NULL;
    }
};
struct BT
{
    node *root = NULL;
    void add_root(int val)
    {
        node *new_node = new node(val);
        root = new_node;
    }
    void add_child(int parent_val, int child_val, node *p)
    {
        if (p == NULL)
            return;
        if (p->val == parent_val)
        {
            if (p->left_child == NULL)
            {
                node *temp = new node(child_val);
                p->left_child = temp;
                return;
            }
            else if (p->right_child == NULL)
            {
                node *temp = new node(child_val);
                p->right_child = temp;
                return;
            }
        }
            add_child(parent_val, child_val, p->left_child);
            add_child(parent_val, child_val, p->right_child);
            return;
    }
    void In_Order_Traversal(node *p)
    {
        if (!p)
            return;
        In_Order_Traversal(p->left_child);
        cout << p->val << " ";
        In_Order_Traversal(p->right_child);
    }
    void Pre_Order_Traversal(node *p)
    {
        if (!p)
            return;
        cout << p->val << " ";
        Pre_Order_Traversal(p->left_child);
        Pre_Order_Traversal(p->right_child);
    }
    void Post_Order_Traversal(node *p)
    {
        if (!p)
            return;
        Pre_Order_Traversal(p->left_child);
        Pre_Order_Traversal(p->right_child);
        cout << p->val << " ";
    }
};
int main()
{
    int n;
    cin >> n;
    BT *new_BT = new BT();
    for (int i = 1; i < n; i++)
    {
        int parent_val, child_val;
        cin >> parent_val >> child_val;
        if (i == 1)
        {
            new_BT->add_root(parent_val);
            new_BT->add_child(parent_val, child_val, new_BT->root);
        }
        else
        {
            new_BT->add_child(parent_val, child_val, new_BT->root);
        }
        
    }
    cout<<"Inorder Traversal : ";
    new_BT->In_Order_Traversal(new_BT->root);
    cout << endl<<"Pre-order Traversal : ";
    new_BT->Pre_Order_Traversal(new_BT->root);
    cout << endl<<"Post_order Traversal : ";
    new_BT->Post_Order_Traversal(new_BT->root);
    return 0;
}