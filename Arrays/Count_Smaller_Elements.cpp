// - Unable to solve (on GFG Saw an answer and Understood)
//, Some Policy Based Data Structure to be used.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

class Solution
{
public:
    vector<int> constructLowerArray(int *arr, int n)
    {

        vector<int> v;
        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (v.empty())
            {
                v.push_back(arr[i]);
            }
            else
            {
                auto it = lower_bound(v.begin(), v.end(), arr[i]);
                res[i] = distance(v.begin(), it);
                v.insert(it, arr[i]);
            }
        }

        return res;
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
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
