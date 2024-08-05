/**
21：20-21：43
spent lot of time on
- while (g.find(cur + delta) != g.end())
- while (g[cur + delta])

 */


 class Solution {
 public:
     int longestConsecutive(vector<int>& nums) {
         unordered_map<int, bool> g;
         for (auto num : nums) {
             g[num] = true;
         }
         int resp = 0;
         while (!g.empty()) {
             int cur = g.begin()->first;
             cout<<"---"<<cur<<endl;
             int delta = 0;
             while (g.find(cur + delta) != g.end()) {
                 g.erase(cur + delta);
                 cout<<cur + delta<<endl;
                 delta++;
             }
             int ans = delta;
             delta = -1;
             while (g.find(cur + delta) != g.end()) {
                 g.erase(cur + delta);
                 cout<<cur + delta<<endl;
                 delta--;
             }
             resp = max(resp, ans - delta - 1);
         }
         return resp;
     }
 };