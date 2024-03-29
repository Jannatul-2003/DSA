#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node* parent;
    node(int value){
        val=value;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};
struct BST{
    node* root=NULL;
    void add_node(int val,node* p){
        if(val>=p->val&&p->right==NULL){
            node* new_node=new node(val);
            p->right=new_node;
            p->right->parent=p;
            return;
        }
        else if(val<p->val&&p->left==NULL){
            node* new_node=new node(val);
            p->left=new_node;
            p->left->parent=p;
            return;
        }
        else if(val>=p->val){
            add_node(val,p->right);
        }
        else{
            add_node(val,p->left);
        }
    }
    BST(int n,int arr[]){
        node* new_node=new node(arr[0]);
        root=new_node;
        for(int i=1;i<n;i++){
            add_node(arr[i],root);
        }
    }
    void In_Order_Traversal(node *p)
    {
        if (!p)
            return;
        In_Order_Traversal(p->left);
        cout << p->val << " ";
        In_Order_Traversal(p->right);
    }
    void Pre_Order_Traversal(node *p)
    {
        if (!p)
            return;
        cout << p->val << " ";
        Pre_Order_Traversal(p->left);
        Pre_Order_Traversal(p->right);
    }
    void Post_Order_Traversal(node *p)
    {
        if (!p)
            return;
        Pre_Order_Traversal(p->left);
        Pre_Order_Traversal(p->right);
        cout << p->val << " ";
    }
    bool find(int val,node* p){
        if(!p)return false;
        if(p->val==val){
            return true;
        }
        else if(val>p->val){
            return find(val,p->right);
        }
        else{
            return find(val,p->left);
        }
    }
};
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    BST* new_BST=new BST(n,arr);
    int q;
    cin>>q;
    while(q--){
        int query;
        cin>>query;
        if(new_BST->find(query,new_BST->root)){
            cout<<"Node is found"<<endl;
        }
        else cout<<"Node not found"<<endl;
    }
    new_BST->In_Order_Traversal(new_BST->root);
    cout<<endl;
    new_BST->Pre_Order_Traversal(new_BST->root);
    cout<<endl;
    new_BST->Post_Order_Traversal(new_BST->root);
    cout<<endl;
    return 0;
}