
/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Big Integer Addition
 * Description: Adds two large integers represented as strings. Assumes both
 *  strings are of the same length. Returns the sum as a string.
 * Time: O(n) where n is the length of the strings
 * Memory: O(n)
 * Status: Untested
 */

string add(string n1, string n2)
{
    string res = "";
    int sum, carry = 0;
    for (int i = sz(n1) - 1; i >= 0; i--)
    {
        sum = n1[i] - '0' + n2[i] - '0' + carry;
        if (sum > 9)
        {
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        else
        {
            res = to_string(sum) + res;
            carry = 0;
        }
    }
    if (carry)
        res = to_string(carry) + res;
    return res;
}
