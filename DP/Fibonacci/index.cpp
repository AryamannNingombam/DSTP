#include <iostream>
#include <vector>

using namespace std;

int helper(int n, vector<int> &values)
{
    if (values[n] != -1)
        return values[n];

    values[n] = helper(n - 1, values) + helper(n - 2, values);
    return values[n];
}

int get_fibonacci(int n)
{
    vector<int> values(10000, -1);
    for (int i = 0; i < 3; i++)
        values[i] = (i != 0);

    return helper(n, values);
}

int main()
{
    int tests, input;
    cout << "Enter the number of test cases : ";
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cout << "Enter the number : ";
        cin >> input;
        cout << get_fibonacci(input) << '\n';
    }

    return 0;
}
