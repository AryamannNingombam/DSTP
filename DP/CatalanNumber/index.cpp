#include <iostream>
#include <vector>

using namespace std;

int calculate_(int left, int right, vector<int> &values)
{
    int num = 0;
    while (left <= right){
        if (left == right){
            num += (values[left++] * values[right--]);
        }else{
            num += values[left++] * values[right--] * 2;
        }
    }


    return num ;
}

int helper(int n, vector<int> &values)
{

    for (int i = 3; i <= n; i++)
        values[i] = calculate_(0, i - 1, values);
    return values[n];
}

int get_catalan(int n)
{
    vector<int> values(10000, -1);
    for (int i = 0; i < 3; i++)
        values[i] = (i == 2) + 1;
    return helper(n, values);
}

int main()
{
    int tests, input;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> input;
        cout << get_catalan(input) << '\n';
    }

    return 0;
}
