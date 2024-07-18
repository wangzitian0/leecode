/**
12:05 - 12:15

just f[i][j]=min(f[i-1][j-1], f[i-1][j])

 */
 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         vector<int>minAns(1, triangle[0][0]);
         for(int z=2;z<=triangle.size();z++) {
             vector<int>curAns(z, 0x3f3f3f3f);
             for (int j=0;j<z;j++) {
                 if (j>0) {
                     curAns[j] = min(curAns[j], minAns[j-1]);
                 }
                 if (j<z-1) {
                     curAns[j] = min(curAns[j], minAns[j]);
                 }
                 curAns[j] += triangle[z-1][j];
             }
             minAns = curAns;
         }
         int resp = 0x3f3f3f3f;
         for(int i=0;i<triangle.size();i++) {
             resp = min(resp, minAns[i]);
         }
         return resp;
     }
 };