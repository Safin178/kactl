/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Sum of Divisors function (SOD)
 * Description: Computes the sum of divisors of a number n using its prime factorization.
 *  If $n = p1^a1 * p2^a2 * ... * pk^ak, then SOD(n) = ((p1^(a1+1)-1)/(p1-1)) * ... * ((pk^(ak+1)-1)/(pk-1))$
 * Usage:
 *  ll sum = SOD(100);  returns sum of divisors of 100
 * Time: O(sqrt(n))
 * Memory: O(1)
 * Status: Untested
 */

ll SOD(ll n) {
  ll sod = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll cur = i;
      while (n % i == 0) {
        cur *= i, n /= i;
      }
      cur = (cur - 1) / (i - 1);
      sod *= cur;
    }
  }
  if (n != 1) sod *= (n + 1);
  return sod;
}


