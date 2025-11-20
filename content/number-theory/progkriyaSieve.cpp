/**
 * Author:
 * Date: 2025-11-20
 * License: CC0
 * Source: Standard Sieve of Eratosthenes (book version)
 * Description: Marks composite numbers up to n. Only odd numbers are processed
 * to improve speed. `marked[x] = true` means composite. `isPrime(x)` checks
 * primality in O(1). Complexity: Time O(n log log n), Space O(n).
 */


#define M 1000000 // 9e7
bool marked[M];
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    return marked[n] == false;
}
void sieve(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == false)
        { // i is a prime
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = true;
            }
        }
    }
}

// from book