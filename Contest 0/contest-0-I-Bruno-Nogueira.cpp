#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int i = -1, j, k;

        while (true)
        {
            i += 1;
            j = i + 1;
            k = j + 1;
            if (i >= p.size() || j >= p.size() || k >= p.size())
            {
                cout << "NO" << "\n";
                break;
            }
            if (p[i] < p[j] && p[j] > p[k])
            {
                cout << "YES" << "\n";
                cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}