// https://www.hackerrank.com/challenges/qheap1/problem
#include <bits/stdc++.h>
using namespace std;

struct Heap_sort
{
    int arr[10000000];
    int size = 0;

    Heap_sort(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int operation;
            cin >> operation;
            if (operation == 1)
            {
                int v;
                cin >> v;
                insert(v);
            }
            else if (operation == 2)
            {
                int x;
                cin >> x;
                del(x);
            }
            else if (operation == 3)
            {
                get_min();
            }
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
            swap(&arr[current], &arr[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    void del(int x)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (arr[i] == x)
                break;
        }
        size--;
        swap(&arr[i], &arr[size]);
        int current_i = i;
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
            swap(&arr[min_i], &arr[current_i]);
            current_i = min_i;
        }
    }
    void get_min()
    {
        cout << arr[0] << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    new Heap_sort(n);
    return 0;
}