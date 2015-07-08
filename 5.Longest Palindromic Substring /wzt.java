public class Solution {
    public String longestPalindrome(String s) {
        int len = s.length(),ans=0,jians=0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;i-j>=0&&i+j<len;j++)
                if(s.charAt(i-j)!=s.charAt(i+j))
                    break;
                else if(ans<j*2+1)
                {
                    ans=j*2+1;
                    jians=i;
                }
            for(int j=0;i-j>=0&&i+1+j<len;j++)
                if(s.charAt(i-j)!=s.charAt(i+1+j))
                    break;
                else if(ans<j*2+2)
                {
                    ans=j*2+2;
                    jians=i;
                }
        }
        StringBuilder strans = new StringBuilder("");
        for(int j=jians-(ans-1)/2;j<jians-(ans-1)/2+ans;j++)
            strans.append(s.charAt(j));
        return strans.toString();
    }
}
