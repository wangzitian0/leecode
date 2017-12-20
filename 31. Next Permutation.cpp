/*
1. C++ 本身就有 next_permutation();这个函数，可以直接搞。
2. 可以康托展开，不过可重排列略麻烦。
3. 找规律，观察两个数列，1，4，2，3 和 1，4，3，2
结论是从右至左找到连续递减的序列[i,n], swap(a[i-1],max(a[i]...a[n])), reverse(i, n);


1.wa  [2,3,1]
2.re  [2,3,0,2,4,1], 降序不能 直接用 upper_bound

*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), z = n-1;
        while(z>0&&nums[z-1]>=nums[z])
            z--;
        if(z){
            for(int i=n-1;i>=z;i--)
                if(nums[i]>nums[z-1]) {
                    swap(nums[z-1], nums[i]);
                    break;
                }
        }
        reverse(nums.begin() + z,nums.end());
    }
};