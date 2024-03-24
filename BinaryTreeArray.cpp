#include <bits/stdc++.h>
using namespace std;

#define type int
#define max 1000
struct BinaryTree
{
    type arr[max];
    BinaryTree(type arr[],int sz)
    {
        for(int i=0; i<sz; i++)
        this->arr[i]=arr[i];
    }
    type get_root()
    {
        return arr[0];
    }

    type get_left_child(int pos)
    {
        return arr[2*pos+1];
    }

    type get_right_child(int pos)
    {
        return arr[2*pos+2];
    }

    type get_parent(int pos)
    {
        return arr[(int)((pos-1)/2)];
    }
};

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    BinaryTree *tree=new BinaryTree(arr,n);
    cout<<"Root is : "<<tree->get_root()<<endl;
    cout<<"Left child of index :";
    cin>>n;
    cout<<" is "<<tree->get_left_child(n)<<endl;
    cout<<"Right child of index :";
    cin>>n;
    cout<<" is "<<tree->get_right_child(n)<<endl;
    cout<<"Parent node of index :";
    cin>>n;
    cout<<" is "<<tree->get_parent(n)<<endl;
}