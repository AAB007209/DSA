// - Longest Consecutive Subsequence (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        int ans = 0;
        unordered_set<int> s;
        for (int i = 0; i < N; i++)
        {
            s.insert(arr[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) != s.end())
            {
                continue;
            }
            else
            {
                int count = 0;
                int current = arr[i];
                while (s.find(current) != s.end())
                {
                    count++;
                    current++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}