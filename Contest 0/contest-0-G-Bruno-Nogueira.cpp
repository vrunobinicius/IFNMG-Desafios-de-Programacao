// https://vjudge.net/contest/706892#problem/G

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string word;
        cin >> word;

        int endOfWord = word.size() - 1;

        if (word.size() > 10)
            cout << word[0] << word.size() - 2 << word[endOfWord] << "\n";
        else
            cout << word << "\n";
    }

    return 0;
}