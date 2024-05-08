#include <bits/stdc++.h>
using namespace std;

struct Disjoint_Set
{
    struct Node
    {
        int data, rank;
        Node *parent;
        Node(int data)
        {
            this->data = data;
            parent = this;
            rank = 0;
        }
    };
    unordered_map<int, Node *> mp;
    void make_set(int data)
    {
        if (mp.find(data) == mp.end())
        {
            Node *temp = new Node(data);
            mp[data] = temp;
        }
    }
    Node *find_set(Node *node)
    {
        if (node == node->parent)
            return node;
        node->parent = find_set(node->parent);
        return node->parent;
    }
    void union_set(int data1, int data2)
    {
        Node *node1 = mp[data1];
        Node *node2 = mp[data2];
        Node *parent1 = find_set(node1);
        Node *parent2 = find_set(node2);
        if (parent1 == parent2)
            return;
        if (parent1->rank >= parent2->rank)
        {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
    }
};
int main()
{
    Disjoint_Set* ds=new Disjoint_Set();
    ds->make_set(0);
    ds->make_set(1);
    ds->make_set(2);
    ds->make_set(3);
    ds->make_set(4);
    ds->make_set(5);
    ds->make_set(6);
    ds->make_set(7);
    ds->make_set(8);
    ds->make_set(9);
    cout << ds->find_set(ds->mp[0])->data << endl;
    ds->union_set(2, 3);
    ds->union_set(1, 4);
    ds->union_set(3, 4);
    ds->union_set(6, 8);
    cout << ds->find_set(ds->mp[1])->data << endl;
    cout << ds->find_set(ds->mp[2])->data << endl;
    cout << ds->find_set(ds->mp[6])->data << endl;
    return 0;
}