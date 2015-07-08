public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans= new int[2];
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        int len = nums.length;
        for(int i=0;i<len;i++)
        {
            if(mp.get(target-nums[i])!=null)
            {
                ans[0]=mp.get(target-nums[i]);
                ans[1]=i+1;
                break;
            }
            mp.put(nums[i],i+1);
        }
        return ans;
    }
}
