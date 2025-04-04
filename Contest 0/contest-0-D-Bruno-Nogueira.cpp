// https://vjudge.net/contest/706892#problem/D

#include <bits/stdc++.h>

using namespace std;

vector<bool> findPrimes(long long L, long long R)
{
    vector<long long> primes;
    long long sqrtR = ceil(sqrt(R));
    vector<bool> mark(sqrtR + 1, false);
    vector<bool> isPrime(R - L + 1, true);
    for (long long i = L; i <= sqrtR; i++)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (int j = i * i; j <= sqrtR; j += i)
                mark[j] = true;
        }

        for (long long i : primes)
        {
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j] = false;

            if (L == 1)
            {
                isPrime[0] = isPrime[1] = false;
            }
        }
    }

    return isPrime;
}

int main(int argc, char const *argv[])
{

    auto isPrime = findPrimes(3, 5);

    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}
