#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    int m = matrix.size();    // row
    int n = matrix[0].size(); // column
    int dir = 0;
    /*
    dir=0 : left to right
    dir=1 :top to bottom
    dir=2 : right to left
    dir=3 :bottom to top
    */
    vector<int> result;
    int top = 0;
    int down = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= down && left <= right)
    {
        if (dir == 0)
        {
            // left to right
            // constant row (top)
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
        }
        if (dir == 1)
        {
            // top to bottom
            // constant column
            for (int i = top; i <= down; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
        }
        if (dir == 2)
        {
            // bottom to top
            // constant column
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[down][i]);
            }
            down--;
        }
        if (dir == 3)
        {
            /*Down to top
            constant col
            */

            for (int i = down; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        dir++;
        if (dir == 4)
        {
            dir = 0;
        }
    }
    return result;
}

int main()
{

    // Matrix initialization.
    vvi mat = {{1, 2, 3, 4},
               {5, 6, 7, 8},
               {9, 10, 11, 12},
               {13, 14, 15, 16}};

    vi spiralMatrix = spiralOrder(mat);
    for (int i = 0; i < spiralMatrix.size(); i++)
    {
        cout<<spiralMatrix[i]<<endl;
    }
    
    return 0;
}