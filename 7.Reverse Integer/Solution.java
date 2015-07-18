public class Solution {
    public int reverse(int x) {
        StringBuffer xs=new StringBuffer(String.valueOf(x));
        xs=xs.reverse();
        int len=xs.length();
        String ans=xs.toString();
        if(ans.charAt(len-1)=='-')
            ans="-" + (ans.substring(0,len-1));
        try{
        return Integer.parseInt(ans);
        }
        catch (Exception e)
        {
            return 0;
        }
    }
}
