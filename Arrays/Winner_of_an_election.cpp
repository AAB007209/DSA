// - Winner of an election (easy)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> winner(string arr[], int n)
    {
        //, Below commented is my solution.
        // map<string, int> mp;
        // for(int i=0; i<n; i++)
        // {
        //     mp[arr[i]]++;
        // }

        // auto pr = *max_element(mp.begin(), mp.end(), [](const auto &x, const auto &y)
        //                   { return x.second < y.second; });

        // string ans = pr.first;
        // string res = to_string(pr.second);
        // return {ans, res};

        vector<string> ans;
        string s;
        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int maxi = INT_MIN;
        for (auto i : mp)
        {
            if (maxi < i.second)
            {
                maxi = i.second;
                s = i.first;
            }
        }
        ans.push_back(s);
        ans.push_back(to_string(maxi));
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}