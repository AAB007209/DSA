// - Reverse First K elements of Queue.

#include <bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int> res;
    stack<int> st;

    // firstly pushing first K elements of queue to stack
    for (int i = 1; i <= k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // transferring elements from stack to new queue
    for (int i = 1; i <= k; i++)
    {
        res.push(st.top());
        st.pop();
    }

    // transferring remaining elements of old queue to new queue
    while (q.size() != 0)
    {
        res.push(q.front());
        q.pop();
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}