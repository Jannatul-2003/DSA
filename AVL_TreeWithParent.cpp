#include <bits/stdc++.h>
using namespace std;

struct AVL_Tree{
    struct Node{
        int data, height;
        Node *left, *right, *parent;
        Node(int data){
            this->data = data;
            left = right = parent = NULL;
            height = 1;
        }
    };
    Node *root = NULL;
    int height(Node *node){
        if(node == NULL)
            return 0;
        return node->height;
    }

    int balance_factor(Node *node){
        if(node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *insert(Node *node, int data){
        if(node == NULL){
            Node *temp = new Node(data);
            return temp;
        }
        else if(data < node->data){
            node->left = insert(node->left, data);
            node->left->parent = node;
        }
        else if(data > node->data){
            node->right = insert(node->right, data);
            node->right->parent = node;
        }
        //insert on bst finished
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balance_factor(node);
        //left left case
        if(balance > 1 && data < node->left->data){
            return right_rotate(node);
        }

        //right right case
        if(balance < -1 && data > node->right->data){
            return left_rotate(node);
        }

        //left right case
        if(balance > 1 && data > node->left->data){
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        //right left case
        if(balance < -1 && data < node->right->data){
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
        return node;
    }
    void insert(int data){
        if(root == NULL){
            root = new Node(data);
        }
        else{
            Node* temp = root;
            while(temp)
            {
                if(data < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(data);
                        break;
                    }
                    temp = temp->left;
                }
                else if(data > temp->data){
                    if(temp->right == NULL){
                        temp->right = new Node(data);
                        break;
                    }
                    temp = temp->right;
                }
                else{
                    break;
                }            
            }
            if(temp->data>temp->parent->data){
                temp->parent->right = temp;
            }
            else{
                temp->parent->left = temp;
            }
            while(temp!=root)
            {
                temp->height = 1 + max(height(temp->left), height(temp->right));
                int balance = balance_factor(temp);
                //left left case
                if(balance > 1 && data < temp->left->data){
                    temp = right_rotate(temp);
                }

                //right right case
                if(balance < -1 && data > temp->right->data){
                    temp = left_rotate(temp);
                }

                //left right case
                if(balance > 1 && data > temp->left->data){
                    temp->left = left_rotate(temp->left);
                    temp = right_rotate(temp);
                }

                //right left case
                if(balance < -1 && data < temp->right->data){
                    temp->right = right_rotate(temp->right);
                    temp = left_rotate(temp);
                }
                temp = temp->parent;
            
            }
        }
    }
    Node *right_rotate(Node *node){
        Node *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node->height = 1 + max(height(node->left), height(node->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        return temp;
    }
    Node *left_rotate(Node *node){
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + max(height(node->left), height(node->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        return temp;
    }
};