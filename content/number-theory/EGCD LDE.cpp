/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Standard Extended Euclidean / Linear Diophantine Equation
 * Description: Finds any integer solution $(x_0, y_0)$ to the equation 
 *  $a \cdot x + b \cdot y = c$, if it exists. Also computes $g = \gcd(a, b)$. 
 *  All solutions can then be expressed as:
 *  $x = x_0 + k \cdot \frac{b}{g},\ y = y_0 - k \cdot \frac{a}{g}$ for integer $k$.
 * Usage:
 *  int x, y, g;
 *  if(find_any_solution(a, b, c, x, y, g)) {
 *       x, y is one solution, g = gcd(a,b)
 *  }
 * Time: O(log(max(a,b)))
 * Memory: O(1)
 * Status: Tested
 */
#pragma once

#include "EGCD.cpp"
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = euclid (abs(a), abs(b), x0, y0);
    if (c % g) return false;
    
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}