/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Prime factorization
 * Description: Returns the prime factorization of a number `n` as a vector of primes, including multiplicities.
 * Usage:
 *  vector<long long> factors = factorise(60); // returns {2, 2, 3, 5}
 * Time: O(sqrt(n))
 * Memory: O(sqrt(n)) for storing factors
 * Status: 
 */
#pragma once
vector<ll> factorise(ll n){
    vector<ll> ret;
    if(n == 1)
        return ret;

    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
                ret.push_back(i);
            }
        }
    }

    if(n != 1)
        ret.push_back(n);

    return ret;
}


