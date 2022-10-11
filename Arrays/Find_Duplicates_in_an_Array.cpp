// - Find Duplicates in an Array.

#include <bits/stdc++.h>
using namespace std;

//- Below is the one approach (Leetcode)
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (int n : nums)
        {
            n = abs(n);
            if (nums[n - 1] > 0)
                nums[n - 1] *= -1;
            else
                ans.push_back(n);
        }
        return ans;
    }
};

// One more Appraoch (GeeksforGeeks)
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int index = arr[i] % n;
            arr[index] += n;
        }

        for (int i = 0; i < n; i++)
        {
            if ((arr[i] / n) >= 2)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
