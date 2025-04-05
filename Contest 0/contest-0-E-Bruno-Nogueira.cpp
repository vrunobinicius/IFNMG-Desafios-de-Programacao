// https://vjudge.net/contest/706892#problem/E

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int uglyIndex = 1500;
    vector<int> uglyNumbers(uglyIndex);
    uglyNumbers[1] = 1;

    int factor2 = 1;
    int factor3 = 1;
    int factor5 = 1;
    int multipleOf2 = 2;
    int multipleOf3 = 3;
    int multipleOf5 = 5;

    for (int i = 2; i <= uglyIndex; i++)
    {
        uglyNumbers[i] = min(multipleOf2, multipleOf3);
        uglyNumbers[i] = min(uglyNumbers[i], multipleOf5);

        if (uglyNumbers[i] == multipleOf2)
        {
            factor2++;
            multipleOf2 = uglyNumbers[factor2] * 2;
        }
        if (uglyNumbers[i] == multipleOf3)
        {
            factor3++;
            multipleOf3 = uglyNumbers[factor3] * 3;
        }
        if (uglyNumbers[i] == multipleOf5)
        {
            factor5++;
            multipleOf5 = uglyNumbers[factor5] * 5;
        }
    }

    cout << "The 1500'th ugly number is " << uglyNumbers[uglyIndex] << "." << endl;

    return 0;
}