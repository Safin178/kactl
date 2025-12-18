/**
 * Author: 
 * Date: 
 * License: CC0
 * Source: 
 * Description:
 */



#include <ext/pb_ds/assoc_container.hpp> /** keep-include */
#include <ext/pb_ds/tree_policy.hpp> /** keep-include */
using namespace std;
using namespace __gnu_pbds;
template < typename PB >
  using pbds = tree < PB, null_type, less < PB > , rb_tree_tag, tree_order_statistics_node_update > ;
// or

typedef tree<PB,null_type,less<PB>,rb_tree_tag,tree_order_statistics_node_update> pbds;

example =>
 * - less<data_type> --> Increasingly sorted set
 * - less_equal<data_type> --> Increasingly  multiset
 * - greater<data_type> --> Decreasingly sorted set
 * - greated_equal<data_type> --> Decreasingly sorted multiset
 

 order_of_key(k): Number of items strictly smaller than k
 name.order_of_key(100);
find_by_order(k): returns an iterator , K-th element in a set ( Counting from zero)
 *name.find_by_order(5); 

  Path of the File that needs to be renamed in case of error in including PBDS header files: C\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++\ext\pb_ds\detail\resize_policy
 // rename a file which has .hpp0000...lots of numbers to .hpp
 