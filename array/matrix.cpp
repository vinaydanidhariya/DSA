#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void inputMatrix()
{
    int m = 0;
    int n = 0;
    cin >> m;
    cin >> n;
}
vector<int> findMatrix(vector<vector<int>> v, int ele)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == ele)
            {
                return {i, j};
            }
        }
    }
    return {0, 0};
}
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

vector<vector<int>> transposeMatrix(vector<vector<int>> m)
{
    vector<vector<int>> temp(m[0].size(), vector<int>(m.size()));
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            temp[j][i] = m[i][j];
        }
    }
    return temp;
}

void printMatrix(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j];
        }
        cout << "\n";
    }
}
vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {

                for (int k = 0; k < cols; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1000;
                }

                for (int m = 0; m < rows; m++)
                {
                    if (matrix[m][j] != 0)
                        matrix[m][j] = -1000;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1000)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}


v

int main()
{
    // m n
    // vector<vector<int>> matrix(n, vector<int>(n, 2));

    // write fun create matrix

    // [
    //  [ 1, 2, 3 ]
    //  [4, 5, 6]
    // ]
    // 2 *3

    // find element in matrix
    // vector<vector<int>> m2 = {{1, 2, 3},
    //                           {4, 5, 6},
    //                           {7, 8, 9}};
    
    vector<vector<int>> m = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<vector<int>> mNew = transposeMatrix(m);

    // setZeroes(&m);
    printMatrix(mNew);
    return 0;
}
