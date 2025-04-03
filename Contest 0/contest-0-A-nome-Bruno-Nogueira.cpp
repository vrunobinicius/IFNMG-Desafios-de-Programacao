// https://vjudge.net/contest/706892#problem/A

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    while (true)
    {
        cin >> number;
        if (number != 42)
            cout << number << "\n";
        else
            break;
    }
    return 0;
}
