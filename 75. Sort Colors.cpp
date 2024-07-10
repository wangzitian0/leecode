/*
9:01 - 9:06
f**k
Wa x 1.

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={};
        for(int i=0;i<nums.size();i++) {
            count[nums[i]]++;
        }
        int pos=0;
        for(int j=0;j<3;j++) {
            for(int i=0;i<count[j];i++){
                nums[pos+i]=j;
            }
            pos += count[j];
        }
    }
};