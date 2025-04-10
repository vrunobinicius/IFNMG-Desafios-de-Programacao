#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int main(int argc, char const *argv[])
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
            transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::toupper);
        }

        int k;
        cin >> k;
        while (k--)
        {
            string word;
            cin >> word;
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            bool found = false;

            for (int i = 0; i < n && !found; i++)
            {
                for (int j = 0; j < m && !found; j++)
                {
                    for (auto direction : directions)
                    {
                        int row = i, column = j, current = 0;
                        while (current < word.size())
                        {
                            if (row < 0 || column < 0 || row >= n || column >= m || grid[row][column] != word[current])
                                break;

                            if (++current == word.size())
                                found = true;

                            row += direction.first;
                            column += direction.second;
                        }
                        if (found)
                        {
                            cout << i + 1 << " " << j + 1 << "\n";
                            break;
                        }
                    }
                }
            }
        }
        if (t)
            cout << "\n";
    }

    return 0;
}
