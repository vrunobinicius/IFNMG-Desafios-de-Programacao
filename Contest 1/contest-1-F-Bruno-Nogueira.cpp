// https://vjudge.net/contest/707365#problem/F

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string blankline;
    int t;
    cin >> t;
    cin.ignore();
    getline(cin, blankline);

    while (t--)
    {
        string fragment;
        vector<string> fragments;
        while (getline(cin, fragment))
        {
            if (fragment.empty())
                break;
            fragments.push_back(fragment);
        }

        unordered_map<string, int> ocorrences;
        for (auto fragmentA : fragments)
            for (auto fragmentB : fragments)
                ocorrences[fragmentA + fragmentB]++;

        int maximun = 0;
        string result;
        for (auto ocorrence : ocorrences)
        {
            if (ocorrence.second > maximun)
            {
                maximun = ocorrence.second;
                result = ocorrence.first;
            }
        }

        cout << result << "\n";
        if (t > 0)
            cout << "\n";
    }

    return 0;
}
