// - Function to generate binary numbers from 1 to N using a queue.

#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int N)
{
    vector<string> v;

    queue<string> q;
    q.push("1");
    string s = "";

    for (int i = 0; i < N; i++)
    {
        s = q.front();
        q.pop();
        v.push_back(s);
        q.push(s + "0");
        q.push(s + "1");
    }
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}