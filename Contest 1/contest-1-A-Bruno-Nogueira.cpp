// https://vjudge.net/contest/707365#problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> keyboard_rows = {"`1234567890-=", "QWERTYUIOP[]\\",
                                    "ASDFGHJKL;'", "ZXCVBNM,./"};
    map<char, char> keyboard_map = {};

    for (int i = 0; i < keyboard_rows.size(); i++)
    {
        for (int j = 1; j < keyboard_rows[i].size(); j++)
        {
            keyboard_map[keyboard_rows[i][j]] = keyboard_rows[i][j - 1];
        }
    }

    string phrase;
    while (getline(cin, phrase))
    {
        for (int i = 0; i < phrase.size(); i++)
        {
            if (phrase[i] == ' ')
            {
                cout << " ";
            }
            else
            {
                cout << keyboard_map[phrase[i]];
            }
        }
        cout << "\n";
    }

    return 0;
}