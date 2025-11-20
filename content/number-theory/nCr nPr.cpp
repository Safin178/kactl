/**
 * Author:
 * Date: 2025-11-20
 * License: CC0
 * Source: Combinatorics (nCr / nPr) with factorial + inverse factorial precomputation
 * Description: Precomputes factorials and inverse factorials modulo MOD up to MAXN. 
 *              Provides fast computation of nCr and nPr in O(1) time after O(MAXN) preprocessing.
 * Usage:
 *   precompute();
 *   long long c = nCr(5, 2); // 10
 *   long long p = nPr(5, 2); // 20
 * Time: Precompute O(MAXN), Queries O(1)
 * Memory: O(MAXN)
 * Status:
 */
const int MAXN = 2000005;   // change as needed
const long long MOD = 1000000007;

vector<long long> fact(MAXN), inv_fact(MAXN);


long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    long long cur = fact[MAXN - 1];
    cur = modpow(cur, MOD - 2); // modular inverse of fact[MAXN-1]
    inv_fact[MAXN - 1] = cur;

    for (int i = MAXN - 2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[n - r] % MOD;
}
