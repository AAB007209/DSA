// - Tie Breaker (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string TieBreak(string names[], int n)
    {
        map<string, int> mp;
        int winner = INT_MIN;
        string ans = "";
        for (int i = 0; i < n; i++)
            mp[names[i]]++;

        for (auto &x : mp)
        {
            if (x.second > winner)
            {
                ans = x.first;
                winner = x.second;
            }
        }
        return ans;
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

        string names[n];
        for (int i = 0; i < n; i++)
            cin >> names[i];
        Solution ob;
        cout << ob.TieBreak(names, n) << endl;
    }
}
