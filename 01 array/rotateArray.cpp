#include <iostream>
#include <vector>
#include <map>
#define vi vector<int>
#define vii vector<int, int>
using namespace std;
void printV(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void rotateK(vector<int> v, int k)
{
    int n = v.size();
    vector<int> chunk(k);
    // k=2
    // 1 2 3 4 5 //5-2 = 3

    // 4 5 1 2 3
    // store last chunk
    for (int i = 0; i < k; i++)
    {
        chunk[i] = v[n - k + i];
    }
    printV(chunk);

    // store other
    cout << "\n";
    for (int i = n - 1; i >= k; i--)
    {
        cout << v[i] << " v OF I ";
        cout << "\n";
        cout << v[i - k] << " i-k OF I ";
        cout << "\n";
        v[i] = v[i - k];
    }

    // store in front
    for (int i = 0; i < k; i++)
    {
        v[i] = chunk[i];
    }

    printV(v);
}

// void rotateUsingReverse(vector<int> v, int k)
// {
//     int n = v.size();
//     reverse(v.begin(), v.end() - k);
//     reverse(v.end() - k, v.end());
//     reverse(v.begin(), v.end());
// }

void secondMax(vector<int> v)
{
    int n = v.size();
    int max = v[0];
    int secondMax = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            secondMax = max;
            max = v[i];
        }
        else if (v[i] > secondMax && v[i] != max)
        {
            secondMax = v[i];
        }
    }
    cout << secondMax << " SECOND MAX\n";
}

// void secondMaxOne(vector v){
//     for (int i = 0; i < v.size(); i++)
//     {
//         /* code */
//     }

// }

// void printHashmap(){
//     map<string,vector<string>> crushMap;
//     crushMap["jay"] = {"surbhi"};
//     crushMap.insert("Ronak",{"gita","sampna"});
// }

void countElement()
{
}
// void max(vector<int> v){
//     int max= v[0];
//     for (int x:v){

//     }

// }

// mode

// 1 2 3 1 2 3
//  1 2 3

//  1 1 1 2 3
// 1

vi mode(vi)
{
}

map<int, int> getFrequency(vector<int> v)
{
    int n = v.size();
    map<int, int> counts;

    for (int x : v)
    {
        counts[x]++;
    }

    return counts;
}

void printMap(map<int, int> map)
{
    for (pair<int, int> pkv : map)
    {
        cout << pkv.first << "  :  " << pkv.second << "\n";
    }
}
// return distinct element in vector

// majority element
// void majorityElement(vector<int> v){
//     int majority = v.size()/2;
//     map<int,int> cout = getFrequency(v);
//     for(pair<int,int> pkv:)
// }
// msot ca,aprita
// 3 sum in

// day three

long arrayManipulation()
{
    int n = 10,
        vector<vector<int>> queries = {{1, 5, 3},
                                       {4, 8, 7},
                                       {6, 9, 1}};
    vector<long> v(n + 1);
    for (int i = 0; i < queries.size(); i++)
    {
        v[queries[i][0] - 1] += queries[i][2];
        v[queries[i][1]] -= queries[i][2];
    }

    long sum = 0;
    long maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        maxSum = std::max(maxSum, sum);
    }

    return maxSum;
}

// done
int chalkReplacer(vector<int> &chalk, int k)
{
    long sum = 0;
    for (int i = 0; i < chalk.size(); i++)
    {
        sum += chalk[i];
    }
    k = k % sum;
    for (int i = 0; i < chalk.size(); i++)
    {
        k -= chalk[i];
        if (k < 0)
        {
            return i;
        }
    }

    return 0;
}
int majorityElement(vector<int> &nums)
{
    int count = 1;
    int element;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count++;
        }
        else
        {
            count--;
        }
        element = nums[i];
    }
    int countMajor;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == element)
        {
            countMajor++;
        }
        if (countMajor < nums.size() / 2)
        {
            return element;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 4, 5, 5};
    int k = 2;
    MajorityElementWithMorse(v1);
    // arrayManipulation();

    return 0;
}

// reverse last k elements
// reverse all elements

// 1. https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// 2. https://leetcode.com/problems/two-sum/submissions/
// 3. https://leetcode.com/problems/remove-element/description/
// 4. https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1293824564/
