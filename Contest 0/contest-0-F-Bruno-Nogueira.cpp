// https://vjudge.net/contest/706892#problem/F

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;

        if ((l1 == l2 && l3 % 2 == 0) ||
            (l1 == l3 && l2 % 2 == 0) ||
            (l2 == l3 && l1 % 2 == 0) ||
            (l1 + l2 == l3) ||
            (l1 + l3 == l2) ||
            (l2 + l3 == l1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}