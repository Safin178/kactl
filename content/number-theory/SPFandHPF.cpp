/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Sieve for smallest prime factor (SPF)
 * Description: Computes smallest prime factor (spf) for all numbers up to MAXN
 *  using a sieve. Allows quick factorization of any number <= MAXN.
 * Usage:
 *  sieve(); // precompute spf
 *  auto factors = getFactorization(100); // returns prime factors of 100
 * Time: O(MAXN log log MAXN) for sieve, O(log n) per factorization
 * Memory: O(MAXN)
 * Status: Untested
 */

int const MAXN = (int)1e7 + 5;
vector<int> spf(MAXN + 1, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getFactorization(int x) // with spf
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}