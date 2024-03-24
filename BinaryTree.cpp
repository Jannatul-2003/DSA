#include <bits/stdc++.h>
using namespace std;

#define type int

struct BinaryTree{
    struct node{
        node* parent;
        type data;
        node* left_child;
        node* right_child;
    };

    node* root=NULL;
    BinaryTree(type val)
    {
        node* newRoot=new node();
        newRoot->data=val;
        newRoot->parent=newRoot->left_child=newRoot->right_child=NULL;
        root=newRoot;
    }
    void addLeftChild(type child,node* parent_node)
    {
        node* LeftChild=new node();
        LeftChild->data=child;
        LeftChild->left_child=LeftChild->right_child=NULL;
        LeftChild->parent=parent_node;
        parent_node->left_child=LeftChild;
    }
    void addRightChild(type child,node* parent_node)
    {
        node* RightChild=new node();
        RightChild->data=child;
        RightChild->left_child=RightChild->right_child=NULL;
        RightChild->parent=parent_node;
        parent_node->right_child=RightChild;
    }
    int countNodes(node* p)
    {
        if(!p)
            return 0;
        int l=countNodes(p->left_child);
        int r=countNodes(p->right_child);
        return l+r+1;
    }
    void inorder(node* p)
    {
        if(!p)
         return;
        inorder(p->left_child);
        if(countNodes(p)==1)
        cout<<p->data<<endl;
        else
        cout<<p->data<<" ";
        inorder(p->right_child);
    }
    void preorder(node* p)
    {
        if(!p)
         return;
        if(countNodes(p)==1)
        cout<<p->data<<endl;
        else
        cout<<p->data<<" ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
    void postorder(node* p)
    {
        if(!p)
         return;
        postorder(p->left_child);
        postorder(p->right_child);
        if(countNodes(p)==1)
        cout<<p->data<<endl;
        else
        cout<<p->data<<" ";
    }
};

int main()
{
    type n;
    cin>>n;
    BinaryTree* a=new BinaryTree(n);
    BinaryTree::node* p=a->root;
    cout<<"For no left child or right child input -1.To terminate the tree input -2"<<endl;
    cout<<"Left And Right Child is respectively: ";
    cin>>n;
    while(n!=-2)
    {type r;
    cin>>r;
    a->addLeftChild(n,p);
    a->addRightChild(r,p);
        cout<<"Left And Right Child is respectively: ";
        cin>>n;
    p=p->left_child;
    }


}
