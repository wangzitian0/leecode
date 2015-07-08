public class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1)return s;
        StringBuilder ans = new StringBuilder("");
        int len = s.length();
        
        for(int j=0;j<=len/(numRows*2-2);j++)
            if(j*(numRows*2-2)<len)ans.append(s.charAt(j*(numRows*2-2)));
        for(int i=1;i<numRows-1;i++)
        {
            for(int j=0;j<=len/(numRows*2-2);j++)
            {
                if(j*(numRows*2-2)+i<len)ans.append(s.charAt(j*(numRows*2-2)+i));
                if((1+j)*(numRows*2-2)-i<len)ans.append(s.charAt((1+j)*(numRows*2-2)-i));
            }
        }
        for(int j=0;j<=len/(numRows*2-2);j++)
            if(j*(numRows*2-2)+numRows-1<len)ans.append(s.charAt(j*(numRows*2-2)+numRows-1));
        return ans.toString();
    }
}
