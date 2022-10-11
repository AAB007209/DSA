// - Sorting Elements of an Array by Frequency (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
    vector<int> sortByFreq(int arr[], int n)
    {
        map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int s = mp.size();
        pair<int, int> p[s];

        int i = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            p[i++] = make_pair(it->first, it->second);
        }

        sort(p, p + s, compare);

        for (int i = 0; i < s; i++)
        {
            int freq = p[i].second;
            while (freq--)
            {
                v.push_back(p[i].first);
            }
        }
        return v;
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

        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(a, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}