// - Previous greater element - Stacks

#include <bits/stdc++.h>
using namespace std;

vector<int> prevGreater(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> s;
    s.push(arr[0]);

    ans.push_back(-1);

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() < arr[i])
            s.pop();

        s.empty() ? ans.push_back(-1) : ans.push_back(s.top());

        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> v = {10, 4, 2, 20, 40, 12, 30};

    vector<int> ans = prevGreater(v, v.size());

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
