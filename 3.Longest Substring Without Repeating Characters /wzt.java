public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int slen = s.length(),ans=0,last=0;
        int[] cnt = new int[256];
        for(int i=0;i<slen;i++)
        {
            while(cnt[s.charAt(i)]!=0)
            {
                cnt[s.charAt(last)]--;
                last++;
            }
            cnt[s.charAt(i)]++;
            ans=Math.max(ans,i-last+1);
        }
        return ans;
    }
}
