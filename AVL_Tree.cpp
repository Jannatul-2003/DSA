#include <bits/stdc++.h>
using namespace std;

struct AVL_Tree{
    struct Node{
        int data, height;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right= NULL;
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
        }
        else if(data > node->data){
            node->right = insert(node->right, data);
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
    Node *right_rotate(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    Node *left_rotate(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }
};