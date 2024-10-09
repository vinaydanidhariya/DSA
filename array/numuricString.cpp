#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMagicNumber(string s, int k, int b, int m){
    vector<string> spiltString;
    for (int i = 0; i < s.size(); i++)
    {
        string part;
        for (int i = 0; i < k; i++)
        {
            part.append(s[i]);
            
        }
        spiltString.push_back(part);
    }
    for (int i = 0; i < spiltString.size(); i++){
        cout<<spiltString[i];
    }
    return 0;
}


int main()
{

}