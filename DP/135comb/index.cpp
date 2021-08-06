#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int helper(int n, vector<long> &values)
{

    if (n <= 0)
        return n == 0;
    if (values[n] != -1)
        return values[n];

    values[n] = helper(n - 1, values) + helper(n - 3, values) + helper(n - 5, values);
    return values[n];
}

int getResult(int n)
{
     vector<long> values(10000,-1);
    values[0] = 1;
    values[1] = 1;
    return helper(n, values);
}

int main()
{
    int cases, temp;

    cout << "Enter the number of test cases : ";
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> temp;
        cout << temp << " : " << getResult(temp) << '\n';
    }
    return 0;
}
