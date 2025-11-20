/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Extended Euclidean Algorithm
 * Description: Computes gcd(a,b) and integers x,y such that $a \cdot x + b \cdot y = \gcd(a,b)$. 
 * Can be used to find modular inverses when $\gcd(a,b)=1$.Finds two integers $x$ and $y$, such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 * Time: $O(\log(\max(a,b)))$
 * Memory: $O(1)$
 * Status: Untested
 */

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}