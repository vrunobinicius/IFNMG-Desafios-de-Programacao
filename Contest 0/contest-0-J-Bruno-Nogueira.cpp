// https://vjudge.net/contest/706892#problem/J

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int w, d, h;
        cin >> w >> d >> h;

        int a, b, f, g;
        cin >> a >> b >> f >> g;

        int cableOnFloorMin = min(a, b);
        int cableOnCeilingMin = min(f, g);
        int cableOnWallMin = h;

        cout << "cableOnFloorMin: " << cableOnFloorMin << " cableOnWallMin: " << cableOnWallMin << " cableOnCeilingMin: " << cableOnCeilingMin << "\n";
    }

    return 0;
}