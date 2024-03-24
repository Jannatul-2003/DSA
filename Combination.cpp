#include<bits/stdc++.h> 
using namespace std; 


void combinationUtil(int arr[], int out[], 
					int arr_start, int arr_end, 
					int out_iterator, int out_sz) 
{ 
	
	if (out_iterator == out_sz) 
	{ 
		for (int j = 0; j < out_sz; j++) 
			cout << out[j] << " "; 
		cout << endl; 
		return; 
	} 

	for (int i = arr_start; i <= arr_end && 
		arr_end - i + 1 >= out_sz - out_iterator; i++) 
	{ 
		out[out_iterator] = arr[i]; 
		combinationUtil(arr, out, i+1, 
						arr_end, out_iterator+1,out_sz); 
	} 
} 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5,6,7}; 
	int out_sz = 4; 
	int arr_sz = sizeof(arr)/sizeof(arr[0]); 
    int out[out_sz]; 
	combinationUtil(arr, out, 0, arr_sz-1, 0, out_sz); 
} 

