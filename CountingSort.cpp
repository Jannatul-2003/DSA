#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[],int size)
{
    int max = *max_element(arr,arr+size);
    int min = *min_element(arr,arr+size);
    int range = max - min + 1;
    int count[range] = {0};
    int output[size];
    for(int i = 0; i < size; i++)
    {
        count[arr[i]-min]++;
    }
    for(int i = 1; i < range; i++)
    {
        count[i] += count[i-1];
    }
    for(int i = size-1; i >= 0; i--)
    {
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }
    for(int i=0; i < size; i++)
    {
        arr[i] = output[i];
    }
}