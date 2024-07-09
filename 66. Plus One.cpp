/*
10:19-10:23
big number add
easy.

*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int mod = 1;
        for(int i=0;i<digits.size();i++){
            mod += digits[i];
            digits[i] = mod%10;
            mod = mod / 10;
        }
        if (mod>0){
            digits.push_back(mod);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};