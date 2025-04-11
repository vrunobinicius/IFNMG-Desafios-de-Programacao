// https://vjudge.net/contest/707365#problem/C

#include <bits/stdc++.h>

using namespace std;

int lcs(string x, string y, int i, int j, vector<vector<int>> &l)
{
    if (i == 0 || j == 0)
        return 0;

    if (l[i][j] != -1)
        return l[i][j];

    if (x[i - 1] == y[j - 1])
        l[i][j] = 1 + lcs(x, y, i - 1, j - 1, l);
    else
        l[i][j] = max(lcs(x, y, i - 1, j, l), lcs(x, y, i, j - 1, l));

    return l[i][j];
}

string constructing_string(string x, string y, int i, int j, vector<vector<int>> &l)
{
    if (i == 0 || j == 0)
        return "";
    else if (x[i - 1] == y[j - 1])
        return constructing_string(x, y, i - 1, j - 1, l) + x[i - 1];
    else if (l[i][j - 1] >= l[i - 1][j])
        return constructing_string(x, y, i, j - 1, l);
    else
        return constructing_string(x, y, i - 1, j, l);
}

int main(int argc, char const *argv[])
{
    string x, y;

    while (cin >> x >> y)
    {
        vector<vector<int>> l;
        l.assign(x.size() + 1, vector<int>(y.size() + 1, -1));
        int lengthX = x.size();
        int lengthY = y.size();
        lcs(x, y, lengthX, lengthY, l);
        string subsequence = constructing_string(x, y, lengthX, lengthY, l);
        next_permutation(subsequence.begin(), subsequence.end());
        cout << subsequence << "\n";
    }
    return 0;
}
