#include <bits/stdc++.h>
using namespace std;
// 2 4 ^ n
 void validParenthesis1(int openingBrSize, int closeBrSize, string element,
                               vector<string> &output)
{

    if (openingBrSize == 0 && closeBrSize == 0)
    {
        output.push_back(element);
        return;
    }

    if (openingBrSize > 0)
    {
        validParenthesis(openingBrSize - 1, closeBrSize, element + "(",
                         output);
    }
    if (closeBrSize > openingBrSize)
    {
        validParenthesis(openingBrSize, closeBrSize - 1, element + ")",
                         output);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> output;
    validParenthesis(n, n, "", output);
    return output;
}

int main()
{
    vector<string> strings = generateParenthesis(6);
    for (int i = 0; i < strings.size(); i++)
    {
        cout << strings[i];
        cout << "\n";
    }
}
