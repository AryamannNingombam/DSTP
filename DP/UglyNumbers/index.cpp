#include <iostream>
#include <vector>

using namespace std;

int ugly_number(int n)
{
    vector<long> values(10000, -1);
    values[0] = 1;
    int i2 = 1, i3 = 1, i5 = 1, next_number_two = 2, next_number_three = 3,
        next_number_five = 5;
    int next_number;
    for (int i = 1; i < n; i++)
    {
         next_number = min(next_number_two, 
         min(next_number_three, next_number_five));
        values[i] = next_number;
        if (next_number == next_number_two)
        {

            next_number_two = values[i2++] * (2);
        
        }
        if (next_number == next_number_three)
        {
            next_number_three = values[i3++] * 3;
       
        }
        if (next_number == next_number_five)
        {  
            next_number_five = values[i5++] * 5;
      
        }
    };
    return next_number;
}

int main()
{
    int tests, input;
    cout << "Enter the number of test cases : ";
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> input;
        cout << input << "th ugly number is " << ugly_number(input) << '\n';
    }

    return 0;
}
