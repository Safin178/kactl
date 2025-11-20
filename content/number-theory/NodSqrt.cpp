/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Number of Divisors (NOD)
 * Description: Computes the number of divisors of a number n using its prime factorization.
 * Usage:
 *  ll divisors = NOD(100); returns 9
 * Time: O(sqrt(n))
 * Memory: O(1)
 * Status: Untested
 */

ll NOD(ll n) { 
  ll nod = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll p = 0;
      while (n % i == 0) {
        n /= i;
        p++;
      }
      nod *= (p + 1);
    }
  }
  if (n != 1)
    nod *= 2;
  return nod;
}