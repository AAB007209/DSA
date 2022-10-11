// - Parties and Seats - Easy GFG problem (learnt inbuilt *max_element function)

#include <bits/stdc++.h>
using namespace std;

void Election2019(char party[], int seats[], int n)
{
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[party[i]] = seats[i];
    }

    auto pr = *max_element(mp.begin(), mp.end(), [](const auto &x, const auto &y)
                           { return x.second < y.second; });

    for (auto x : mp)
    {
        cout << x.first << " " << x.second << "\n";
    }
    cout << pr.second << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char party[n];
        int seats[n];
        for (int i = 0; i < n; i++)
            cin >> party[i];

        for (int i = 0; i < n; i++)
            cin >> seats[i];

        Election2019(party, seats, n);
    }
}