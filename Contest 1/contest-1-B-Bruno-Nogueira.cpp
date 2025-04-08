#include <bits/stdc++.h>
using namespace std;

int main()
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
            string letters;
            cin >> letters;
            transform(letters.begin(), letters.end(), letters.begin(), ::toupper);
            grid[i] = letters;
        }

        vector<pair<int, int>> locations;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string word;
            cin >> word;
            transform(word.begin(), word.end(), word.begin(), ::toupper);

            char start_char = word[0];
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (start_char == grid[j][l])
                    {
                        int row_initial_search = j;
                        int col_initial_search = l;
                        if ((m - l) >= word.size())
                        {
                            string substring = grid[j].substr(l, word.size());
                            if (substring == word)
                            {
                                locations.push_back(make_pair(j + 1, l + 1));
                            }
                        }
                        if ((m - l) >= word.size() && (j + l) <= word.size())
                        {
                            int size_word = word.size();
                            string substring = "";
                            for (int o = 0; o < word.size(); o++)
                            {
                                if (word[o] != grid[row_initial_search][col_initial_search])
                                    break;

                                substring += grid[row_initial_search][col_initial_search];
                                row_initial_search++;
                                col_initial_search++;
                            }

                            if (substring == word)
                            {
                                locations.push_back(make_pair(j + 1, l + 1));
                            }
                        }
                    }
                }
            }
        }

        for (int p = 0; p < locations.size(); p++)
        {
            cout << locations[p].first << " " << locations[p].second << "\n";
        }
        cout << "\n";
    }

    return 0;
}