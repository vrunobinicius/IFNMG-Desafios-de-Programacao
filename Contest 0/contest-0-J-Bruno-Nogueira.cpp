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

        int lengthCableInW = abs(w - a) + h + abs(w - f) + abs(b - g);
        int lengthCableInWReverse = a + h + f + abs(b - g);
        int lengthCableInD = abs(d - b) + h + abs(d - g) + abs(a - f);
        int lengthCableInDReverse = b + h + g + abs(a - f);

        cout << min(min(lengthCableInW, lengthCableInWReverse), min(lengthCableInD, lengthCableInDReverse)) << "\n";
    }

    return 0;
}