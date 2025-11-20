/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Euler's Totient Function using factorization
 * Description: 
 * Time: O(sqrt(n))
 * Memory: O(sqrt(n)) for storing prime factors
 * Status: 
 */

vector<int> factorize(int n){
    vector<int> primes;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            primes.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    }

    if(n > 1)
        primes.push_back(n);
    return primes;
}

int phi(int n){
    vector<int> primes = factorize(n);

    for(int p : primes){
        n = n - n/p;
    }

    return n;
}

/// O(sqrt(n))
