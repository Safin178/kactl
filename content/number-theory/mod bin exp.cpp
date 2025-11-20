/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Binary Exponentiation and Modular Arithmetic
 * Description: this mod is bit slow, use $ans -= ans / mod * mod$ 
 * Time: O(log n) for bin exp and modInv, O(1) for other operations
 * Memory: O(1)
 * Status: 
 */
#pragma once

ll bin_exp(ll a, ll n) //O(log(n))
{
  // a ^ n
  ll r = 1LL;
  int m = 1000000007;
  // Delete % m if we don't need it
  while (n) {
    if (n & 1) r = (r * a) % m, n--;
    else a = (a * a) % m, n /= 2LL;
  }
  return r;
}

const int mod2 = 1e9 + 7; // faster if const
inline ll MOD(ll a){ return (a % mod2 + mod2) % mod2; }
inline ll modAdd(ll a, ll b) { return MOD(MOD(a) + MOD(b)); }
inline ll modSub(ll a, ll b) { return MOD(MOD(a) - MOD(b)); }
inline ll modMul(ll a, ll b) { return MOD(MOD(a) * MOD(b)); }
inline ll modInv(ll a) { return bin_exp(a, mod2 - 2); } 


