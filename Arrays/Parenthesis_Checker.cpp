// - Program to check whether the given bracket sequence is balanced or not.
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        // Pusing the elements into stack
        if (str[i] == '(')
            st.push(str[i]);

        // Popping the elements out
        else
        {
            if (st.empty())
                return 0;
            st.pop();
        }
    }

    // Checking for Balance
    if (!st.empty())
        return 0;
    return 1;
}

int main()
{
    string bracSeq = "(())(())";
    cout << isBalanced(bracSeq);
    return 0;
}