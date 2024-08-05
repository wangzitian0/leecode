/**
20:55 - 21:05
just scan.
use a map to judge loop.

 */


 class Solution {
 public:
     bool isHappy(int n) {
         unordered_map<int, bool> g;
         while (true) {
             int s = 0, tmp;
             while (n > 0) {
                 tmp = n % 10;
                 s += (tmp * tmp);
                 n /= 10;
             }
             if (s == 1) {
                 return true;
             } else if (g[s]) {
                 return false;
             }
             g[s] = true;
             n = s;
         }
     }
 };