#include <bits/stdc++.h>
using namespace std;

void permutation(string str, char arr[], int l)//creates prblem if arr is passed as a string
{
    if (l == str.size())
    {
        for (int i = 0; i < l; i++)
            cout << arr[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        int flag = 0;
        for (int j = l; j >= 0; j--)
        {
            if (str[i] == arr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        arr[l] = str[i];
        permutation(str, arr, l + 1);
    }
}

int main()
{
    string a;
    cout << "Enter a string : ";
    cin >> a;
    char arr[1000];
    cout << "Permutations are : " << endl;
    permutation(a, arr, 0);
    return 0;
}