// https://vjudge.net/contest/706892#problem/C

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int w;

    cin >> w;

    cout << ((w%2==0) && w != 2 ? "YES\n" : "NO\n");  

    return 0;
}
