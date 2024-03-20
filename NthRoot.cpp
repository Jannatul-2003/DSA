#include <bits/stdc++.h>
using namespace std;

void nthRoot(int n, int number)
{
    double low = 1, high = number;
    double epsilon = 0.0000001;
    double mid = (low + high) / 2;
    while (abs(pow(mid, n) - number) >= epsilon)
    {
        if (pow(mid, n) > number)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        mid = (low + high) / 2;
    }
    cout << "The " << n << "th root of " << number << " is " << mid << endl;
}

void nth_root_recursive(int n, int number, double low, double high)
{
    double epsilon = 0.0000001;
    double mid = (low + high) / 2;
    if (abs(pow(mid, n) - number) < epsilon)
    {
        cout << "The " << n << "th root of " << number << " is " << mid << endl;
        return;
    }
    if (pow(mid, n) > number)
    {
        nth_root_recursive(n, number, low, mid);
    }
    else
    {
        nth_root_recursive(n, number, mid, high);
    }
}

int main()
{
    int n, number;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the number: ";
    cin >> number;
    nthRoot(n, number);
    nth_root_recursive(n, number, 1, number);
    return 0;
}