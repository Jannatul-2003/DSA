#include <bits/stdc++.h>
using namespace std;

//#define INT_MAX 2147483647

struct Heap{
    int arr[10000];
    int size=0;

    void insert(int x){
        arr[size]=x;
        size++;
        
        int current=size-1;
        while(current>0 && arr[current]>arr[(current-1)/2]){//max heap; swap if child is greater than parent
            int temp=arr[current];
            arr[current]=arr[(current-1)/2];
            arr[(current-1)/2]=temp;

            current=(current-1)/2;//move to parent
        }
    }

    int extract_max()
    {
        int ret=arr[0];

        arr[0]=arr[size-1];//replace root with rightmost leaf
        size--;

        int current=0;
        while(current<size)
        {
            int left=current*2+1;
            int right=current*2+2;
            int largest_child_index=-1;

            if(left<size) largest_child_index=left;
            if(right<size && arr[right]>arr[left]) largest_child_index=right;
            
            if(largest_child_index==-1) break;//no children
            if(arr[current]>arr[largest_child_index]) break;//parent is greater than children

            int temp=arr[current];//swap parent with largest child
            arr[current]=arr[largest_child_index];
            arr[largest_child_index]=temp;

            current=largest_child_index;
        }
        return ret;
    }
};

int main(){
    //Heap Sort O(nlogn)
    Heap* heap=new Heap();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heap->insert(x);
    }
    for(int i=0;i<n;i++){
        cout<<heap->extract_max()<<endl;//descending order of elements
    }

    return 0;
}
// Output:    10
//         3     4
//       1  2
//10 3 4 1 2
//0 1 2 3 4
// 1*2+1=3
//1*2+2=4
// Output:    10
//         3     9
//       1  2  4   12
//10 3 9 1 2 4 12
//0 1 2 3 4  5  6
// current=6
//arr[current]=12
//(current-1)/2=2
//arr[(current-1)/2]=9
