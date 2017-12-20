/*
给你一个无序数组，求第一个没出现的正整数。算法必须是 O(n)，常数空间复杂度

常数空间复杂度很多方法都不行了。
然后我们需要一种方法来表示0...n 这样一种状态
首先<=0的数字扔到，没有意义。

第一感觉是用类似亦或的算法，按位置依次去统计，O(32)，虽然是 O(1)，常数巨大无比，还不如 log……

然后，就没有然后了，想了半天不会……
一看答案，出题人是傻逼么…… 可以改动原始数组，那和新申请有什么区别。。。。。。
预计前50题就这一个怪怪的吧。。。


TLE: 数据[1,1]，不会停止循环。。。

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            while(nums[i]>0 && nums[i]<=n && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        return n+1;
    }
};