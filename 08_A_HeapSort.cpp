// https://www.hackerrank.com/contests/hw1/challenges/heap-sort/problem
#include <bits/stdc++.h>
using namespace std;

struct Heap_sort
{
    int arr[10000000];
    int size = 0;

    Heap_sort(int n)
    {
        for(int i=0; i<n; i++)
        {
            int v;
            cin>>v;
            insert(v);
        }
        for(int i=0; i<n; i++)
        {
            if(i==0)
                cout<<"[";
            else
                cout<<",";
            cout<<get_min();
            if(i==n-1)
                cout<<"]"<<endl;
        }
    }
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void insert(int v)
    {
        arr[size] = v;
        size++;
        int current = size - 1;
        while (arr[(current - 1) / 2] > arr[current] && current > 0)
        {
            swap(&arr[current],&arr[(current-1)/2]);
            current = (current - 1) / 2;
        }
    }
    int get_min()
    {
        int min = arr[0];
        size--;
        arr[0] = arr[size];
        int current_i = 0;
        while (current_i < size)
        {
            int min_i = -1;
            int left_i = 2 * current_i + 1;
            int right_i = 2 * current_i + 2;
            if (left_i < size)
                min_i = left_i;
            if (right_i < size && arr[left_i] > arr[right_i])
                min_i = right_i;
            if (min_i == -1)
                break;
            if (arr[current_i] < arr[min_i])
                break;
            swap(&arr[min_i],&arr[current_i]);
            current_i = min_i;
        }
        return min;
    }
};

int main()
{
    int n;
    cin >> n;
    new Heap_sort(n);
    return 0;
}