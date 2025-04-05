// https://vjudge.net/contest/706892#problem/H

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x;

    cin >> n >> k >> x;

    vector<int> chores(n);
    for (int i = 0; i < n; i++)
        cin >> chores[i];

    int lastChores = chores.size() - 1;
    while (k--)
    {
        chores[lastChores] = x;
        lastChores--;
    }

    int sum = 0;
    for (int i = 0; i < chores.size(); i++)
        sum += chores[i];

    cout << sum << "\n";

    return 0;
}