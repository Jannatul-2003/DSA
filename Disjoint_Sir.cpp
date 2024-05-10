#include <bits/stdc++.h>
using namespace std;

//#define INT_MAX 2147483647

int parent[1000000];
int Rank[10000000]={0};
int nodeNo[1000000]={1};

int find_set(int i)//returns the root of the set in which i is present
{
    if(parent[i] == i)
        return i;
    int root=find_set(parent[i]);
    parent[i]=root;//path compression
    return root; 
}

int find(int i, int j)
{
    int root_of_i=find_set(i);
    int root_of_j=find_set(j);
    if(root_of_i==root_of_j)
        return 1;
    return 0;
}

void unoin_set(int i, int j)
{
    int root_of_i=find_set(i);
    int root_of_j=find_set(j);
    if(root_of_i==root_of_j)
        return;
    if(Rank[root_of_i]<Rank[root_of_j])
    {
        nodeNo[root_of_j]+=nodeNo[root_of_i];//size[root_of_tree_with_higher_depth]+=size[root_of_tree_with_lower_depth
        parent[root_of_i]=root_of_j;//parent[root_of_tree_with_lower_depth]=root_of_tree_with_higher_depth; 
    }
    else if(Rank[root_of_i]>Rank[root_of_j])
    {
        nodeNo[root_of_i]+=nodeNo[root_of_j];//size[root_of_tree_with_higher_depth]+=size[root_of_tree_with_lower_depth
        parent[root_of_j]=root_of_i;//parent[root_of_tree_with_lower_depth]=root_of_tree_with_higher_depth; 
    }
    else if(Rank[root_of_i]==Rank[root_of_j])
    {
        int size1=nodeNo[root_of_i];
        int size2=nodeNo[root_of_j];
        if(size1>size2)
        {
            nodeNo[root_of_i]+=nodeNo[root_of_j];
            parent[root_of_j]=root_of_i;
            Rank[root_of_i]++;
        }
        else
        {
            nodeNo[root_of_j]+=nodeNo[root_of_i];
            parent[root_of_i]=root_of_j;
            Rank[root_of_j]++;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    cout<<find(0, 1)<<endl;
    unoin_set(2,3);
    unoin_set(1, 4);
    unoin_set(3, 4);
    unoin_set(6,8);
    cout<<find(1,3)<<endl;
    cout<<find(2, 4)<<endl;
    cout<<find(6, 4)<<endl;
    return 0;
}
/*      
6        6
|    /  |  \
7   7   8   9 o(1)   
|
8   first time running e O(n) hoi. ekbar chalale path compression er karon e O(1) hoye jabe. 
|   avg complexity O(logn) hoye jabe. O(n) worst case e hobe.//kom heigh er tree er parent beahi height er tree er parent hobe
9 o(n)*/