#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    int i, j;
    while (cin >> i >> j)
    {
        int cl;
        int minimum = min(i, j);
        int maximum = max(i, j);
        int maxCL = 0;
        for (int k = minimum; k <= maximum; k++)
        {
            int num = k;
            cl = 1;
            while (num != 1)
            {
                if (num % 2 == 0)
                    num /= 2;
                else
                    num = 3 * num + 1;
                cl++;
            }
            maxCL = max(maxCL, cl);
        }
        cout << i << " " << j << " " << maxCL << "\n";
    }

    return 0;
}
