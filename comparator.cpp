#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<string, double> umsd;

umsd populateMarks(umsd &m)
{
    m["vinay"] = 92;
    m["riddhi"] = 90;
    m["parth"] = 84;
    m["krishna"] = 96;
    return m;
}
void printMap(umsd &m)
{
    for (const auto &x : m)
    {
        cout << "KEY : " << x.first << " Value : " << x.second << endl;
    }
}
int main()
{
    umsd map;
    populateMarks(map);
    printMap(map);
}