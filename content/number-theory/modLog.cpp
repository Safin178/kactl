/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: 
 * Description: $Returns the smallest x > 0 such that a^x = b (mod m) $ 
 *  or -1 if no such x exists. This function can also be used to compute 
 *  the order of a modulo m by calling modLog(a,1,m). 
 * 
 * Usage:
 *  ll x = modLog(2, 8, 13);  finds x such that $2^x \equiv 8 \pmod{13}$ (mod 13)
 * Time: O(sqrt(m))
 * Memory: O(sqrt(m)) for the map
 * Status: Untested
 */

#define rep(i,x,n) for(int i=x; i<n; i++)

ll modLog(ll a, ll b, ll m)
{
    ll n = (ll)sqrt(m) + 1, e = 1, f = 1, j = 1;
    unordered_map<ll, ll> A;
    while (j <= n && (e = f = e * a % m) != b % m)
        A[e * b % m] = j++;
    if (e == b % m)
        return j;
    if (__gcd(m, e) == __gcd(m, b))
        rep(i, 2, n + 2) if (A.count(e = e * f % m))
                return n * i - A[e];
    return -1;
}