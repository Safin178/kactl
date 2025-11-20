/**
 * Author:
 * Date:
 * License: CC0
 * Source: Basic comparator utilities
 * Description:
 *  Two comparison helpers.
 *   Pair comparator: sorts by first element ascending; if equal, sorts by
 *    second element descending. Formally:
 *      $(A < B)$ iff  
 *      $(A.first < B.first)$ or  
 *      $(A.first = B.first \,\wedge\, A.second > B.second)$.
 *   Double comparator: compares two floating-point numbers with epsilon.
 *    Returns $0$ if $|a-b| \le \varepsilon$, otherwise $-1$ if $a<b$,
 *    and $1$ if $a>b$.
 * Usage:
 *  sort(v.begin(), v.end(), cmp);
 *  if (double comp(x, y) == 0) {  equal  }
 * Time: $O(1)$
 * Status: Tested
 */
#pragma once


bool cmp(pair<int, int> A, pair<int, int> B) // pair compare
{
    if (A.first == B.first)
        return (A.second > B.second);
    //! if A.second is Larger than A will come before B
    return (A.first < B.first);
    //! if A.first is smaller than A will come before B
}



int double_comp(ld a, ld b) //compare between 2 double
{
    if (fabs(a - b) <= eps)
        return 0;
    return a < b ? -1 : 1;
    //! dbl cmp return 0 when a==b, -1 if a<b ,, 1 if a>b
}
