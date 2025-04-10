// https://vjudge.net/contest/707365#problem/B

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
            cin >> grid[i];
            transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::toupper);
        }

        int k;
        cin >> k;

        vector<pair<int, int>> locations;

        for (int i = 0; i < k; i++)
        {
            string word;
            cin >> word;
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            bool found = false;

            for (int j = 0; j < n && !found; j++)
            {
                for (int l = 0; l < m && !found; l++)
                {
                    if (grid[j][l] != word[0])
                        continue;

                    // Busca horizontal (da esquerda para a direita)
                    if ((m - l) >= (int)word.size())
                    {
                        string substring = grid[j].substr(l, word.size());
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j + 1, l + 1));
                            found = true;
                            break;
                        }
                    }

                    // Busca horizontal reversa (da direita para a esquerda)
                    if (l + 1 >= (int)word.size())
                    {
                        string substring = grid[j].substr(l - word.size() + 1, word.size());
                        reverse(substring.begin(), substring.end());
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j + 1, l - word.size() + 2));
                            found = true;
                            break;
                        }
                    }

                    // Busca vertical superior (de baixo para cima)
                    if (j + 1 >= (int)word.size())
                    {
                        int row = j;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][l] != word[o])
                                break;
                            substring.push_back(grid[row][l]);
                            row--;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j - word.size() + 2, l + 1));
                            found = true;
                            break;
                        }
                    }

                    // Busca vertical inferior (de cima para baixo)
                    if ((n - j) >= (int)word.size())
                    {
                        int row = j;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][l] != word[o])
                                break;
                            substring.push_back(grid[row][l]);
                            row++;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j + 1, l + 1));
                            found = true;
                            break;
                        }
                    }

                    // Busca diagonal inferior à direita
                    if ((n - j) >= (int)word.size() && (m - l) >= (int)word.size())
                    {
                        int row = j, col = l;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][col] != word[o])
                                break;
                            substring.push_back(grid[row][col]);
                            row++;
                            col++;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j + 1, l + 1));
                            found = true;
                            break;
                        }
                    }

                    // Busca diagonal superior à direita
                    if (j >= (int)word.size() - 1 && (m - l) >= (int)word.size())
                    {
                        int row = j, col = l;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][col] != word[o])
                                break;
                            substring.push_back(grid[row][col]);
                            row--;
                            col++;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j - word.size() + 2, l + 1));
                            found = true;
                            break;
                        }
                    }

                    // Busca diagonal superior à esquerda
                    if (j >= (int)word.size() - 1 && l >= (int)word.size() - 1)
                    {
                        int row = j, col = l;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][col] != word[o])
                                break;
                            substring.push_back(grid[row][col]);
                            row--;
                            col--;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j - word.size() + 2, l - word.size() + 2));
                            found = true;
                            break;
                        }
                    }

                    // Busca diagonal inferior à esquerda
                    if ((n - j) >= (int)word.size() && l + 1 >= (int)word.size())
                    {
                        int row = j, col = l;
                        string substring = "";
                        for (int o = 0; o < (int)word.size(); o++)
                        {
                            if (grid[row][col] != word[o])
                                break;
                            substring.push_back(grid[row][col]);
                            row++;
                            col--;
                        }
                        if (substring == word)
                        {
                            locations.push_back(make_pair(j + 1, l - word.size() + 2));
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        for (int p = 0; p < (int)locations.size(); p++)
            cout << locations[p].first << " " << locations[p].second << "\n";
    }

    return 0;
}
