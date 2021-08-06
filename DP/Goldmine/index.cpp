#include <iostream>
#include <vector>

using namespace std;

bool check(int row, int col, int rows, int cols)
{
    return row >= 0 && col >= 0 && row < rows && col < cols;
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> values(n, vector<int>(m, 0));
    int right, top_right, bottom_right;
    for (int col = m - 1; col > -1; col--)
    {
        for (int row = 0; row < n; row++)
        {
            right = check(row, col + 1, n, m) ? values[row][col + 1] : 0;
            top_right = check(row - 1, col + 1, n, m) ? values[row - 1][col - 1] : 0;
            bottom_right = check(row + 1, col + 1, n, m) ? values[row + 1][col + 1] : 0;
            values[row][col] = M[row][col] + max(right, max(top_right, bottom_right));
        }
    };

    int result = -1;
    for (int i = 0; i < n; i++)
        result = max(result, values[i][0]);
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> values(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> values[i][j];
    };
    cout << maxGold(n, m, values);
    return 0;
}