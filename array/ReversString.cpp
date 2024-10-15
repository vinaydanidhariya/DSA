#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    int l = 0;
    int r = s.size() - 1;
    string temp=s;
    // revere4+s(temp.begin(),temp.end());
    while (l < r)
    {
        swap(temp[l],temp[r]);
        l++;
        r--;
    }
    return temp;
}

int main()
{
    string rev=reverseWords("hello world");
    cout<<rev<<"\n";
    return 0;
}