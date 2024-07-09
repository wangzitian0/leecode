/*
10:35-10:40
binary search.

*/class Solution {
  public:
      int mySqrt(int x) {
          int low = 0, up = 0x7FFFFFF;
          while(low+1<up){
              int mid = (low+up)/2;
              // mid*mid==x -> mid==x/mid
              if (mid<=x/mid)
                  low = mid;
              else up = mid;
          }
          return low;
      }
  };