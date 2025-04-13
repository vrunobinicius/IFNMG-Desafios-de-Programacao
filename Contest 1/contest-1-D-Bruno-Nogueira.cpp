// https://vjudge.net/contest/707365#problem/D

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    string decryptedPlaintext = "the quick brown fox jumps over the lazy dog", blankline;
    int t;
    cin >> t;
    cin.ignore();
    getline(cin, blankline);

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
        while (phraseIndex < setOfPhrases.size())
        {
            if (setOfPhrases[phraseIndex].size() == decryptedPlaintext.size())
            {
                vector<string> wordsInPhrase, wordsInDecrypted;
                istringstream phraseStream(setOfPhrases[phraseIndex]), decryptedStream(decryptedPlaintext);
                string wordInPhrase, wordInDecrypted;

                bool hasSameStructure = true;
                while (phraseStream >> wordInPhrase && decryptedStream >> wordInDecrypted)
                {
                    if (wordInPhrase.size() != wordInDecrypted.size())
                    {
                        hasSameStructure = false;
                        break;
                    }
                    wordsInPhrase.push_back(wordInPhrase);
                    wordsInDecrypted.push_back(wordInDecrypted);
                }

                if (!hasSameStructure)
                    break;

                map<char, char> tempMapCharacters;
                set<char> usedChars;
                bool isValidMapping = true;

                for (int i = 0; i < decryptedPlaintext.size(); i++)
                {
                    char currentCharPhrase = setOfPhrases[phraseIndex][i];
                    char currentCharDecrypted = decryptedPlaintext[i];

                    if (currentCharPhrase == ' ')
                        continue;

                    if (tempMapCharacters.count(currentCharPhrase))
                    {
                        if (tempMapCharacters[currentCharPhrase] != currentCharDecrypted)
                        {
                            isValidMapping = false;
                            break;
                        }
                    }
                    else
                    {
                        if (usedChars.count(currentCharDecrypted))
                        {
                            isValidMapping = false;
                            break;
                        }
                        tempMapCharacters[currentCharPhrase] = currentCharDecrypted;
                        usedChars.insert(currentCharDecrypted);
                    }
                }

                if (isValidMapping)
                {
                    mapCharacters = tempMapCharacters;
                    break;
                }
            }
            phraseIndex++;
        }

        if (phraseIndex == setOfPhrases.size())
        {
            cout << "No solution.\n";
        }
        else
        {
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
        if (t > 0)
            cout << "\n";
    }

    return 0;
}
