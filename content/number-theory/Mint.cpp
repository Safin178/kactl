
/**
 * Author: Lukas Polacek
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */


const ll mod = 1e9+7; // change to something else
struct Mint {
  ll x;
  Mint() : x(0){}
  Mint(ll x_):x(x_ % mod){if (x < 0) x += mod;}
  Mint operator+(Mint b) { return Mint((x + b.x) % mod); }
  Mint operator-(Mint b) { return Mint((x - b.x + mod) % mod); }
  Mint operator*(Mint b) { return Mint((x * b.x) % mod); }
  Mint operator/(Mint b) { return *this * invert(b); }
  Mint invert(Mint a) {
    ll x, y, g = euclid(a.x, mod, x, y);
    assert(g == 1); return Mint((x + mod) % mod);
  }
  Mint power(ll e) {
    if (!e) return Mint(1);
    Mint r = this-> power (e / 2); r = r * r;
    return e&1 ? *this * r : r;
  }
};

vector<Mint> fact(1, 1);
 vector<Mint> inv_fact(1, 1);
 
 Mint C(int n, int k) {
  if (k < 0 || k > n) return 0;
  
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back( Mint(1) / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];

}