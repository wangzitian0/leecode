
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=val)
                nums[pos++]=nums[i];
        nums.erase(nums.begin()+pos,nums.end());
        return nums.size();
    }
};
int main()
{
    Solution x= Solution();
}
