// https://vjudge.net/contest/707365#problem/C

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string x, y;
    while (getline(cin, x))
    {
        getline(cin, y);
        vector<int> frequenceA(26, 0);
        vector<int> frequenceB(26, 0);
        string result = "";

        for (auto character : x)
            frequenceA[character - 'a']++;

        for (auto character : y)
            frequenceB[character - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            int minimun = min(frequenceA[i], frequenceB[i]);
            result.append(minimun, 'a' + i);
        }

        cout << result << "\n";
    }
    return 0;
}
