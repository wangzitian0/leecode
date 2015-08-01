
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        int pos=1;
        for(int i=1;i<(int)nums.size();i++)
            if(nums[i]!=nums[i-1])
                nums[pos++]=nums[i];
        nums.erase(nums.begin()+pos,nums.end());
        return nums.size();
    }
};
int main()
{
    Solution x= Solution();
}
