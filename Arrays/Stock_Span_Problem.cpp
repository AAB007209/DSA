// - Stock Span Problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> v;
        stack<int> s;
        s.push(0);
        v.push_back(1);
        int span;
        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && price[i] >= price[s.top()])
                s.pop();
            span = s.empty() ? i + 1 : i - s.top();
            v.push_back(span);
            s.push(i);
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}