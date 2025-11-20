/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Big Integer Divisibility Check
 * Description: Checks if a large number represented as a string is divisible
 *  by an integer b. Returns the remainder; if remainder is 0, the number is divisible.
 * Time: O(n) where n is the length of the string
 * Memory: O(1)
 * Status: Untested
 */

int is_div(string a, int b)
{
    int j = 0;
    if (a[0] == '-')
        j = 1;
    if (b < 0)
        b = abs(b);
    ll rim = 0;
    for (; j < sz(a); j++)
    {
        rim = rim * 10 + (a[j] - '0');
        rim %= b;
    }
    return rim; // if rim=0 divisible else not
}
