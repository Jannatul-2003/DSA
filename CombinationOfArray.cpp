#include <bits/stdc++.h>
using namespace std;

void combination(int arr[], int out_sz, int out[], int iterator_out,int arr_sz)
{
    if (iterator_out == out_sz)
    {
        for (int i = 0; i < out_sz; i++)
        {
            if (i != 0)
                cout << " ";
            cout << out[i];
        }
        cout << endl;
        return;
    }
    //int arr_sz =sizeof(arr) / sizeof(arr[0]);//creates problem as arr is a pointer
    for (int i = 0; i < arr_sz; i++)
    {
        int flag=0;
        for(int j=iterator_out; j>=0; j--)
        {
            if(arr[i]==out[j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            continue;
        out[iterator_out]=arr[i];
        combination(arr,out_sz,out,iterator_out+1,arr_sz);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int out_sz;
    cout<<"Enter combination size : ";
    cin>>out_sz;
    int out[out_sz];
    cout<<"Combinations are : "<<endl;
    combination(arr,out_sz,out,0,n);
    return 0;
}