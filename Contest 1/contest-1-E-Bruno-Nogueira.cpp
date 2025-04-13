/// https://vjudge.net/contest/707365#problem/E

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = -1, m = -1;
    int runNumber = 1;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cin.ignore();

        vector<string> standardSolution;
        while (n--)
        {
            string temp;
            getline(cin, temp);
            standardSolution.push_back(temp);
        }

        cin >> m;
        cin.ignore();
        vector<string> teamOutput;
        while (m--)
        {
            string temp;
            getline(cin, temp);
            teamOutput.push_back(temp);
        }

        if (standardSolution.size() == teamOutput.size())
        {
            bool accepted = true;
            for (int i = 0; i < standardSolution.size(); i++)
            {
                if (standardSolution[i] != teamOutput[i])
                {
                    accepted = false;
                    break;
                }
            }
            if (accepted)
            {
                cout << "Run #" << runNumber++ << ": Accepted\n";
                continue;
            }
        }

        bool presentationError = true;
        string solutionNumeric, teamNumeric;
        for (const auto &line : standardSolution)
        {
            for (char c : line)
            {
                if (isdigit(c))
                    solutionNumeric.push_back(c);
            }
        }

        for (const auto &line : teamOutput)
        {
            for (char c : line)
            {
                if (isdigit(c))
                    teamNumeric.push_back(c);
            }
        }

        if (solutionNumeric != teamNumeric)
            presentationError = false;

        if (presentationError)
            cout << "Run #" << runNumber++ << ": Presentation Error\n";
        else
            cout << "Run #" << runNumber++ << ": Wrong Answer\n";
    }

    return 0;
}
