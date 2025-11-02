// Given a matrix, print the matrix in spiral order

#include <iostream>
#include <vector>
using namespace std;

void spiral_traverse(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    int top = 0, bottom = m-1, left = 0, right = n-1;

    while (left <= right && top <= bottom)
    {
        // Print top row
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;

        // Print rightmost column
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            // Print bottom row
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            // Print leftmost column
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    spiral_traverse(arr);

    return 0;
}