// - Maximum Sum (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximum_sum(int N, vector<int> v, int k)
    {
        unordered_map<int, int> mp;
        int i = 0;
        for (i = 0; i < v.size(); i++)
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = 1;
            }
            else
                mp[v[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto itr : mp)
        {
            pq.push({itr.second, itr.first});
        }
        long ans = 0;
        for (i = 1; i <= k; i++)
        {
            pair<int, int> p = pq.top();
            ans += p.second;
            pq.pop();
            pq.push({p.first - 1, p.second});
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
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution obj;
        cout << obj.maximum_sum(n, v, k) << endl;
    }
    return 0;
}