#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void magic_square(int n)
{
    vector<vector<int> > square(n, vector<int>(n, 0));  
    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        square[row][col] = num;
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (square[next_row][next_col] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = next_row;
            col = next_col;
        }
    }

    for (const auto& row : square)  
    {
        for (int val : row)
        {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter an odd number for Magic Square: ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Magic Square only works for odd numbers!" << endl;
        return 1;
    }

    magic_square(n);
    return 0;
}
