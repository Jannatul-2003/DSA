#include <bits/stdc++.h>
using namespace std;

void BinarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = high+(low - high) / 2;
        if (arr[mid] == x) {
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
}
//space complexity: O(1) and time complexity: O(log n)

void BinarySearchRecursive(int arr[], int low, int high, int x) {
    if (low > high) {
        cout << "Element not found" << endl;
        return;
    }
    int mid = high+(low - high) / 2;
    if (arr[mid] == x) {
        cout << "Element found at index " << mid << endl;
        return;
    }
    else if (arr[mid] < x) {
        BinarySearchRecursive(arr, mid + 1, high, x);
    }
    else {
        BinarySearchRecursive(arr, low, mid - 1, x);
    }
}
//space complexity: O(log n) and time complexity: O(log n)

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;
    sort(arr, arr + n);
    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BinarySearch(arr, n, x);
    BinarySearchRecursive(arr, 0, n - 1, x);
    return 0;
}
