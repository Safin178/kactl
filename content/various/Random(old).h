/**
 * Author: 
 * Date:
 * License: 
 * Source:
 * Description: gen\_random(l, r);  random number dei l to r er modde, shuffle() vector ke randomly suffle kore
 * Time: 
 * Status: untested
 */

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll gen_random(ll l, ll r){
return uniform_int_distribution<ll>(l, r)(rng);
}

shuffle(all(v), rng); 