/*
7：31- 7:40
very ugly impl..
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, ans = 0;
        for (auto ch : s) {
            if(ch==' ') {
                if(len>0)ans = len;
                len = 0;
            }
            else len++;
        }
        if(len>0)ans = len;
        return ans;
    }
};