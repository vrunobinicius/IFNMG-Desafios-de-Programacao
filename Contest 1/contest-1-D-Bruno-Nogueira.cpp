#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    string decryptedPlaintext = "the quick brown fox jumps over the lazy dog";
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string phrase;
        vector<string> setOfPhrases;
        map<char, char> mapCharacters;
        while (getline(cin, phrase))
        {
            if (phrase.empty())
                break;
            setOfPhrases.push_back(phrase);
        }

        int phraseIndex = 0;
        while (phraseIndex < setOfPhrases.size() && setOfPhrases[phraseIndex].size() != decryptedPlaintext.size())
            phraseIndex++;

        if (phraseIndex == setOfPhrases.size())
        {
            cout << "No solution.\n";
        }
        else
        {

            for (int i = 0; i < decryptedPlaintext.size(); i++)
            {
                if (setOfPhrases[phraseIndex][i] == ' ')
                    continue;
                mapCharacters[setOfPhrases[phraseIndex][i]] = decryptedPlaintext[i];
            }

            for (int i = 0; i < setOfPhrases.size(); i++)
            {
                for (int j = 0; j < setOfPhrases[i].size(); j++)
                {
                    if (setOfPhrases[i][j] == ' ')
                    {
                        cout << " ";
                        continue;
                    }
                    cout << mapCharacters[setOfPhrases[i][j]];
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
