/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Big Integer Multiplication
 * Description: Multiplies two large integers represented as strings and
 *  returns the product as a string.
 * Time: O(n * m) where n and m are lengths of n1 and n2
 * Memory: O(n + m)
 * Status: Untested
 */

string mul(string n1, string n2)
{
  if (n1 == "0" || n2 == "0")
    return "0";
  string product(sz(n1) + sz(n2), 0);
  for (int i = sz(n1) - 1; i >= 0; i--)
  {
    for (int j = sz(n2) - 1; j >= 0; j--)
    {
      int n = (n1[i] - '0') * (n2[j] - '0') + product[i + j + 1];
      product[i + j + 1] = n % 10;
      product[i + j] += (n / 10);
    }
  }
  for (int i = 0; i < sz(product); i++)
  {
    product[i] += '0';
  }
  return product[0] == '0' ? product.substr(1) : product;
}
