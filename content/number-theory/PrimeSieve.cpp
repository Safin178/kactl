/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Sieve of Eratosthenes
 * Description: Generates all prime numbers up to n using a simple
 *  sieve. Marks non-primes in a boolean array and stores primes in a vector.
 * Usage:
 *  sieve(1000000);
 *  for (int p : primes) cout << p << ' ';
 * Time: O(n log log n)
 * Memory: O(M)
 * Status: Untested
 */

const int M = 1000000; // max : 9e7
vector<int>primes;
bool marked[M];
bool isprime(int n) {
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  return marked[n] == false;
}
void sieve(ll n) { // O(n log log n)
  for (ll i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) // i is a prime
    {
      for (ll j = i * i; j <= n; j += i) {
        marked[j] = true;
      }
    }
  }
     for (int i = 0; i < n; i++) { 
    if (isprime(i)) {
        primes.push_back(i);
    }
  }
}
