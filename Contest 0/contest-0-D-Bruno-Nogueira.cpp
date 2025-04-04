// https://vjudge.net/contest/706892#problem/D

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000000

int main(int argc, char const *argv[])
{
    vector<long long> primes;
    long long lim = sqrt(MAXN);
    vector<bool> mark(lim + 1, false);
    for (long long i = 2; i <= lim; i++)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        long long n, m;
        cin >> n >> m;

        vector<bool> isPrime(m - n + 1, true);
        for (long long i : primes)
        {
            for (long long j = max(i * i, (n + i - 1) / i * i); j <= m; j += i)
                isPrime[j - n] = false;
        }

        if (n == 1)
            isPrime[0] = false;

        for (int i = 0; i < isPrime.size(); i++)
        {
            if (isPrime[i])
            {
                cout << i + n << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
