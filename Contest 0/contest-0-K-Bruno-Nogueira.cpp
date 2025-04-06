#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<int> planks(n);
        for (int i = 0; i < n; i++)
            cin >> planks[i];

        int max_square_side = 0;
        for (int side = 1; side <= n; side++)
        {
            int count = 0;
            for (int plank_height : planks)
                if (plank_height >= side)
                    count++;

            if (count >= side)
                max_square_side = side;
            else
                break;
        }
        cout << max_square_side << "\n";
    }
    return 0;
}