#include <iostream>
#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
vector<long> v(n + 1);
    for (int i = 0; i < queries.size(); i++) {
        v[queries[i][0] - 1] += queries[i][2];
        v[queries[i][1]] -= queries[i][2];
    }

    long sum = 0;
    long maxSum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        maxSum = std::max(maxSum, sum);
    }

    return maxSum;
}