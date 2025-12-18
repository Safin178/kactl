/**
 * Author:
 * Date:
 * License:
 * Source: Mobius inversion
 * Description:
 *
 * Count x in [L, R] with gcd(x, m) = k:
 *   k divides m
 *   sum over d dividing (m / k):
 *     mu[d] * ( R / (k*d) - (L-1) / (k*d) )
 *
 * Count pairs (i, j) with gcd(i, j) = k:
 *   i in [l1, r1], j in [l2, r2]
 *   sum over d up to min(r1/k, r2/k):
 *     mu[d] *
 *     ( r1 / (k*d) - (l1-1) / (k*d) ) *
 *     ( r2 / (k*d) - (l2-1) / (k*d) )
 *
 * Count pairs in array a with gcd(a[i], a[j]) = k:
 *   cnt[x] = number of elements divisible by x
 *   sum over d up to max(a)/k:
 *     mu[d] * cnt[d*k] * cnt[d*k]
 *
 * All divisions are integer floor.
 */



const int N = 5e5 + 9;
int mob[N];
void mobius() {
  mob[1] = 1;
  for (int i = 2; i < N; i++){
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}
