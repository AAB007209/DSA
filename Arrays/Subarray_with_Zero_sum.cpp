// - Subarray with zero sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        int pre_sum = 0;
        unordered_set<int> s;

        for (int i = 0; i < n; i++)
        {
            pre_sum += arr[i];
            if (pre_sum == 0)
                return true;

            if (s.find(pre_sum) != s.end())
            {
                return true;
            }
            else
                s.insert(pre_sum);
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}