/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Memory-efficient bitwise Sieve of Eratosthenes
 * Description: Provides a memory-efficient implementation of the Sieve of Eratosthenes using bitwise operations. 
 *              Includes `sieve(n)` to generate all primes up to `n` and `isPrime(num)` to check primality of a number in O(1) time.
 * Time: O(n log log n) for sieve, O(1) for isPrime
 * Memory: O(n/64)
 */
#pragma once


#define M 100000000
int marked[M / 64 + 2];

#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))

void sieve(int n)
{
    for (int i = 3; i * i < n; i += 2)
    {
        if (!on(i))
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                mark(j);
            }
        }
    }
}

bool isPrime(int num)
{
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

// memory efficient er jonno ei sieve