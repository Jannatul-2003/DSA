#include <bits/stdc++.h>
using namespace std;

struct BST
{
    struct Node
    {
        int data;
        Node *parent, *left, *right;
        Node(int data)
        {
            this->data = data;
            parent = left = right = NULL;
        }
    };
    Node *root = NULL;
    void insert(int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new Node(data);
                        temp->left->parent = temp;
                        return;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new Node(data);
                        temp->right->parent = temp;
                        return;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return root;
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
            root->left->parent = root;
        }
        else
        {
            root->right = insert(root->right, data);
            root->right->parent = root;
        }
        return root;
    }
    void inorder()
    {
        stack<Node *> s;
        Node *temp = root;
        while (temp != NULL || !s.empty())
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder()
    {
        preorder(root);
    }
    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder()
    {
        postorder(root);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void levelorder()
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    void remove(int data)
    {
        Node* current=root;
        Node* parent=NULL;
        //searching for the node to be deleted and its parent
        while(current!=NULL && current->data!=data)
        {
            parent=current;
            if(data<current->data)
                current=current->left;
            else
                current=current->right;
        }
        //if the node is not found
        if(current==NULL)
            return;
        //if the node has no child
        if(current->left==NULL && current->right==NULL)
        {
            if(current!=root)
            {
                if(parent->left==current)
                    parent->left=NULL;
                else
                    parent->right=NULL;
            }
            else
                root=NULL;
            delete current;
        }
        //if the node has one child
        else if(current->left==NULL || current->right==NULL)
        {
            Node* child=(current->left!=NULL)?current->left:current->right;
            if(current!=root)
            {
                if(current==parent->left)
                    parent->left=child;
                else
                    parent->right=child;
            }
            else
                root=child;
            delete current;
        }
        //if the node has two children
        else
        {
            Node* successor=current->right;
            Node* parent_successor=current;
            while(successor->left!=NULL)
            {
                parent_successor=successor;
                successor=successor->left;
            }
            current->data=successor->data;
            if(parent_successor!=current)
                parent_successor->left=successor->right;
            else
                current->right=successor->right;
            delete successor;
        }
    }
    Node *remove(Node *root, int data)
    {
        if (root == NULL)
            return root;
        if (data < root->data)
        {
            root->left = remove(root->left, data);
            return root;
        }
        else if (data > root->data)
        {
            root->right = remove(root->right, data);
            return root;
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = remove(root->right, temp->data);

        }
    }
};