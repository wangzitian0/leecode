/**
2 min


 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int g[128]={};
        for(auto ch : magazine) {
            g[ch]++;
        }

        for(auto ch : ransomNote) {
            if(g[ch]>0){
                g[ch]--;
            } else {
                return false;
            }
        }
        return true;
    }
};