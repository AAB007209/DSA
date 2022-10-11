// - Subarray Sum (first last occurence method) (tough)

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum
int maxValue(int a[], int n)
{
    unordered_map<int, int> first, last;
    int pr[n];

    for (int i = 0; i < n; i++)
    {
        // Build prefix sum array
        if (i)
            pr[i] = pr[i - 1] + a[i];
        else
            pr[i] = a[i];
        // If the value hasn't been encountered before,
        // It is the first occurrence
        if (first[a[i]] == 0)
            first[a[i]] = i + 1;

        // Keep updating the last occurrence
        last[a[i]] = i + 1;
    }

    int ans = 0;

    // Find the maximum sum with same first and last value
    for (int i = 0; i < n; i++)
    {
        int start = first[a[i]];
        int end = last[a[i]];
        if (start == 1)
            ans = max(ans, pr[end - 1]);
        else
            ans = max(ans, pr[end - 1] - pr[start - 2]);
    }
    return ans;
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 31, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxValue(arr, n);

    return 0;
}

// - Below is the one more solution to the above problem

// class Solution
// {
// public:
//     long long int maximum_sum(vector<long long int> v)
//     {
//         unordered_map<long long int, long long int> m;

//         long long int res = 0;

//         long long int preSum = 0;
//         long long int current = 0;
//         for (auto &x : v)
//         {
//             preSum += x;
//             if (m.find(x) == m.end())
//             {
//                 current = x;
//                 m[x] = preSum;
//             }
//             else
//             {
//                 current = preSum - m[x] + x;
//             }
//             res = max(res, current);
//         }
//         return res;
//     }
// };