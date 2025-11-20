/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Euler's Totient Function (ETF) Sieve
 * Description: Computes Euler's Totient Function (phi) for all numbers up to N using a sieve. 
 *              phi(n) counts the integers from 1 to n that are coprime with n.
 * Usage:
 *  etf(); // fills the phi array
 *  int val = phi[97]; // retrieves phi(97)
 * Time: O(N log log N)
 * Memory: O(N)
 * Status: 
 */

/* Upobir 
int phi[100000+5];
bool mark[100000+5];

void sieve(){
    for(int i = 1; i<=100000; i++)
        phi[i] = i;

    for(int i = 2; i<=100000; i++){
        if(mark[i])
            continue;
        phi[i] = i-1;    // i is prime => phi(i) = i-1
        for(int j = i+i; j<=100000; j+=i){
            mark[j] = true;

            phi[j] = phi[j] - phi[j]/i;
        }
    }
}
*/

const int N = 1e5 + 9;
int phi[N];
void etf() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) 
      {
        phi[j] -= phi[j] / i;
      }
    }
  }
}