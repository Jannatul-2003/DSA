#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int high)
{
    int mid = (low+high)/2;
    int lft_arr_sz = mid-low+1;
    int rht_arr_sz = high-mid;
    int left[lft_arr_sz],right[rht_arr_sz];
    for(int i=0;i<lft_arr_sz;i++)
    {
        left[i] = arr[low+i];
    }
    for(int i=0;i<rht_arr_sz;i++)
    {
        right[i] = arr[mid+1+i];
    }
    int lft_iterator=0,rht_iterator=0,main_arr_iterator=low;
    while(lft_iterator<lft_arr_sz && rht_iterator<rht_arr_sz)
    {
        if(left[lft_iterator]<=right[rht_iterator])
        {
            arr[main_arr_iterator] = left[lft_iterator];
            lft_iterator++;
        }
        else
        {
            arr[main_arr_iterator] = right[rht_iterator];
            rht_iterator++;
        }
        main_arr_iterator++;
    }
    while(lft_iterator<lft_arr_sz)
    {
        arr[main_arr_iterator] = left[lft_iterator];
        lft_iterator++;
        main_arr_iterator++;
    }
    while(rht_iterator<rht_arr_sz)
    {
        arr[main_arr_iterator] = right[rht_iterator];
        rht_iterator++;
        main_arr_iterator++;
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high);
    }
    return;
}
// space complexity: O (n +log2n)=O (n). n for the auxiliary array and log2n for the stack space. and time complexity: O(nlog n)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}